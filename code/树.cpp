//PART3：树——BFS、DFS etc.

//1004: BFS
/*
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<deque>
using namespace std;
class node
{
public:
	char id[5];
	node* child[105];
	int childnum;
	node()
	{
		childnum = 0;
		for (int i = 0; i < 105; i++)
			child[i] = NULL;
	}
};
int main()
{
	int n, m;
	string str = "01";
	cin >> n >> m;
	node tree[105];
	strcpy(tree[0].id, (char*)str.c_str());
	for (int i = 0; i < m; i++)
	{
		int num;
		string child;
		cin >> str >> num;
		tree[atoi(str.c_str()) - 1].childnum = num;
		for (int j = 0; j < num; j++)
		{
			cin >> child;
			tree[atoi(str.c_str()) - 1].child[j] = &tree[atoi(child.c_str()) - 1];
		}
	}

	//BFS
	deque<node*>V;
	int num, same, leaf, first = 0;
	V.push_back(&tree[0]);
	num = 1;
	while (!V.empty())
	{
		for (int i = 0; i < num; i++)
		{
			//添加下一层的node
			for (int j = 0; j < V[i]->childnum; j++)
			{
				//检查有无重复
				same = 0;
				for (int k = num; k < V.size(); k++)
				{
					if (strcmp(V[k]->id, V[i]->child[j]->id))
					{
						same = 1;
						break;
					}
				}
				if (!same)
					V.push_back(V[i]->child[j]);
			}
		}
		leaf = 0;
		for (int i = 0; i < num; i++)
		{
			//pop本层节点并输出
			if (V[0]->childnum == 0)
				leaf++;
			V.pop_front();
		}
		if (!first)
		{
			first = 1;
			cout << leaf;
		}
		else cout << " " << leaf;
		num = V.size();
	}
}
*/

//1013: DFS
/*
#include<iostream>
#include<string.h>
using namespace std;
int N, M, K, total;
int visited[1005];
int G[1005][1005];
int city[1005];
void dfs(int start)
{
	//cout << total;
	total++;
	visited[start] = 1;
	//search for G
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && G[start][i])
			dfs(i);
	}
}
int main()
{
	int times;
	cin >> N >> M >> K;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
	for (int i = 0; i < K; i++)
		cin >> city[i];
	for (int i = 0; i < K; i++)
	{
		memset(visited, 0, sizeof(visited));
		total = 0;
		visited[city[i]] = 1;
		times = 0;
		while (total != N - 1)
		{
			times++;
			for (int j = 1; j <= N; j++)
			{
				if (!visited[j])
				{
					dfs(j);
					break;
				}
			}
		}
		if (i == K - 1)
			cout << times - 1;
		else
			cout << times - 1 << endl;
	}
}*/

//1021: DFS
/*
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int N, total, height, maxheight, treeheight;
vector<int>maxnode;
//int G[10005][10005];
vector<int>G[10005];
int visited[10005];
void dfs(int start)
{
	visited[start] = 1;
	total++;
	for (int i = 0; i < G[start].size(); i++)
	{
		if (!visited[G[start][i]])
		{
			height++;
			dfs(G[start][i]);
		}
	}
	if (height > treeheight)
		treeheight = height;
	height--;
}
int main()
{
	int a, b, time;
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		//G[a][b] = G[b][a] = 1;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		total = height = treeheight = 0;
		time = 1;
		memset(visited, 0, sizeof(visited));
		dfs(i);
		if (total == N)
		{
			if (treeheight > maxheight)
			{
				maxnode.clear();
				maxheight = treeheight;
				maxnode.push_back(i);
			}
			else if (treeheight == maxheight)
				maxnode.push_back(i);
		}
		else
		{
			while (total != N)
			{
				time++;
				for (int j = 1; j <= N; j++)
				{
					if (!visited[j])
					{
						dfs(j);
						break;
					}
				}
			}
			cout << "Error: " << time << " components";
			return 0;
		}
	}
	for (int i = 0; i < maxnode.size(); i++)
		if (i == maxnode.size() - 1)
			cout << maxnode[i];
		else
			cout << maxnode[i] << endl;
}*/

