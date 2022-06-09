//PART4：其他数据结构：链表、队列、并查集、图	etc.

//1051：栈
/*
#include<iostream>
#include<vector>
using namespace std;
int M, N, K;
int seq[1005][1005];
vector<int>s;
bool func(int index)
{
	s.clear();
	int i = 1, j = 0;
	while (i <= N)
	{
		s.push_back(i);
		i++;
		if (s.size() > M)return false;
		while (s.back() == seq[index][j])
		{
			s.pop_back();
			j++;
			if (s.empty())break;
		}
	}
	if (s.empty())return true;
	else return false;
}
int main()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
		for (int j = 0; j < N; j++)
			cin >> seq[i][j];
	for (int i = 0; i < K; i++)
	{
		if (func(i))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}*/

//1098: 堆
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int seq1[105], seq2[105];
vector<int>nxt;
bool insertsort()
{
	vector<int>sorted;
	for (int i = 0; i < N; i++)
	{
		sorted.push_back(seq1[i]);
		sort(sorted.begin(), sorted.end());
		int j = 0, flag = 1;
		while (j < N)
		{
			if (j < sorted.size())
			{
				if (sorted[j] != seq2[j])
				{
					flag = 0;
					break;
				}
			}
			else
			{
				if (seq1[j] != seq2[j])
				{
					flag = 0;
					break;
				}
			}
			j++;
		}
		if (flag)
		{
			j = 0;
			while (sorted.back() < seq1[i + 1])
			{
				i++;
				sorted.push_back(seq1[i]);
				sort(sorted.begin(), sorted.end());

			}
			i++;
			sorted.push_back(seq1[i]);
			sort(sorted.begin(), sorted.end());
			while (j < N)
			{
				if (j < sorted.size())
					nxt.push_back(sorted[j]);
				else
					nxt.push_back(seq1[j]);
				j++;
			}
			return true;
		}
	}
	return false;
}
void heapfunc(int *seq, int y)
{
	for (int j = (y - 1) / 2; j >= 0; j--)
	{
		int k = j, l = 2 * k + 1;
		while (l <= y)
		{
			if (l + 1 <= y && seq[l + 1] > seq[l])l++;
			if (seq[k] > seq[l])break;
			swap(seq[k], seq[l]);
			k = l;
			l = 2 * l + 1;
		}
	}
}
int heapcheck(int* seq)
{
	for (int j = 0; j < N; j++)
	{
		if (seq[j] != seq2[j])
			return 0;
	}
	return true;
}
bool heapsort()
{
	int seq[105], temp;
	for (int i = 0; i < N; i++)
		seq[i] = seq1[i];
	for (int i = 0; i < N; i++)
	{
		heapfunc(seq, N - 1 - i);
		if (heapcheck(seq))
		{
			swap(seq[0], seq[N - 1 - i]);
			heapfunc(seq, N - 2 - i);
			for (int j = 0; j < N; j++)
				nxt.push_back(seq[j]);
			return true;
		}
		swap(seq[0], seq[N - 1 - i]);
	}
	return false;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> seq1[i];
	for (int i = 0; i < N; i++)
		cin >> seq2[i];
	if (insertsort())
	{
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < N; i++)
			if (i != N - 1)
				cout << nxt[i] << " ";
			else cout << nxt[i];
		return 0;
	}
	nxt.clear();
	if (heapsort())
	{
		cout << "Heap Sort" << endl;
		for (int i = 0; i < N; i++)
			if (i != N - 1)
				cout << nxt[i] << " ";
			else cout << nxt[i];
		return 0;
	}
}*/

