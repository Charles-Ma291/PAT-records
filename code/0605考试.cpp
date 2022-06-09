/*1*/
//#include<iostream>
//using namespace std;
//class date
//{
//public:
//	int val;
//	int next()
//	{
//		if (val == 6)return 0;
//		else return val + 1;
//	}
//	int prev()
//	{
//		if (val == 0)return 6;
//		else return val - 1;
//	}
//	string int2date()
//	{
//		switch (val)
//		{
//		case 0:
//			return "Sunday";
//		case 1:
//			return "Monday";
//		case 2:
//			return "Tuesday";
//		case 3:
//			return "Wednesday";
//		case 4:
//			return "Thursday";
//		case 5:
//			return "Friday";
//		case 6:
//			return "Saturday";
//		}
//	}
//};
//int main()
//{
//	int k1[3], k2[3];
//	for (int i = 0; i < 3; i++)cin >> k1[i];
//	for (int i = 0; i < 3; i++)cin >> k2[i];
//	date today;
//	today.val = 0;
//	for (; today.val < 7; today.val++)
//	{
//		int t1 = 0, t2 = 0, i1, i2;
//		if (today.prev() == k1[0])
//		{
//			t1++;
//			i1 = 0;
//		}
//		if (today.val == k1[1])
//		{
//			t1++;
//			i1 = 1;
//		}
//		if (today.next() == k1[2])
//		{
//			t1++;
//			i1 = 2;
//		}
//		if (today.prev() == k2[0])
//		{
//			t2++;
//			i2 = 0;
//		}
//		if (today.val == k2[1])
//		{
//			t2++;
//			i2 = 1;
//		}
//		if (today.next() == k2[2])
//		{
//			t2++;
//			i2 = 2;
//		}
//		if (t1 == 1 && t2 == 1)
//		{
//			cout << today.int2date() << endl;
//			switch (i1)
//			{
//			case 0:
//				cout << "yesterday\n";
//				break;
//			case 1:
//				cout << "today\n";
//				break;
//			case 2:
//				cout << "tomorrow\n";
//				break;
//			};
//			switch (i2)
//			{
//			case 0:
//				cout << "yesterday\n";
//				break;
//			case 1:
//				cout << "today\n";
//				break;
//			case 2:
//				cout << "tomorrow\n";
//				break;
//			};
//
//			return 0;
//		}
//	}
//}

/*2*/
//#include<deque>
//#include<map>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int N, M;
////<int, int>* pos[20005] = { 0 };
//int cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
//int main()
//{
//	deque<pair<int, int>>q, out;
//	int a, pos=-1;
//	cin >> N >> M;
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> a;
//		for (int j = 0; j < q.size(); j++)if (q[j].first == a)pos = j;
//		if (pos<0)
//		{
//			//cout << "NO ";
//			if (q.size() < N)
//			{
//				q.push_back(pair<int, int>(a, i));
//				//pos[a] = &q.back();
//			}
//			else
//			{
//				cout << 'a';
//				out.push_back(pair<int, int>(q[0]));
//				//pos[q[0].first] = nullptr;
//				q.pop_front();
//				q.push_back(pair<int, int>(a, i));
//				//pos[a] = &q.back();
//			}
//		}
//		else
//		{
//			//cout << "YES ";
//			q[pos].second = i;
//			sort(q.begin(), q.end(), cmp);
//		}
//		//for (int j = 0; j < q.size(); j++)
//		//	cout << q[j].first << " ";
//		////if (pos[1] == 0)cout << 0 << endl;
//		////else cout << pos[1]->key << endl;
//		//cout << endl;
//
//	}
//	for (int i = 0; i < out.size(); i++)
//		if (i != out.size() - 1)cout << out[i].first << " ";
//		else cout << out[i].first;
//}

#include<queue>
#include<deque>
#include<iostream>
#include<map>
using namespace std;
int N, M;
int cmp(pair<int, int>a, pair<int, int>b) { return a.second < b.second; }
int main()
{
	priority_queue<pair<int, int>>s;
	int a, b;
	deque<int>q, out;
	map<int, int>p;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		if (s.size() < N)s.push(pair<int, int>(a, i));
		else
		{
			out.push_back(s.top().first);
			s.pop();
			s.push(pair<int, int>(a, i));
		}
	}
	for (int i = 0; i < out.size(); i++)
		if (i != out.size() - 1)cout << out[i] << " ";
		else cout << out[i];
}




/*3*/
//#include<iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//int N, M, K;
//vector<int>edge[1005];
//int seq[1005], visited[1005], onemore = 0;
//int dfs(int start)
//{
//	int flag = 1;
//	if (visited[seq[start]])return -1;
//	if (start == N - 1)return start;
//	visited[seq[start]] = 1;
//	for (int i = 0; i < edge[seq[start]].size(); i++)
//	{
//		if (edge[seq[start]][i] == seq[start + 1])
//			return dfs(start + 1);
//		if (!visited[edge[seq[start]][i]])flag = 0;
//	}
//	if (flag)onemore++;
//	return start;
//}
//int main()
//{
//	int a, b;
//	cin >> N >> M >> K;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		edge[a].push_back(b);
//	}
//	for (int i = 0; i < K; i++)
//	{
//		onemore = 1;
//		memset(visited, 0, sizeof(visited));
//		for (int j = 0; j < N; j++)
//			cin >> seq[j];
//		int end1 = -1;
//		while (onemore > 0)
//		{
//			end1 = dfs(end1 + 1);
//			onemore--;
//		}
//		if (end1 == N - 1)cout << "yes\n";
//		else cout << "no\n";
//	}
//}

/*4*/
//#include<iostream>
//#include<math.h>
//using namespace std;
//int N, d, index, K;
//int tree[200], num[55], q[54];
//void maketree(int pos)
//{
//	if (index >= N)return;
//	tree[pos] = num[index];
//	index++;
//	for (int i = 1; i <= d && pos * d + i < N; i++)
//		maketree(pos * d + i);
//}
//int main()
//{
//	cin >> N >> d;
//	//int level;
//	//for (level = 1; (pow(d, level) - 1) / 2 < N; level++);
//	for (int i = 0; i < N; i++)
//		cin >> num[i];
//	maketree(0);
//	cin >> K;
//	for (int i = 0; i < K; i++)
//		cin >> q[i];
//	for (int i = 0; i < N; i++)
//		if (i != N - 1)cout << tree[i] << " ";
//		else cout << tree[i] << endl;
//	for (int i = 0; i < K; i++)
//	{
//		int index = q[i];
//		while (index >= 0)
//		{
//			if (index != 0)cout << tree[index] << " ";
//			else
//			{
//				cout << tree[index] << endl;
//				break;
//			}
//			index = (index - 1) / d;
//		}
//	}
//}