//1034: DFS
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int N, K, total, gang, head, maxrelation;
map<string, int>name2id;
string id2name[2005];
int G[1005][3];
int visited[2005];
int relation[2005];
vector<pair<string, int>>res;
vector<int>members;
bool cmp(pair<string, int>s1, pair<string, int>s2)
{
	return s1.first < s2.first;
}
void dfs(int start)
{
	members.push_back(start);
	visited[start] = 1;
	for (int i = 0; i < N; i++)
	{
		if (G[i][0] != G[i][1])
		{
			if (G[i][0] == start && !visited[G[i][1]])
			{
				dfs(G[i][1]);
			}

			if (G[i][1] == start && !visited[G[i][0]])
			{
				dfs(G[i][0]);
			}
		}
	}
}
int main()
{
	string a, b;
	int c, find;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		find = 0;
		cin >> a >> b >> c;
		if (name2id.find(a) == name2id.end())
		{
			id2name[name2id.size()] = a;
			name2id.insert(pair<string, int>(a, name2id.size()));
		}
		if (name2id.find(b) == name2id.end())
		{
			id2name[name2id.size()] = b;
			name2id.insert(pair<string, int>(b, name2id.size()));
		}
		for (int j = 0; j < i; j++)
		{
			if (G[j][0] == name2id[b] && G[j][1] == name2id[a])
			{
				find = 1;
				G[j][2] += c;
				break;
			}
			if (G[j][0] == name2id[a] && G[j][1] == name2id[b])
			{
				find = 1;
				G[j][2] += c;
				break;
			}
		}
		if (!find)
		{
			G[i][0] = name2id[a];
			G[i][1] = name2id[b];
			G[i][2] = c;
		}
		else
			G[i][0] = G[i][1] = G[i][2] = -1;
	}
	while (total != name2id.size())
	{
		gang = maxrelation = head = 0;
		members.clear();
		for (int i = 0; i < name2id.size(); i++)
		{
			if (!visited[i])
			{
				dfs(i);
				break;
			}
		}
		total += members.size();
		for (int i = 0; i < N; i++)
		{
			if (G[i][0] != G[i][1])
			{
				for (int j = 0; j < members.size(); j++)
				{
					if (members[j] == G[i][0])
					{
						gang += G[i][2];
						relation[G[i][0]] += G[i][2];
						relation[G[i][1]] += G[i][2];
						if (relation[G[i][0]] > maxrelation)
						{
							head = G[i][0];
							maxrelation = relation[G[i][0]];
						}
						if (relation[G[i][1]] > maxrelation)
						{
							head = G[i][1];
							maxrelation = relation[G[i][1]];
						}
						break;
					}
					if (members[j] == G[i][1])
					{
						gang += G[i][2];
						relation[G[i][1]] += G[i][2];
						relation[G[i][0]] += G[i][2];
						if (relation[G[i][1]] > maxrelation)
						{
							head = G[i][1];
							maxrelation = relation[G[i][1]];
						}
						if (relation[G[i][0]] > maxrelation)
						{
							head = G[i][0];
							maxrelation = relation[G[i][0]];
						}
						break;
					}
				}
			}
		}
		//cout << gang << endl;
		if (gang > K && members.size() > 2)
			res.push_back(pair<string, int>(id2name[head], members.size()));
	}
	if (res.empty())
		cout << 0;
	else
	{
		cout << res.size() << endl;
		sort(res.begin(), res.end(), cmp);
		for (int i = 0; i < res.size(); i++)
		{
			if (i == res.size() - 1)
				cout << res[i].first << " " << res[i].second;
			else
				cout << res[i].first << " " << res[i].second << endl;
		}
	}
}*/

//1103: DFS
/*
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, K, P;
vector<vector<int>>res;
vector<int>temp;
bool cmp(vector<int>a, vector<int>b)
{
	int suma = 0, sumb = 0;
	for (int i = 0; i < K; i++)
	{
		suma += a[i];
		sumb += b[i];
	}
	if (suma > sumb)
		return true;
	else if (suma == sumb)
	{
		int i = 0;
		for (i = 0; i < K; i++)
		{
			if (a[i] > b[i])
				return true;
			if (a[i] < b[i])
				return false;
		}
	}
	else
		return false;
	return false;
}
void factorization(int index, int level, int sum)
{
	if (level == 0)
		temp.clear();
	for (int i = index; i > 0; i--)
	{
		temp.push_back(i);
		if (level != K)
		{
			if (sum + pow(i, P) >= N)
			{
				temp.pop_back();
				continue;
			}
			factorization(i, level + 1, sum + pow(i, P));
		}
		else if (sum + pow(i, P) == N)
		{
			res.push_back(temp);
			temp.pop_back();
			return;
		}
		temp.pop_back();
	}
}
int main()
{
	cin >> N >> K >> P;
	factorization(int(pow(N, (double)1 / P)), 1, 0);
	if (res.empty())
		cout << "Impossible";
	else
	{
		sort(res.begin(), res.end(), cmp);
		cout << N << " = ";
		for (int i = 0; i < K; i++)
		{
			if (i != K - 1)
				cout << res[0][i] << "^" << P << " + ";
			else
				cout << res[0][i] << "^" << P;
		}
	}
}
*/

//1130: DFS
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N, root;
int tree[25][2];
string id[25];
vector<string>expr;
void dfs(int start)
{
	if (!((tree[start][0] == -1 && tree[start][1] == -1) || start == root))expr.push_back("(");
	if (tree[start][0] != -1)dfs(tree[start][0]);
	expr.push_back(id[start]);
	if (tree[start][1] != -1)dfs(tree[start][1]);
	if (!((tree[start][0] == -1 && tree[start][1] == -1) || start == root))expr.push_back(")");
}
int main()
{
	cin >> N;
	int visited[25] = { 0 };
	for (int i = 1; i <= N; i++)
	{
		cin >> id[i] >> tree[i][0] >> tree[i][1];
		if (tree[i][0] != -1)visited[tree[i][0]] = 1;
		if (tree[i][1] != -1)visited[tree[i][1]] = 1;
	}
	for (int i = 1; i <= N; i++)
		if (!visited[i])
		{
			root = i;
			dfs(i);
			break;
		}
	for (int i = 0; i < expr.size(); i++)
		cout << expr[i];
}
*/