//1107: 并查集
/*
#include<iostream>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N, num;
int hobby[1005][1005];
vector<map<int, int>>closure_hobby;
vector<int>closure_num;
int erased[1005];
bool cmp(int a, int b)
{
	return a > b;
}
void merge(map<int, int>& a, map<int, int>& b)
{
	for (auto p = b.begin(); p != b.end(); p++)
	{
		a[p->first] = p->second;
	}
}
int main()
{
	cin >> N;
	string str;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		str = str.substr(0, str.length() - 1);
		for (int j = 0; j < atoi(str.c_str()); j++)
		{
			cin >> hobby[i][j];
		}
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	int flag = 0;
	//	for (int j = 0; j < closure_hobby.size(); j++)
	//	{
	//		for (int k = 0; hobby[i][k] != 0; k++)
	//		{
	//			if (closure_hobby[j].find(hobby[i][k]) != closure_hobby[j].end())
	//			{
	//				flag = 1;
	//				for (int m = 0; hobby[i][m] != 0; m++)
	//					closure_hobby[j][hobby[i][m]] = 1;
	//				break;
	//			}
	//		}
	//		if (flag)
	//		{
	//			closure_num[j]++;
	//			break;
	//		}
	//	}
	//	if (!flag)
	//	{
	//		closure_hobby.push_back(*new map<int, int>());
	//		for (int k = 0; hobby[i][k] != 0; k++)
	//		{
	//			closure_hobby.back()[hobby[i][k]] = 1;
	//		}
	//		closure_num.push_back(1);
	//	}
	//}
	for (int i = 1; i <= N; i++)
	{
		closure_hobby.push_back(*new map<int, int>);
		for (int j = 0; hobby[i][j] != 0; j++)
			closure_hobby.back()[hobby[i][j]] = 1;
		closure_num.push_back(1);
	}
	//for (int i = 0; i < closure_hobby.size(); i++)
	//{
	//	for (auto p = closure_hobby[i].begin(); p != closure_hobby[i].end(); p++)
	//	{
	//		cout << p->first << " ";
	//	}
	//	cout << endl;
	//}
	int num = closure_hobby.size();
	for (int i = 0; i < closure_hobby.size(); i++)
	{
		if (!erased[i])
		{
			for (int j = 0; j < closure_hobby.size(); j++)
			{
				if (!erased[j] && i != j)
				{
					for (auto p = closure_hobby[j].begin(); p != closure_hobby[j].end(); p++)
					{
						if (closure_hobby[i].find(p->first) != closure_hobby[i].end())
						{
							merge(closure_hobby[i], closure_hobby[j]);
							closure_num[i] += closure_num[j];
							erased[j] = 1;
							num--;
							j = -1;
							break;
						}
					}
				}
			}
		}
	}
	cout << num << endl;
	int flag = 0;
	sort(closure_num.begin(), closure_num.end(), cmp);
	for (int i = 0; i < closure_num.size(); i++)
		if (!erased[i])
			if (!flag)
			{
				cout << closure_num[i];
				flag = 1;
			}
			else
				cout << " " << closure_num[i];
}*/ // 问题代码

//debug失败，更换思路
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N;
int father[1005], hobby[1005];
vector<int>Count;
bool cmp(int a, int b) { return a > b; }
int findFather(int x)
{
	int a = x;
	while (a != father[a])
		a = father[a];
	int b = x, c;
	while (b != father[b])
	{
		c = b;
		b = father[b];
		father[c] = a;
	}
	return a;
}
void Union(int a, int b)
{
	int fa = findFather(a);
	int fb = findFather(b);
	if (fa != fb)
	{
		father[fa] = fb;
		findFather(a);
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < 1005; i++)
		father[i] = i;
	for (int i = 1; i <= N; i++)
	{
		int t;
		string str;
		cin >> str;
		str = str.substr(0, str.length() - 1);
		for (int j = 0; j < atoi(str.c_str()); j++)
		{
			cin >> t;
			if (hobby[t] == 0)hobby[t] = i;
			Union(i, hobby[t]);
		}
	}
	Count.resize(1005);
	for (int i = 1; i <= N; i++)
		Count[father[i]]++;
	sort(Count.begin(), Count.end(), cmp);
	int num = 0;
	for (int i = 0; Count[i] != 0; i++)num++;
	cout << num << endl;
	for (int i = 0; Count[i] != 0; i++)
		if (i != 0)cout << " " << Count[i];
		else cout << Count[i];
}*/

//1114: 并查集
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<iomanip>
using namespace std;
class node
{
public:
	int id, member, sets, area;
	node() { id = -1;  member = sets = area = 0; }
};
int N;
int root[10000], estate[10000][2];
map<int, int>people;
vector<node>family;
bool cmp(node a, node b)
{
	if (a.id == -1)return 0;
	if (b.id == -1)return 1;
	if ((double)a.area / a.member > (double)b.area / b.member)
		return 1;
	else if ((double)a.area / a.member == (double)b.area / b.member && a.id < b.id)
		return 1;
	return 0;
}
int getFather(int x)
{
	int a = x;
	while (a != root[a])
		a = root[a];
	int b = x, c;
	while (b != root[b])
	{
		c = b;
		b = root[b];
		root[c] = a;
	}
	return a;
}
int main()
{
	cin >> N;
	string str1, str2, str3;
	int k, id, f, m, c, num, value;
	family.resize(10000);
	for (int i = 0; i < 10000; i++)
	{
		root[i] = i;
		family[i].id = -1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> str1 >> str2 >> str3;
		id = atoi(str1.c_str());
		people[id] = 0;
		f = atoi(str2.c_str());
		m = atoi(str3.c_str());
		if (f >= 0)
		{
			people[f] = 0;
			int fa = getFather(f);
			int fb = getFather(id);
			if (fa > fb)
			{
				root[fa] = fb;
				getFather(f);
			}
			else if (fa < fb)
			{
				root[fb] = fa;
				getFather(id);
			}
		}
		if (m >= 0)
		{
			people[m] = 0;
			int fa = getFather(m);
			int fb = getFather(id);
			if (fa > fb)
			{
				root[fa] = fb;
				getFather(m);
			}
			else if (fa < fb)
			{
				root[fb] = fa;
				getFather(id);
			}
		}
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> str2;
			c = atoi(str2.c_str());
			people[c] = 0;
			int fa = getFather(c);
			int fb = getFather(id);
			if (fa > fb)
			{
				root[fa] = fb;
				getFather(c);
			}
			else if (fa < fb)
			{
				root[fb] = fa;
				getFather(id);
			}
		}
		cin >> num >> value;
		estate[id][0] = num;
		estate[id][1] = value;
	}
	for (auto p = people.begin(); p != people.end(); p++)
	{
		int i = getFather(p->first);
		family[i].id = i;
		family[i].member++;
		family[i].sets += estate[p->first][0];
		family[i].area += estate[p->first][1];
	}
	sort(family.begin(), family.end(), cmp);
	int total = 0;
	for (int i = 0; family[i].id != -1; i++)
		total++;
	cout << total << endl;
	for (int i = 0; family[i].id != -1; i++)
	{
		int Id = family[i].id;
		int o[4];
		for (int j = 0; j < 4; j++)
		{
			o[j] = Id % 10;
			Id = Id / 10;
		}
		for (int j = 3; j >= 0; j--)
			cout << o[j];
		cout << " " << family[i].member << " " << setiosflags(ios::fixed) << setprecision(3) << (double)family[i].sets / family[i].member << " "
			<< (double)family[i].area / family[i].member << endl;
	}
}*/