//1131: DFS
/*
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
int N, K, root, des;
int subway[105][105];
vector<pair<int, int>>G[10005];
vector<pair<int, int>>temp_path;
vector<vector<pair<int, int>>>path;
int req[10][2];
int visited[10005];
string printnum(int a)
{
	char digit[5];
	digit[4] = '\0';
	for (int i = 3; i >= 0; i--)
	{
		digit[i] = a % 10 + '0';
		a /= 10;
	}
	return string(digit);
}
int getlength(vector<pair<int, int>>a)
{
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int dete = 0, pos1, pos2;
		if (!i)
		{
			for (int j = 0; j < 105; j++)
			{
				if (subway[a[0].second][j] == root)
				{
					dete++;
					pos1 = j;
				}
				if (subway[a[0].second][j] == a[0].first)
				{
					dete++;
					pos2 = j;
				}
				if (dete == 2)
					break;
			}
		}
		else
		{
			for (int j = 0; j < 105; j++)
			{
				if (subway[a[i].second][j] == a[i - 1].first)
				{
					dete++;
					pos1 = j;
				}
				if (subway[a[i].second][j] == a[i].first)
				{
					dete++;
					pos2 = j;
				}
				if (dete == 2)
					break;
			}
		}
		sum += abs(pos1 - pos2);
	}
	return sum;
}
bool cmp(vector<pair<int, int>>a, vector<pair<int, int>>b)
{
	int suma = getlength(a), sumb = getlength(b);
	if (suma < sumb)
	{
		return true;
	}
	else if (suma == sumb)
	{
		return a.size() < b.size();
	}
	else
	{
		return false;
	}
}
void dfs(int start, int route)
{
	visited[start] = 1;
	for (int i = 0; i < G[start].size(); i++)
	{
		if (!visited[G[start][i].first])
		{
			if (G[start][i].first == des)
			{
				if (root != start && route != G[start][i].second)temp_path.push_back(pair<int, int>(start, route));
				temp_path.push_back(pair<int, int>(des, G[start][i].second));
				path.push_back(temp_path);
				temp_path.pop_back();
				if (root != start && route != G[start][i].second)temp_path.pop_back();
				visited[start] = 0;
				return;
			}
			if (root != start && route != G[start][i].second)temp_path.push_back(pair<int, int>(start, route));
			dfs(G[start][i].first, G[start][i].second);
			if (root != start && route != G[start][i].second)temp_path.pop_back();
		}
	}
	visited[start] = 0;
}
int main()
{
	//input
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> subway[i][j];
			if (j != 0)
			{
				G[subway[i][j]].push_back(pair<int, int>(subway[i][j - 1], i));
				G[subway[i][j - 1]].push_back(pair<int, int>(subway[i][j], i));
			}
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> req[i][0] >> req[i][1];
	//calculate
	for (int i = 0; i < K; i++)
	{
		temp_path.clear();
		path.clear();
		root = req[i][0];
		des = req[i][1];
		memset(visited, 0, sizeof(visited));
		dfs(root, 0);
		sort(path.begin(), path.end(), cmp);
		cout << getlength(path[0]) << endl;
		for (int j = 0; j < path[0].size(); j++)
		{
			if (!j)
			{
				if (j != path[0].size() - 1 || i != K - 1)
					cout << "Take Line#" << path[0][j].second << " from " << printnum(root) << " to " << printnum(path[0][j].first) << "." << endl;
				else
					cout << "Take Line#" << path[0][j].second << " from " << printnum(root) << " to " << printnum(path[0][j].first) << ".";
			}
			else
			{
				if (j != path[0].size() - 1 || i != K - 1)
					cout << "Take Line#" << path[0][j].second << " from " << printnum(path[0][j - 1].first) << " to " << printnum(path[0][j].first) << "." << endl;
				else
					cout << "Take Line#" << path[0][j].second << " from " << printnum(path[0][j - 1].first) << " to " << printnum(path[0][j].first) << ".";
			}
		}
	}
}
*/

//1076: BFS
/*
#include<iostream>
#include<string.h>
#include<vector>
#include<deque>
using namespace std;
int N, L, K;
vector<int>followers[1005];
int req[1005];
int visited[1005];
int bfs(int start)
{
	int level = 0, top, total = 0, cur = 1, next = 0;
	deque<int>Q;
	Q.push_back(start);
	visited[start] = 1;
	while (level != L && !Q.empty())
	{
		top = Q[0];
		for (int i = 0; i < followers[top].size(); i++)
		{
			if (!visited[followers[top][i]])
			{
				Q.push_back(followers[top][i]);
				visited[followers[top][i]] = 1;
				total++;
				next++;
			}
		}
		Q.pop_front();
		cur--;
		if (cur == 0)
		{
			level++;
			cur += next;
			next = 0;
		}
	}
	return total;
}
int main()
{
	int num, temp;
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> temp;
			followers[temp].push_back(i);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> req[i];
	for (int i = 0; i < K; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (i != K - 1)
			cout << bfs(req[i]) << endl;
		else
			cout << bfs(req[i]);
	}
}*/

//1091: BFS
/*
#include<iostream>
#include<unordered_map>
#include<deque>
using namespace std;
int M, N, L, T, volume = 0, pixel = 0;
int G[1300][130][60];
unordered_map<int, int>visited;
void bfs(int start)
{
	int cnt = 0;
	deque<int>Q;
	Q.push_back(start);
	visited[start] = 1;
	while (!Q.empty())
	{
		int x, y, z;
		z = Q[0] / (M * N);
		x = (Q[0] - z * M * N) / N;
		y = Q[0] - z * M * N - x * N;
		pixel++;
		if (x > 0 && G[x - 1][y][z] && !visited[(x - 1) * N + y + z * M * N])
		{
			visited[(x - 1) * N + y + z * M * N] = 1;
			Q.push_back((x - 1) * N + y + z * M * N);
		}
		if (x < M - 1 && G[x + 1][y][z] && !visited[(x + 1) * N + y + z * M * N])
		{
			visited[(x + 1) * N + y + z * M * N] = 1;
			Q.push_back((x + 1) * N + y + z * M * N);
		}

		if (y > 0 && G[x][y - 1][z] && !visited[x * N + y - 1 + z * M * N])
		{
			visited[x * N + y - 1 + z * M * N] = 1;
			Q.push_back(x * N + y - 1 + z * M * N);
		}
		if (y < N - 1 && G[x][y + 1][z] && !visited[x * N + y + 1 + z * M * N])
		{
			visited[x * N + y + 1 + z * M * N] = 1;
			Q.push_back(x * N + y + 1 + z * M * N);
		}

		if (z > 0 && G[x][y][z - 1] && !visited[x * N + y + (z - 1) * M * N])
		{
			visited[x * N + y + (z - 1) * M * N] = 1;
			Q.push_back(x * N + y + (z - 1) * M * N);
		}
		if (z < L - 1 && G[x][y][z + 1] && !visited[x * N + y + (z + 1) * M * N])
		{
			visited[x * N + y + (z + 1) * M * N] = 1;
			Q.push_back(x * N + y + (z + 1) * M * N);
		}
		Q.pop_front();
		cnt++;
	}
	if (cnt >= T)volume += cnt;
}
int main()
{
	cin >> M >> N >> L >> T;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
			{
				cin >> G[j][k][i];
				if (G[j][k][i])
					visited[k + j * N + i * M * N] = 0;
			}
	while (pixel != visited.size())
	{
		for (auto p = visited.begin(); p != visited.end(); p++)
		{
			if (!p->second)
			{
				bfs(p->first);
				//break;
			}
		}
	}
	cout << volume;
}*/

//1053: DFS
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, S, cur;
vector<vector<int>>path;
vector<int>temp_path;
int tree[105][105];
int weight[105];
bool cmp(vector<int>a, vector<int>b)
{
	int i;
	for (i = 0; i < a.size() && i < b.size(); i++)
	{
		if (a[i] > b[i])
			return true;
		if (a[i] < b[i])
			return false;
	}
	if (i == a.size())
		return false;
	if (i == b.size())
		return true;
	return false;
}
void dfs(int start)
{
	cur += weight[start];
	temp_path.push_back(weight[start]);
	if (cur == S)
	{
		if (tree[start][0] == 0)
			path.push_back(temp_path);
		temp_path.pop_back();
		cur -= weight[start];
		return;
	}
	for (int i = 0; tree[start][i] != 0; i++)
	{
		dfs(tree[start][i]);
	}
	cur -= weight[start];
	temp_path.pop_back();
}
int main()
{
	int id, k;
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	for (int i = 0; i < M; i++)
	{
		cin >> id >> k;
		for (int j = 0; j < k; j++)
			cin >> tree[id][j];
	}
	dfs(0);
	sort(path.begin(), path.end(), cmp);
	for (int i = 0; i < path.size(); i++)
	{
		for (int j = 0; j < path[i].size(); j++)
			if (j != path[i].size() - 1)
				cout << path[i][j] << " ";
			else if (i != path.size() - 1)
				cout << path[i][j] << endl;
			else
				cout << path[i][j];

	}
}*/

//1079: BFS
/*
#include<iostream>
#include<deque>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;
int N;
double P, r, price = 0;
vector<int>tree[100005];
void bfs()
{
	int level = 0, cur = 1, next = 0;
	deque<int>Q;
	Q.push_back(0);
	while (!Q.empty())
	{
		if (tree[Q[0]][0] == 0)
			price += pow(1 + r / 100, level) * P * tree[Q[0]][1];
		else
		{
			for (int i = 0; i < tree[Q[0]].size(); i++)
			{
				Q.push_back(tree[Q[0]][i]);
				next++;
			}
		}
		Q.pop_front();
		cur--;
		if (cur == 0)
		{
			level++;
			cur = next;
			next = 0;
		}
	}
}
int main()
{
	cin >> N >> P >> r;
	int k, m;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		if (k != 0)
		{
			for (int j = 0; j < k; j++)
			{
				cin >> m;
				tree[i].push_back(m);
			}
		}
		else
		{
			cin >> m;
			tree[i].push_back(0);
			tree[i].push_back(m);
		}
	}
	bfs();
	cout << setiosflags(ios::fixed) << setprecision(1) << price;
}*/

//1090: BFS
/*
#include<iostream>
#include<deque>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;
int N, num = 0;
double P, r, price = 0, max_level = 0;
vector<int>tree[100005];
vector<int>root;
void bfs()
{
	deque<int>Q;
	int level = 0, cur = 0, next = 0;
	for (int i = 0; i < root.size(); i++)
	{
		Q.push_back(root[i]);
		cur++;
	}
	while (!Q.empty())
	{
		if (tree[Q[0]].empty())
		{
			if (level != max_level)
			{
				max_level = level;
				num = 0;
			}
			num++;
		}
		for (int i = 0; i < tree[Q[0]].size(); i++)
		{
			Q.push_back(tree[Q[0]][i]);
			next++;
		}
		Q.pop_front();
		cur--;
		if (cur == 0)
		{
			level++;
			cur = next;
			next = 0;
		}
	}
}
int main()
{
	cin >> N >> P >> r;
	int k;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		if (k == -1)
			root.push_back(i);
		else
			tree[k].push_back(i);
	}
	bfs();
	//cout << setiosflags(ios::fixed) << setprecision(2) << pow(1 + r / 100, max_level) * P << " " << setprecision(0) << num;
	printf("%.2f %d", pow(1 + r / 100, max_level) * P, num);
}*/

//1094: BFS
/*
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int N, M, max_num = 1, max_level = 1;
vector<int>tree[105];
void bfs()
{
	deque<int>Q;
	int level = 1, cur = 1, next = 0;
	Q.push_back(1);
	while (!Q.empty())
	{
		for (int i = 0; i < tree[Q[0]].size(); i++)
		{
			Q.push_back(tree[Q[0]][i]);
			next++;
		}
		Q.pop_front();
		cur--;
		if (cur == 0)
		{
			level++;
			cur = next;
			next = 0;
			if (cur > max_num)
			{
				max_num = cur;
				max_level = level;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	int id, k, child;
	for (int i = 0; i < M; i++)
	{
		cin >> id >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> child;
			tree[id].push_back(child);
		}
	}
	bfs();
	cout << max_num << " " << max_level;
}
*/