//1118: 并查集
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int>father, Count;
int tree[10005], queues[10005][2];
int cmp(int a, int b) { return a > b; }
int findFather(int x)
{
	int a = x, b = x, c;
	while (a != father[a])
		a = father[a];
	while (b != father[b])
	{
		c = b;
		b = father[b];
		father[c] = a;
	}
	return a;
}
void Union(int a, int b)
{
	int fa = findFather(a);
	int fb = findFather(b);
	if (fa != fb)father[fa] = fb;
	findFather(a);
}
int main()
{
	int max_birds = 0, cur_bird;
	cin >> N;
	father.resize(10005);
	Count.resize(10005);
	for (int i = 0; i < 10005; i++)
		father[i] = i;
	for (int i = 0; i < N; i++)
	{
		int birds;
		cin >> birds;
		for (int j = 0; j < birds; j++)
		{
			cin >> cur_bird;
			if (cur_bird > max_birds)max_birds = cur_bird;
			if (tree[i] == 0)tree[i] = cur_bird;
			Union(cur_bird, tree[i]);
		}
	}
	for (int i = 1; i <= max_birds; i++)
	{
		Count[father[i]]++;
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> queues[i][0] >> queues[i][1];
	}
	int num = 0;
	sort(Count.begin(), Count.end(), cmp);
	for (int i = 0; Count[i] != 0; i++)
		num++;
	cout << num << " " << max_birds << endl;
	for (int i = 0; i < Q; i++)
	{
		if (father[queues[i][0]] == father[queues[i][1]])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}*/

/*1014: 队列*/
//#include<iostream>
//#include<queue>
//using namespace std;
//int N, M, K, Q;
//queue<int>customers;
//queue<int>windows[22];
//int times[1002], querys[1002], transaction[22], finish[1002], start[1002];
//string getTime(int x)
//{
//	int h = x / 60, m = x - 60 * h;
//	char a[6];
//	a[0] = (int)(h + 8) / 10 + '0';
//	a[1] = (h + 8) % 10 + '0';
//	a[2] = ':';
//	a[3] = (int)m / 10 + '0';
//	a[4] = m % 10 + '0';
//	a[5] = '\0';
//	return a;
//}
//int main()
//{
//	int max_time = (17 - 8) * 60, cur_time = 0, flag = 1;
//	cin >> N >> M >> K >> Q;
//	for (int i = 0; i < 22; i++)
//		transaction[i] = 0x3fffffff;
//	for (int i = 1; i <= K; i++)
//	{
//		cin >> times[i];
//		customers.push(i);
//	}
//	for (int i = 0; i < Q; i++)
//		cin >> querys[i];
//	int wait = 0, deal_time = 0x3fffffff, deal_index = 100;
//	while (wait < N * M && !customers.empty())
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (customers.empty() || wait == N * M)break;
//			windows[i].push(customers.front());
//			transaction[i] = times[windows[i].front()];
//			start[windows[i].front()] = cur_time;
//			if (transaction[i] < deal_time)
//			{
//				deal_time = transaction[i];
//				deal_index = i;
//			}
//			else if (transaction[i] == deal_time && i < deal_index)
//				deal_index = i;
//			customers.pop();
//			wait++;
//		}
//	}
//	while (flag)
//	{
//		flag = 0;
//		cur_time += deal_time;
//		int t = deal_time, id = deal_index;
//		deal_time = 0x3fffffff, deal_index = 100;
//		for (int i = 0; i < N; i++)
//		{
//			if (i == id)
//			{
//				if (!windows[i].empty())
//				{
//					finish[windows[i].front()] = cur_time;
//					windows[i].pop();
//				}
//				if (!customers.empty())
//				{
//					windows[i].push(customers.front());
//					customers.pop();
//				}
//				if (!windows[i].empty())
//				{
//					transaction[i] = times[windows[i].front()];
//					start[windows[i].front()] = cur_time;
//				}
//				else transaction[i] = 0x3fffffff;
//			}
//			else
//			{
//				transaction[i] -= t;
//				if (transaction[i] == 0)
//				{
//					if (!windows[i].empty())
//					{
//						finish[windows[i].front()] = cur_time;
//						windows[i].pop();
//					}
//					if (!customers.empty())
//					{
//						windows[i].push(customers.front());
//						customers.pop();
//					}
//					if (!windows[i].empty())
//					{
//						transaction[i] = times[windows[i].front()];
//						start[windows[i].front()] = cur_time;
//					}
//					else transaction[i] = 0x3fffffff;
//				}
//			}
//			if (transaction[i] < deal_time)
//			{
//				deal_time = transaction[i];
//				deal_index = i;
//			}
//			else if (transaction[i] == deal_time && i < deal_index)
//				deal_index = i;
//			if (!windows[i].empty())flag = 1;
//		}
//	}
//	for (int i = 0; i < Q; i++)
//	{
//		if (start[querys[i]] < max_time)cout << getTime(finish[querys[i]]) << endl;
//		else cout << "Sorry" << endl;
//	}
//}

/*1056: 队列*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
//int P, G;
//int player[1002], output[1002];
//map<int, int>id;
//vector<pair<int, int>>Rank;
//int cmp(pair<int, int>a, pair<int, int>b) { return a.second > b.second; }
//int main()
//{
//	int t;
//	vector<int>group, next_group, all_players;
//	cin >> P >> G;
//	Rank.resize(P);
//	for (int i = 0; i < P; i++)
//	{
//		cin >> player[i];
//		id[player[i]] = i;
//		Rank[i].first = player[i];
//		Rank[i].second = 0;
//	}
//	for (int i = 0; i < P; i++)
//	{
//		cin >> t;
//		all_players.push_back(player[t]);
//	}
//	while (all_players.size() != 1)
//	{
//		for (int i = 0; i < all_players.size(); i++)
//		{
//			group.push_back(all_players[i]);
//			if (i == all_players.size() - 1)
//			{
//				sort(group.begin(), group.end());
//				Rank[id[group.back()]].second++;
//				next_group.push_back(group.back());
//				all_players = next_group;
//				group.clear();
//				next_group.clear();
//			}
//			else if ((i + 1) % G == 0)
//			{
//				sort(group.begin(), group.end());
//				Rank[id[group.back()]].second++;
//				next_group.push_back(group.back());
//				group.clear();
//			}
//		}
//	}
//	sort(Rank.begin(), Rank.end(), cmp);
//	int cur_score = Rank[0].second, cur_rank = 1;
//	for (int i = 0; i < P; i++)
//	{
//		if (Rank[i].second != cur_score)
//		{
//			cur_rank = i + 1;
//			cur_score = Rank[i].second;
//		}
//		output[id[Rank[i].first]] = cur_rank;
//	}
//	for (int i = 0; i < P; i++)
//		if (i != P - 1)
//			cout << output[i] << " ";
//		else cout << output[i];
//}

/*1032: 链表*/
//#include<iostream>
//#include<map>
//using namespace std;
//int w1, w2, N;
//map<int, int>path;
//class node
//{
//public:
//	int id;
//	char data;
//	int next;
//	node() = default;
//};
//node words[100001];
//int main()
//{
//	int t;
//	cin >> w1 >> w2 >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> t;
//		words[t].id = t;
//		cin >> words[t].data >> words[t].next;
//	}
//	int i = w1, j = w2;
//	while (1)
//	{
//		path[i] = 1;
//		i = words[i].next;
//		if (i < 0)break;
//	}
//	while (j >= 0)
//	{
//		if (path.find(j) != path.end())break;
//		j = words[j].next;
//	}
//	if (j == -1)cout << j;
//	else
//	{
//		int a[5];
//		for (int k = 4; k >= 0; k--)
//		{
//			a[k] = j % 10;
//			j /= 10;
//		}
//		for (int k = 0; k < 5; k++)
//			cout << a[k];
//	}
//}

/*1052: 链表*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int address, key, next, flag;
//	node() { address = key = next = flag = 0; }
//};
//vector<node>nodes;
//int pos[100001];
//int N;
//string getNum(int x)
//{
//	char a[6];
//	for (int i = 4; i >= 0; i--)
//	{
//		a[i] = x % 10 + '0';
//		x /= 10;
//	}
//	a[5] = '\0';
//	return a;
//}
//int cmp(node a, node b)
//{
//	if (a.flag > b.flag)return 1;
//	else if (a.flag == b.flag && a.key < b.key)return 1;
//	return 0;
//}
//int main()
//{
//	int head;
//	nodes.resize(100001);
//	cin >> N >> head;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> nodes[i].address >> nodes[i].key >> nodes[i].next;
//		pos[nodes[i].address] = i;
//	}
//	int p = head, num = 0;
//	while (p != -1)
//	{
//		nodes[pos[p]].flag = 1;
//		p = nodes[pos[p]].next;
//		num++;
//	}
//	sort(nodes.begin(), nodes.end(), cmp);
//	if (num == 0) { cout << 0 << " " << -1; return 0; }
//	cout << num << " " << getNum(nodes[0].address) << endl;
//	for (int i = 0; nodes[i].flag != 0; i++)
//	{
//		if (nodes[i + 1].flag != 0)cout << getNum(nodes[i].address) << " " << nodes[i].key << " " << getNum(nodes[i + 1].address) << endl;
//		else cout << getNum(nodes[i].address) << " " << nodes[i].key << " " << -1 << endl;
//	}
//}

/*1074: 链表*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int address, key, next, flag;
//	node() { address = key = next = flag = 0; }
//};
//vector<node>nodes;
//vector<node*>list;
//int pos[100001];
//int N, K;
//string getNum(int x)
//{
//	char a[6];
//	for (int i = 4; i >= 0; i--)
//	{
//		a[i] = x % 10 + '0';
//		x /= 10;
//	}
//	a[5] = '\0';
//	return a;
//}
//void Reverse(int start, int end)
//{
//	vector<node*>link;
//	for (int i = start; i < end; i++)
//	{
//		link.push_back(list[i]);
//	}
//	for (int i = start; i < end; i++)
//	{
//		list[i] = link[end - i - 1];
//	}
//}
//int main()
//{
//	int head;
//	cin >> head >> N >> K;
//	nodes.resize(100001);
//	list.resize(100001);
//	for (int i = 0; i < 100001; i++)
//		pos[i] = -1;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> nodes[i].address >> nodes[i].key >> nodes[i].next;
//		pos[nodes[i].address] = i;
//	}
//	int p = head, i = 0, start = 0, end;
//	while (p != -1)
//	{
//		if (pos[p] == -1)break;
//		list[i] = &nodes[pos[p]];
//		i++;
//		p = nodes[pos[p]].next;
//	}
//	for (int i = 0; list[i] != 0; i++)
//	{
//		if ((i + 1) % K == 0)
//		{
//			end = i + 1;
//			Reverse(start, end);
//			start = i + 1;
//		}
//	}
//	if (list[0] == 0)cout << -1;
//	for (int i = 0; list[i] != 0; i++)
//	{
//		if (list[i + 1] != 0)cout << getNum(list[i]->address) << " " << list[i]->key << " " << getNum(list[i + 1]->address) << endl;
//		else cout << getNum(list[i]->address) << " " << list[i]->key << " " << -1 << endl;
//	}
//}

/*1097: 链表*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int address, key, next, flag;
//	node() { address = key = next = flag = 0; }
//};
//int pos[100001], exist[100001];
//vector<node*>duplicate;
//node nodes[100001];
//node* list[100001];
//int N;
//string getNum(int x)
//{
//	char a[6];
//	for (int i = 4; i >= 0; i--)
//	{
//		a[i] = x % 10 + '0';
//		x /= 10;
//	}
//	a[5] = '\0';
//	return a;
//}
//int main()
//{
//	int head;
//	cin >> head >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> nodes[i].address >> nodes[i].key >> nodes[i].next;
//		pos[nodes[i].address] = i;
//	}
//	int p = head, i = 0;
//	while (p != -1)
//	{
//		list[i] = &nodes[pos[p]];
//		p = nodes[pos[p]].next;
//		i++;
//	}
//	for (int i = 0; list[i] != 0; i++)
//	{
//		if (exist[abs(list[i]->key)])
//		{
//			list[i]->flag = 1;
//			duplicate.push_back(list[i]);
//		}
//		exist[abs(list[i]->key)] = 1;
//	}
//	for (int i = 0; list[i] != 0; i++)
//	{
//		if (!list[i]->flag)
//		{
//			int j = i + 1;
//			while (list[j] != 0 && list[j]->flag)j++;
//			if (list[j] != 0)cout << getNum(list[i]->address) << " " << list[i]->key << " " << getNum(list[j]->address) << endl;
//			else cout << getNum(list[i]->address) << " " << list[i]->key << " " << -1 << endl;
//		}
//	}
//	for (int i = 0; i < duplicate.size(); i++)
//	{
//		if (i != duplicate.size() - 1)cout << getNum(duplicate[i]->address) << " " << duplicate[i]->key << " " << getNum(duplicate[i + 1]->address) << endl;
//		else cout << getNum(duplicate[i]->address) << " " << duplicate[i]->key << " " << -1 << endl;
//	}
//}

/*1113: 链表*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int address, key, next, flag;
//	node() { address = key = next = flag = 0; }
//};
//int pos[100001];
//vector<node*>negative, bigger, other;
//node nodes[100001];
//node* list[100001];
//int N, K;
//string getNum(int x)
//{
//	char a[6];
//	for (int i = 4; i >= 0; i--)
//	{
//		a[i] = x % 10 + '0';
//		x /= 10;
//	}
//	a[5] = '\0';
//	return a;
//}
//int main()
//{
//	int head;
//	cin >> head >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> nodes[i].address >> nodes[i].key >> nodes[i].next;
//		pos[nodes[i].address] = i;
//	}
//	int p = head, i = 0;
//	while (p != -1)
//	{
//		list[i] = &nodes[pos[p]];
//		i++;
//		p = nodes[pos[p]].next;
//	}
//	for (int i = 0; list[i] != 0; i++)
//	{
//		if (list[i]->key < 0)
//		{
//			negative.push_back(list[i]);
//			list[i]->flag = 1;
//		}
//		if (list[i]->key > K)
//		{
//			bigger.push_back(list[i]);
//			list[i]->flag = 1;
//		}
//	}
//	for (int i = 0; list[i] != 0; i++)
//	{
//		if (list[i]->flag == 0)
//			other.push_back(list[i]);
//	}
//	if (!negative.empty())
//	{
//		for (int i = 0; i < negative.size(); i++)
//		{
//			if (i != negative.size() - 1)
//				cout << getNum(negative[i]->address) << " " << negative[i]->key << " " << getNum(negative[i + 1]->address) << endl;
//			else
//			{
//				int j = 0;
//				while (list[j] != 0 && list[j]->flag)j++;
//				if (list[j] != 0)
//				{
//					cout << getNum(negative[i]->address) << " " << negative[i]->key << " " << getNum(list[j]->address) << endl;
//					for (int ii = 0; ii < N; ii++)
//					{
//						if (list[ii]->flag == 0)
//						{
//							int jj = ii + 1;
//							while (list[jj] != 0 && list[jj]->flag)jj++;
//							if (list[jj] != 0)cout << getNum(list[ii]->address) << " " << list[ii]->key << " " << getNum(list[jj]->address) << endl;
//							else if (!bigger.empty())
//							{
//								cout << getNum(list[ii]->address) << " " << list[ii]->key << " " << getNum(bigger[0]->address) << endl;
//								for (int iii = 0; iii < bigger.size(); iii++)
//								{
//									if (iii != bigger.size() - 1)
//										cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << getNum(bigger[iii + 1]->address) << endl;
//									else cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << -1 << endl;
//								}
//							}
//							else
//								cout << getNum(list[ii]->address) << " " << list[ii]->key << " " << -1 << endl;
//						}
//					}
//				}
//				else if (!bigger.empty())
//				{
//					cout << getNum(negative[i]->address) << " " << negative[i]->key << " " << getNum(bigger[0]->address) << endl;
//					for (int iii = 0; iii < bigger.size(); iii++)
//					{
//						if (iii != bigger.size() - 1)
//							cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << getNum(bigger[iii + 1]->address) << endl;
//						else cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << -1 << endl;
//					}
//				}
//				else
//					cout << getNum(negative[i]->address) << " " << negative[i]->key << " " << -1 << endl;
//			}
//		}
//	}
//	else if (!other.empty())
//	{
//		for (int i = 0; i < other.size(); i++)
//		{
//			if (i != other.size() - 1)
//				cout << getNum(other[i]->address) << " " << other[i]->key << " " << getNum(other[i + 1]->address) << endl;
//			else if(!bigger.empty())
//			{
//				cout << getNum(other[i]->address) << " " << other[i]->key << " " << getNum(bigger[0]->address) << endl;
//				for (int iii = 0; iii < bigger.size(); iii++)
//				{
//					if (iii != bigger.size() - 1)
//						cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << getNum(bigger[iii + 1]->address) << endl;
//					else cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << -1 << endl;
//				}
//			}
//			else cout << getNum(other[i]->address) << " " << other[i]->key << " " << -1 << endl;
//		}
//	}
//	else
//	{
//		for (int iii = 0; iii < bigger.size(); iii++)
//		{
//			if (iii != bigger.size() - 1)
//				cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << getNum(bigger[iii + 1]->address) << endl;
//			else cout << getNum(bigger[iii]->address) << " " << bigger[iii]->key << " " << -1 << endl;
//		}
//	}
//}

/*1122: 图论*/
//#include<iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//int N, M, K;
//int edge[202][202];
//vector<vector<int>>query;
//bool isCircle(vector<int>q)
//{
//	if (q.front() != q.back())return 0;
//	int flag = 1, cnt = 0, k;
//	int visited[202];
//	for (int i = 0; i < q.size() - 1; i++)
//	{
//		cnt = 1;
//		memset(visited, 0, sizeof(visited));
//		visited[q[i]] = 1;
//		for (int j = i + 1;; j++)
//		{
//			if (j == q.size() - 1)j = 0;
//			if (visited[q[j]])break;
//			if (j == 0)k = q.size() - 2;
//			else k = j - 1;
//			if (!edge[q[k]][q[j]])return 0;
//			cnt++;
//			visited[q[j]] = 1;
//		}
//		if (cnt != q.size() - 1)
//		{
//			flag = 0;
//			break;
//		}
//	}
//	if (flag)return 1;
//	else return 0;
//}
//int main()
//{
//	int a, b, n, t;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		edge[a][b] = edge[b][a] = 1;
//	}
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> n;
//		query.push_back(*new vector<int>);
//		for (int j = 0; j < n; j++)
//		{
//			cin >> t;
//			query.back().push_back(t);
//		}
//	}
//	for (int i = 0; i < K; i++)
//	{
//		if (!isCircle(query[i]))cout << "NO" << endl;
//		else if (query[i].size() != N + 1)cout << "NO" << endl;
//		else cout << "YES" << endl;
//	}
//}

/*1126: 图论*/
//#include<iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//int N, M, num;
//int G[502][502], visited[502];
//int degree[502];
//vector<int>edge[502];
//bool connect(int x)
//{
//	visited[x] = 1;
//	num++;
//	for (int i = 0; i < edge[x].size(); i++)
//	{
//		if (!visited[edge[x][i]])
//			if(connect(edge[x][i])) r
//	}
//	if (num == N)return 1;
//	visited[x] = 0;
//	num--;
//	return 0;
//}
//int main()
//{
//	int a, b, odd = 0;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		if (G[a][b] == 0)degree[a]++;
//		if (G[b][a] == 0)degree[b]++;
//		G[a][b] = G[b][a] = 1;
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		if (i != N)cout << degree[i] << " ";
//		else cout << degree[i] << endl;
//		if (degree[i] % 2 == 1)odd++;
//	}
//	if (odd != 0 && odd != 2)
//	{
//		cout << "Non-Eulerian";
//		return 0;
//	}
//	else if (!connect(1))
//	{
//		cout << "Non-Eulerian";
//		return 0;
//	}
//	if (odd == 0)cout << "Eulerian";
//	else if (odd == 2)cout << "Semi-Eulerian";
//	else cout << "Non-Eulerian";
//}

/*1142: 图论*/
//#include<iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//int N, M, K, num;
//vector<int>G[202], query[100];
//int exist[202];
//int edge[202][202];
//bool isClique(vector<int>q)
//{
//	for (int i = 0; i < q.size(); i++)
//	{
//		for (int j = i + 1; j < q.size(); j++)
//		{
//			if (!edge[q[i]][q[j]])return 0;
//		}
//	}
//	return 1;
//}
//bool isMax(vector<int>q)
//{
//	vector<int>nodes;
//	for (int i = 0; i < q.size(); i++)
//	{
//		for (int j = 0; j < G[q[i]].size(); j++)
//		{
//			if (!exist[G[q[i]][j]] && edge[q[i]][G[q[i]][j]])
//			{
//				nodes.push_back(G[q[i]][j]);
//				exist[G[q[i]][j]] = 1;
//			}
//		}
//	}
//	for (int i = 0; i < nodes.size(); i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < q.size(); j++)
//		{
//			if (!edge[q[j]][nodes[i]])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int a, b;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		G[a].push_back(b);
//		G[b].push_back(a);
//		edge[a][b] = 1;
//		edge[b][a] = 1;
//	}
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> a;
//		for (int j = 0; j < a; j++)
//		{
//			cin >> b;
//			query[i].push_back(b);
//		}
//	}
//	for (int i = 0; i < K; i++)
//	{
//		num = 0;
//		memset(exist, 0, sizeof(exist));
//		for (int j = 0; j < query[i].size(); j++)
//			exist[query[i][j]] = 1;
//		if (!isClique(query[i]))
//			cout << "Not a Clique" << endl;
//		else if (isMax(query[i]))
//			cout << "Yes" << endl;
//		else cout << "Not Maximal" << endl;
//	}
//}

/*1150: 图论*/
//#include<iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//int N, M, K;
//vector<int>edge[202];
//int G[202][202], visited[202];
//vector<vector<int>>querys;
//pair<int, int> isCycle(vector<int>q)
//{
//	memset(visited, 0, sizeof(visited));
//	int num = 0, dis = 0;
//	pair<int, int>res;
//	if (q.front() != q.back())res.first = -1;
//	else res.first = 1;
//	for (int i = 0; i < q.size(); i++)
//	{
//		if (i != 0)
//		{
//			if (G[q[i - 1]][q[i]] == 0)
//			{
//				res.first = -1;
//				res.second = -1;
//				return res;
//			}
//			dis += G[q[i - 1]][q[i]];
//		}
//		if (!visited[q[i]])
//		{
//			num++;
//			visited[q[i]] = 1;
//		}
//	}
//	res.second = dis;
//	if (num != N)res.first = -1;
//	return res;
//}
//int main()
//{
//	cin >> N >> M;
//	int a, b, c;
//	int mindis = 999999, index = -1;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		G[a][b] = G[b][a] = c;
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//	}
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> a;
//		querys.push_back(*new vector<int>);
//		for (int j = 0; j < a; j++)
//		{
//			cin >> b;
//			querys.back().push_back(b);
//		}
//	}
//	for (int i = 0; i < K; i++)
//	{
//		pair<int, int>res = isCycle(querys[i]);
//		if (res.first < 0)
//		{
//			if (res.second < 0)
//				cout << "Path " << i + 1 << ": NA (Not a TS cycle)" << endl;
//			else cout << "Path " << i + 1 << ": " << res.second << " (Not a TS cycle)" << endl;
//		}
//		else
//		{
//			if (res.second < mindis)
//			{
//				mindis = res.second;
//				index = i + 1;
//			}
//			if (querys[i].size() != N + 1)
//				cout << "Path " << i + 1 << ": " << res.second << " (TS cycle)" << endl;
//			else
//				cout << "Path " << i + 1 << ": " << res.second << " (TS simple cycle)" << endl;
//		}
//	}
//	cout << "Shortest Dist(" << index << ") = " << mindis;
//}

/*1146: 拓扑排序*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M, K;
//vector<int>r_edge[1002], edge[1002];
//vector<vector<int>>querys;
//vector<int> isempty, res;
//int isTopological(vector<int>q)
//{
//	vector<int>R_edge[1002];
//	vector<int> cnt = isempty;
//	for (int i = 1; i <= N; i++)
//		R_edge[i] = r_edge[i];
//	for (int i = 0; i < q.size(); i++)
//	{
//		if (cnt[q[i]] != 0)return 0;
//		else
//		{
//			for (int j = 0; j < edge[q[i]].size(); j++)
//			{
//				int node_to = edge[q[i]][j];
//				for (int k = 0; k < R_edge[node_to].size(); k++)
//				{
//					if (R_edge[node_to][k] == q[i])
//					{
//						R_edge[node_to][k] = 0;
//						cnt[node_to]--;
//						break;
//					}
//				}
//			}
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int a, b;
//	isempty.resize(1002);
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		r_edge[b].push_back(a);
//		edge[a].push_back(b);
//		isempty[b]++;
//	}
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		querys.push_back(*new vector<int>);
//		for (int j = 0; j < N; j++)
//		{
//			cin >> b;
//			querys.back().push_back(b);
//		}
//	}
//	for (int i = 0; i < K; i++)
//		if (!isTopological(querys[i]))res.push_back(i);
//	for (int i = 0; i < res.size(); i++)
//		if (i != res.size() - 1)
//			cout << res[i] << " ";
//		else cout << res[i];
//}

/*1054: map*/
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//int N, M;
//int image[805][805];
//int main()
//{
//	int d, maxr = 0, index;
//	unordered_map<int, int>m;
//	cin >> N >> M;
//	for(int i=0;i<M;i++)
//		for (int j = 0; j < N; j++)
//		{
//			cin >> d;
//			m[d]++;
//		}
//	for (auto i : m)
//	{
//		if (i.second > maxr)
//		{
//			maxr = i.second;
//			index = i.first;
//		}
//	}
//	cout << index;
//}

/*1071: map*/
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<string>
//using namespace std;
//bool isLetter(char a)
//{
//	if (!((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')))
//		return 0;
//	return 1;
//}
//int main()
//{
//	int maxn = 0;
//	string index;
//	unordered_map<string, int>m;
//	string art;
//	getline(cin, art);
//	int i = 0, j = 0;
//	while (!isLetter(art[i]))i++;
//	for (j = i; j < art.size(); j++)
//	{
//		if (!isLetter(art[j]))
//		{
//			string w;
//			for (int k = i; k < j; k++)
//			{
//				char t = art[k];
//				if (t >= 'A' && t <= 'Z')t += 'a' - 'A';
//				w.push_back(t);
//			}
//			m[w]++;
//			while (j < art.size() && !isLetter(art[j]))j++;
//			i = j;
//			j--;
//		}
//	}
//	if (i != art.size())
//	{
//		string w;
//		for (int j = i; j < art.size(); j++)
//		{
//			char t = art[j];
//			if (t >= 'A' && t <= 'Z')t += 'a' - 'A';
//			w.push_back(t);
//		}
//		m[w]++;
//	}
//	for (auto i : m)
//	{
//		if (i.second >= maxn)
//		{
//			if (i.second > maxn)
//			{
//				maxn = i.second;
//				index = i.first;
//			}
//			else if (i.second == maxn && index > i.first)
//				index = i.first;
//		}
//	}
//	cout << index << " " << maxn;
//}