//1020: 树的遍历
/*
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int N;
int post[35];
int in[35];
vector<int>level;
deque<pair<int, int>>seq;
deque<pair<int, int>>postseq;
void order()
{
	seq.push_back(pair<int, int>(0, N));
	postseq.push_back(pair<int, int>(0, N));
	while (!seq.empty())
	{
		int index, x = seq[0].first, y = seq[0].second, m = postseq[0].first, n = postseq[0].second;
		for (int i = x; i < y; i++)
		{
			if (in[i] == post[n - 1])
			{
				index = i;
				break;
			}
		}
		seq.pop_front();
		postseq.pop_front();
		level.push_back(in[index]);
		if (x != index)
		{
			seq.push_back(pair<int, int>(x, index));
			postseq.push_back(pair<int, int>(m, m + index - x));
		}
		if (index + 1 != y)
		{
			seq.push_back(pair<int, int>(index + 1, y));
			postseq.push_back(pair<int, int>(m + index - x, n - 1));
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> post[i];
	for (int i = 0; i < N; i++)
		cin >> in[i];
	order();
	for (int i = 0; i < N; i++)
		if (i != N - 1)
			cout << level[i] << " ";
		else
			cout << level[i];
}
*/

//1043: 二叉搜索树与树的遍历
/*
#include<iostream>
#include<vector>
using namespace std;
int N, mirror = -1;
int order[1005];
pair<int, int>tree[1005];
vector<int>out;
bool check(int x, int y)
{
	int index = y;
	if (mirror == -1)
	{
		for (int i = x + 2; i < y; i++)
		{
			if (order[i - 1] < order[x] && order[i] >= order[x])
			{
				mirror = 0;
				index = i;
				for (int j = index; j < y; j++)
					if (order[j] < order[x])
						return false;
				break;
			}
			if (order[i - 1] >= order[x] && order[i] < order[x])
			{
				mirror = 1;
				index = i;
				for (int j = index; j < y; j++)
					if (order[j] >= order[x])
						return false;
				break;
			}
		}
	}
	if (mirror == 0)
	{
		for (int i = x + 1; i < y; i++)
		{
			if (order[i] >= order[x])
			{
				index = i;
				for (int j = index + 1; j < y; j++)
					if (order[j] < order[x])
						return false;
				break;
			}
		}
	}
	if (mirror == 1)
	{
		for (int i = x + 1; i < y; i++)
		{
			if (order[i] < order[x])
			{
				index = i;
				for (int j = index + 1; j < y; j++)
					if (order[j] >= order[x])
						return false;
				break;
			}
		}
	}
	if (x + 1 < index)
		if (!check(x + 1, index))
			return false;
	if (index < y)
		if (!check(index, y))
			return false;
	return true;
}
void create_tree(int x, int y)
{
	int index = y;
	if (!mirror)
	{
		for (int i = x + 1; i < y; i++)
		{
			if (order[i] >= order[x])
			{
				index = i;
				break;
			}
		}
		if (x + 1 != index)
		{
			tree[x].first = x + 1;
			create_tree(x + 1, index);
		}
		else
			tree[x].first = -1;
		if (index < y)
		{
			tree[x].second = index;
			create_tree(index, y);
		}
		else
			tree[x].second = -1;
	}
	else
	{
		for (int i = x + 1; i < y; i++)
		{
			if (order[i] < order[x])
			{
				index = i;
				break;
			}
		}
		if (x + 1 != index)
		{
			tree[x].first = x + 1;
			create_tree(x + 1, index);
		}
		else
			tree[x].first = -1;
		if (index < y)
		{
			tree[x].second = index;
			create_tree(index, y);
		}
		else
			tree[x].second = -1;
	}
}
void travel(int root)
{
	if (tree[root].first != -1)travel(tree[root].first);
	if (tree[root].second != -1)travel(tree[root].second);
	out.push_back(order[root]);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> order[i];
	if (check(0, N))
	{
		cout << "YES" << endl;
		create_tree(0, N);
		travel(0);
		for (int i = 0; i < N; i++)
			if (i != N - 1)
				cout << out[i] << " ";
			else
				cout << out[i];
	}
	else
		cout << "NO";
}
*/

//1064: 完全BST
/*
#include<iostream>
#include<vector>
#include<deque>
#include<math.h>
#include<algorithm>
using namespace std;
int N;
vector<int>seq, res;
int log2(int x)
{
	int i;
	for (i = 0;; i++)
		if (pow(2, i) <= x && pow(2, i + 1) > x)
			break;
	return i;
}
void create_tree()
{
	deque<pair<int, int>>Q;
	Q.push_back(pair<int, int>(0, N));
	while (!Q.empty())
	{
		int x = Q[0].first, y = Q[0].second;
		int level = log2(y - x + 1);
		int num = y - x - pow(2, level) + 1 - pow(2, level - 1), cnt, root;
		if (num > 0)
			cnt = pow(2, level - 1) - 1 + num;
		else
			cnt = pow(2, level - 1) - 1;
		root = y - cnt - 1;
		res.push_back(seq[root]);
		Q.pop_front();
		if (x < root)Q.push_back(pair<int, int>(x, root));
		if (root + 1 < y)Q.push_back(pair<int, int>(root + 1, y));
	}
}
int main()
{
	int t;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		seq.push_back(t);
	}
	sort(seq.begin(), seq.end());
	create_tree();
	for (int i = 0; i < N; i++)
		if (i != N - 1)
			cout << res[i] << " ";
		else
			cout << res[i];
}*/

//1066: AVL tree
/*
#include<iostream>
using namespace std;
int N;
int seq[20];
class node
{
public:
	int key;
	node* left, * right;
	node() { key = 0; left = right = 0; }
};
node* tree = 0;
node* L(node* root)
{
	node* t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node* R(node* root)
{
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node* LR(node* root)
{
	root->left = L(root->left);
	return R(root);
}
node* RL(node* root)
{
	root->right = R(root->right);
	return L(root);
}
int getHeight(node* root)
{
	if (root == 0)return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node* insert(node* root, int x)
{
	if (root == 0)
	{
		root = new node();
		root->key = x;
	}
	else if (x < root->key)
	{
		root->left = insert(root->left, x);
		if (getHeight(root->left) - getHeight(root->right) == 2)
		{
			if (x < root->left->key)
				root = R(root);
			else
				root = LR(root);
		}
	}
	else
	{
		root->right = insert(root->right, x);
		if (getHeight(root->right) - getHeight(root->left) == 2)
		{
			if (x < root->right->key)
				root = RL(root);
			else
				root = L(root);
		}
	}
	return root;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
		tree = insert(tree, seq[i]);
	}
	cout << tree->key;
}*/

//1086: 树的遍历
/*
#include<iostream>
#include<vector>
using namespace std;
vector<int>order;
class node
{
public:
	int val;
	node* left, * right, * father;
	node() { val = 0; left = right = father = 0; }
};
int N, position;
node* tree, * cur, * pre;
void insert(int x)
{
	cur = new node();
	cur->val = x;
	if (pre != 0)
	{
		cur->father = pre;
		if (position)pre->right = cur;
		else pre->left = cur;
	}
	pre = cur;
	cur = cur->left;
	position = 0;
}
void postorder(node* temp)
{
	if (temp == 0)return;
	postorder(temp->left);
	postorder(temp->right);
	order.push_back(temp->val);
}
int main()
{
	string str;
	int num;
	cin >> N;
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> str;
		if (str == "Push")
		{
			cin >> num;
			insert(num);
			if (i == 0)tree = pre;
		}
		else
		{
			while (pre->right != 0 || position)
			{
				pre = pre->father;
				position = 0;
			}
			cur = pre->right;
			position = 1;
		}
	}
	postorder(tree);
	for (int i = 0; i < order.size(); i++)
		if (i != 0)
			cout << " " << order[i];
		else
			cout << order[i];
}*/

//1099: BST
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
int N;
vector<int>seq, output;
pair<int, int>tree[100];
int value[100];
int getChild(int root)
{
	if (root == -1)return 0;
	return getChild(tree[root].second) + getChild(tree[root].first) + 1;
}
void make_tree(int x, int y, int root)
{
	int bigger = getChild(tree[root].second);
	value[root] = seq[y - 1 - bigger];
	if (tree[root].first != -1)make_tree(x, y - 1 - bigger, tree[root].first);
	if (tree[root].second != -1)make_tree(y - bigger, y, tree[root].second);
}
void levelorder()
{
	deque<int>Q;
	Q.push_back(0);
	while (!Q.empty())
	{
		output.push_back(value[Q[0]]);
		if (tree[Q[0]].first != -1)Q.push_back(tree[Q[0]].first);
		if (tree[Q[0]].second != -1)Q.push_back(tree[Q[0]].second);
		Q.pop_front();
	}
}
int main()
{
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> tree[i].first >> tree[i].second;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		seq.push_back(temp);
	}
	sort(seq.begin(), seq.end());
	make_tree(0, N, 0);
	levelorder();
	for (int i = 0; i < N; i++)
		if (i != N - 1)
			cout << output[i] << " ";
		else
			cout << output[i];
}*/

//1110: 完全二叉树
/*
#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std;
int N, root = -1, iscomplete = 1;
pair<int, int>tree[20];
vector<int>output;
void levelorder()
{
	deque<int>Q;
	Q.push_back(root);
	while (!Q.empty())
	{
		if (tree[Q[0]].first != -1)Q.push_back(tree[Q[0]].first);
		if (tree[Q[0]].second != -1)Q.push_back(tree[Q[0]].second);
		output.push_back(Q[0]);
		if (output.back() != root)
		{
			int index = output.size() - 1;
			if (index % 2 == 0)
			{
				int father = output[(index - 2) / 2];
				if (tree[father].second != output.back())
				{
					iscomplete = 0;
					return;
				}
			}
			else
			{
				int father = output[(index - 1) / 2];
				if (tree[father].first != output.back())
				{
					iscomplete = 0;
					return;
				}
			}
		}
		Q.pop_front();
	}
}
int main()
{
	int a[20] = { 0 };
	cin >> N;
	string str1, str2;
	for (int i = 0; i < N; i++)
	{
		cin >> str1 >> str2;
		if (str1 == "-")
			tree[i].first = -1;
		else
			tree[i].first = atoi(str1.c_str());

		if (str2 == "-")
			tree[i].second = -1;
		else
			tree[i].second = atoi(str2.c_str());
	}
	for (int i = 0; i < N; i++)
	{
		if (tree[i].first != -1)a[tree[i].first] = 1;
		if (tree[i].second != -1)a[tree[i].second] = 1;
	}
	for(int i=0;i<N;i++)
		if (a[i] == 0)
		{
			root = i;
			break;
		}
	levelorder();
	if (iscomplete)
		cout << "YES " << output.back();
	else
		cout << "NO " << output[0];
}*/

//1115: BST
/*
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int N;
int seq[1005];
vector<int>levelnum;
class node
{
public:
	int val;
	node* left, * right;
	node() { val = 0; left = right = 0; }
};
node* tree;
node* insert(node* root, int x)
{
	if (root == 0)
	{
		root = new node();
		root->val = x;
	}
	else if (x <= root->val)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);
	return root;
}
void levelorder()
{
	deque<node*>Q;
	int cur = 1, next = 0;
	Q.push_back(tree);
	levelnum.push_back(cur);
	while (!Q.empty())
	{
		node* top = Q[0];
		if (top->left != 0)
		{
			Q.push_back(top->left);
			next++;
		}
		if (top->right != 0)
		{
			Q.push_back(top->right);
			next++;
		}
		Q.pop_front();
		cur--;
		if (cur == 0)
		{
			cur = next;
			next = 0;
			levelnum.push_back(cur);
		}
	}
	levelnum.pop_back();
}
int main()
{
	int n1, n2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
		tree = insert(tree, seq[i]);
	}
	levelorder();
	n1 = levelnum.back();
	n2 = levelnum[levelnum.size() - 2];
	cout << n1 << " + " << n2 << " = " << n1 + n2;
}*/

//1119: 树的遍历
/*
#include<iostream>
#include<vector>
using namespace std;
int N, unique = 1;
int preorder[35];
int postorder[35];
vector<int>output;
class node
{
public:
	int val;
	node* left, * right;
	node() { val = 0; left = right = 0; }
};
node* tree;
void make_tree(node*& root, pair<int, int>p1, pair<int, int>p2)
{
	if (p1.first >= p1.second)return;
	int index = p2.first;
	root = new node();
	root->val = preorder[p1.first];
	if (p1.first + 1 < p1.second)
	{
		for (int i = p2.first; i < p2.second - 1; i++)
			if (postorder[i] == preorder[p1.first + 1])
			{
				index = i;
				break;
			}
		if (index == p2.second - 2)
			unique = 0;
		make_tree(root->left, pair<int, int>(p1.first + 1, p1.first + index - p2.first + 2), pair<int, int>(p2.first, index + 1));
		make_tree(root->right, pair<int, int>(p1.first + index - p2.first + 2, p1.second), pair<int, int>(index + 1, p2.second - 1));
	}
}
void inorder(node* root)
{
	if (root == 0)return;
	inorder(root->left);
	output.push_back(root->val);
	inorder(root->right);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> preorder[i];
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	make_tree(tree, pair<int, int>(0, N), pair<int, int>(0, N));
	inorder(tree);
	if (unique)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < N; i++)
		if (i != N - 1)
			cout << output[i] << " ";
		else
			cout << output[i] << endl;
}*/

//1127: 树的遍历
/*
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int N;
int postorder[35], inorder[35];
vector<int>levelorder, output;
vector<int>levelnum;
class node
{
public:
	int val;
	node* left, * right;
	node() { val = 0; left = right = 0; }
};
node* tree;
void maketree(node*& root, pair<int, int>in, pair<int, int>post)
{
	if (in.first == in.second)return;
	root = new node();
	root->val = postorder[post.second - 1];
	if (in.first + 1 < in.second)
	{
		int index;
		for (int i = in.first; i < in.second; i++)
		{
			if (inorder[i] == postorder[post.second - 1])
			{
				index = i;
				break;
			}
		}
		if (in.first < index)maketree(root->left, pair<int, int>(in.first, index), pair<int, int>(post.first, post.first + index - in.first));
		if (index + 1 < in.second)maketree(root->right, pair<int, int>(index + 1, in.second), pair<int, int>(post.first + index - in.first, post.second - 1));
	}
}
void zigzag()
{
	deque<node*>Q;
	int cur = 1, next = 0;
	levelnum.push_back(cur);
	Q.push_back(tree);
	while (!Q.empty())
	{
		node* top = Q[0];
		if (top->left != 0)
		{
			Q.push_back(top->left);
			next++;
		}
		if (top->right != 0)
		{
			Q.push_back(top->right);
			next++;
		}
		levelorder.push_back(top->val);
		Q.pop_front();
		cur--;
		if (cur == 0)
		{
			cur = next;
			next = 0;
			levelnum.push_back(cur);
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	maketree(tree, pair<int, int>(0, N), pair<int, int>(0, N));
	zigzag();
	int j = 0;
	for (int i = 0; i < levelnum.size(); i++)
	{
		if (i % 2 != 0)
		{
			int k = j;
			while (j < k + levelnum[i])
			{
				output.push_back(levelorder[j]);
				j++;
			}
		}
		else
		{
			int k = j + levelnum[i] - 1;
			while (k >= j)
			{
				output.push_back(levelorder[k]);
				k--;
			}
			j = j + levelnum[i];
		}
	}
	for (int i = 0; i < N; i++)
		if (i != N - 1)
			cout << output[i] << " ";
		else
			cout << output[i];
}*/

//1135: 红黑树
/*
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int K;
int pre[35];
vector<int>output;
class node
{
public:
	int val;
	int color;
	node* left, * right;
	node() { val = color = 0; left = right = 0; }
};
node* tree;
node* nil = new node();
void maketree(node*& root, int x, int y)
{
	//if (x == y)return;
	root = new node();
	root->val = abs(pre[x]);
	if (pre[x] < 0)root->color = 1;
	if (x + 1 < y)
	{
		int index = y;
		for (int i = x; i < y; i++)
		{
			if (abs(pre[i]) > abs(pre[x]))
			{
				index = i;
				break;
			}
		}
		if (x + 1 < index)maketree(root->left, x + 1, index);
		else root->left = nil;
		if (index < y)maketree(root->right, index, y);
		else root->right = nil;
	}
	else
	{
		root->left = root->right = nil;
	}
}
void insert(node*& root, int val)
{
	if (root == nil)
	{
		root = new node();
		root->val = abs(val);
		root->left = root->right = nil;
		if (val < 0)root->color = 1;
	}
	else if (root->val < abs(val))
		insert(root->left, val);
	else
		insert(root->right, val);
}
int leafnum = -1;
bool check1(node* root, int num)
{
	if (root->color == 0)num++;
	if (root == nil)
	{
		if (leafnum == -1)
			leafnum = num;
		else if (leafnum != num)
			return false;
		return true;
	}
	//if (root->color)
	//{
	//	if (root->left->color || root->right->color)
	//		return false;
	//}
	if ((!check1(root->left, num)) || (!check1(root->right, num)))
		return false;
	return true;
}
bool check2(node* root)
{
	if (root == nil)return true;
	else if (root->color == 1 && (root->left->color == 1 || root->right->color == 1))return false;
	return check2(root->left) && check2(root->right);
}
int main()
{
	int N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		tree = nil;
		memset(pre, 0, sizeof(pre));
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> pre[j];
			insert(tree, pre[j]);
		}
		//maketree(tree, 0, N);
		if (tree->color == 0 && check1(tree, 0) && check2(tree))output.push_back(1);
		else output.push_back(0);
	}
	for (int i = 0; i < K; i++)
	{
		if (i != K - 1)
			if (output[i])cout << "Yes" << endl;
			else cout << "No" << endl;
		else
			if (output[i])cout << "Yes";
			else cout << "No";
	}
}*/

//1147: 二叉堆
/*
#include<iostream>
#include<vector>
using namespace std;
int M, N, heap = 0;
vector<int>order;
class node
{
public:
	int val;
	node* left, * right;
	node(int c) { left = right = 0; val = c; }
};
node* seq[105][1005];
void maketree(int a)
{
	for (int i = 0; i < N; i++)
	{
		if (2 * i + 1 < N)
			seq[a][i]->left = seq[a][2 * i + 1];
		if (2 * i + 2 < N)
			seq[a][i]->right = seq[a][2 * i + 2];
	}
}
void postorder(node* root)
{
	if (root->left != 0)
	{ 
		if (heap == 0)
		{
			if (root->val > root->left->val)heap = 1;
			else if (root->val < root->left->val)heap = 2;
		}
		if (heap == 1 && root->val < root->left->val)
			heap = -1;
		if (heap == 2 && root->val > root->left->val)
			heap = -1;
		postorder(root->left);
	}
	if (root->right != 0)
	{
		if (heap == 0)
		{
			if (root->val > root->right->val)heap = 1;
			else if (root->val < root->right->val)heap = 2;
		}
		if (heap == 1 && root->val < root->right->val)
			heap = -1;
		if (heap == 2 && root->val > root->right->val)
			heap = -1;
		postorder(root->right);
	}
	order.push_back(root->val);
}
int main()
{
	int t;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			seq[i][j] = new node(t);
		}
	for (int i = 0; i < M; i++)
	{
		heap = 0;
		order.clear();
		maketree(i);
		postorder(seq[i][0]);
		switch (heap)
		{
		case -1:
			cout << "Not Heap" << endl;
			break;
		case 1:
			cout << "Max Heap" << endl;
			break;
		case 2:
			cout << "Min Heap" << endl;
			break;
		}
		for (int j = 0; j < N; j++)
			if (j != N - 1)cout << order[j] << " ";
			else if (i != M - 1)cout << order[j] << endl;
			else cout << order[j];
	}
}
*/

//1151: 树的遍历
/*
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int M, N, u, v, pu, pv;
int inorder[10005], preorder[10005];
int test[1005][2];
map<int, int>pos;

void search(int inx, int iny, int prex, int prey)
{
	int find = 0, value = preorder[prex], root = pos[value];
	if (value == u)
	{
		cout << u << " is an ancestor of " << v << "." << endl;
		return;
	}
	if (value == v)
	{
		cout << v << " is an ancestor of " << u << "." << endl;
		return;
	}
	if (pu < root && pv < root)
	{
		search(inx, root, prex + 1, prex + 1 + root - inx);
	}
	if (pu > root && pv > root)
	{
		search(root + 1, iny, prey - iny + root + 1, prey);
	}
	if ((pu > root && pv < root) || (pu<root && pv>root))
	{
		cout << "LCA of " << u << " and " << v << " is " << value << "." << endl;
		return;
	}
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> inorder[i];
		pos[inorder[i]] = i;
	}
	for (int i = 0; i < N; i++)
		cin >> preorder[i];
	for (int i = 0; i < M; i++)
		cin >> test[i][0] >> test[i][1];
	//maketree(tree, 0, 0, N, 0, N);
	for (int i = 0; i < M; i++)
	{
		u = test[i][0];
		v = test[i][1];
		auto U = pos.find(u), V = pos.find(v);
		if (U == pos.end() && V == pos.end())
			cout << "ERROR: " << test[i][0] << " and " << test[i][1] << " are not found." << endl;
		else if (U == pos.end())
			cout << "ERROR: " << test[i][0] << " is not found." << endl;
		else if (V == pos.end())
			cout << "ERROR: " << test[i][1] << " is not found." << endl;
		else
		{
			pu = pos[u];
			pv = pos[v];
			search(0, N, 0, N);
		}
	}
}*/

