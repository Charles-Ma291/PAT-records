//PART2: 最短路径

//1003

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n, m, c1, c2;
//	cin >> n >> m >> c1 >> c2;
//	int res[1000];
//	int num[1000];
//	for (int i = 0; i < n; i++)
//		cin >> res[i];
//	int** road = new int*[m];
//	for (int i = 0; i < m; i++)
//	{
//		road[i] = new int[3];
//		cin >> road[i][0] >> road[i][1] >> road[i][2];
//	}
//	//初始化数组
//	int* dis = new int[n];
//	int* team = new int[n];
//	bool* minimize = new bool[n];
//	for (int i = 0; i < n; i++) 
//	{
//		dis[i] = 0x3fffffff; 
//		minimize[i] = false;
//		team[i] = 0;
//		num[i] = 0;
//	}
//	team[c1] = res[c1];
//	for (int i = 0; i < m; i++)
//	{
//		if (road[i][0] == c1)
//		{
//			dis[road[i][1]] = road[i][2];
//			team[road[i][1]] = team[c1] + res[road[i][1]];
//			num[road[i][1]] = 1;
//		}
//		if (road[i][1] == c1)
//		{
//			dis[road[i][0]] = road[i][2];
//			team[road[i][0]] = team[c1] + res[road[i][0]];
//			num[road[i][0]] = 1;
//		}
//	}
//	dis[c1] = 0;
//	minimize[c1] = true; num[c1] = 1;
//	int times = 0;
//	while (times < n - 1)
//	{
//		int min = 0x3fffffff, index = -1;
//		for (int i = 0; i < n; i++)
//		{
//			if (!minimize[i] && dis[i] < min)
//			{
//				min = dis[i];
//				index = i;
//			}
//		}
//		minimize[index] = true;
//		//松弛过程
//		for (int i = 0; i < m; i++)
//		{
//			if (road[i][0] == index && !minimize[road[i][1]])
//			{
//				if (dis[index] + road[i][2] < dis[road[i][1]])
//				{
//					dis[road[i][1]] = dis[index] + road[i][2];
//					team[road[i][1]] = team[index] + res[road[i][1]];
//					num[road[i][1]] = num[index];
//				}
//				else if (dis[index] + road[i][2] == dis[road[i][1]])
//				{
//					if (team[road[i][1]] < team[index] + res[road[i][1]])
//						team[road[i][1]] = team[index] + res[road[i][1]];
//					num[road[i][1]] += num[index];
//				}
//			}
//
//			if (road[i][1] == index && !minimize[road[i][0]])
//			{
//				if (dis[index] + road[i][2] < dis[road[i][0]])
//				{
//					dis[road[i][0]] = dis[index] + road[i][2];
//					team[road[i][0]] = team[index] + res[road[i][0]];
//					num[road[i][0]] = num[index];
//				}
//				else if (dis[index] + road[i][2] == dis[road[i][0]])
//				{
//					if (team[road[i][0]] < team[index] + res[road[i][0]])
//						team[road[i][0]] = team[index] + res[road[i][0]];
//					num[road[i][0]] += num[index];
//				}
//			}
//		}
//		times++;
//	}
//	cout << num[c2] << " " << team[c2];
//}


//1018：双重权重+dfs+路径
/*错误代码，未能debug*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class node
//{
//public:
//	int id;
//	node* father[501];
//	int size;
//	node()
//	{
//		id = 0;
//		size = 0;
//	}
//	void clear()
//	{
//		size = 0;
//	}
//	void push_back(node* p)
//	{
//		father[size] = p;
//		size++;
//	}
//};
//int C, N, P, M;
//int v[501], dis[501] = { 0 }, visited[501] = { 0 };
//int** e = new int* [M];
//node* road[501];
////void get_bike(int index, node* father, int& sent, int& recv)
////{
////	if (v[index] - C / 2 > 0)
////	{
////		sent = bike[father->id][0];
////		recv = bike[father->id][1] + v[index] - C / 2;
////	}
////	else if (C / 2 - v[index] <= bike[father->id][1])
////	{
////		sent = bike[father->id][0];
////		recv = bike[father->id][1] - C / 2 + v[index];
////	}
////	else
////	{
////		sent = bike[father->id][0] - v[index] + C / 2 - bike[father->id][1];
////		recv = 0;
////	}
////}
//void Dijsktra()
//{
//	int time = 0;
//	while (time < N)
//	{
//		int min = 0x3fffffff, index = -1;
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && dis[i] < min)
//			{
//				min = dis[i];
//				index = i;
//			}
//		}
//		visited[index] = 1;
//		for (int i = 0; i < M; i++)
//		{
//			if (e[i][0] == index && !visited[e[i][1]])
//			{
//				if (dis[index] + e[i][2] < dis[e[i][1]])
//				{
//					road[e[i][1]]->clear();
//					road[e[i][1]]->push_back(road[index]);
//					dis[e[i][1]] = dis[index] + e[i][2];
//				}
//				else if (dis[index] + e[i][2] == dis[e[i][1]])
//					road[e[i][1]]->push_back(road[index]);
//			}
//
//			if (e[i][1] == index && !visited[e[i][0]])
//			{
//				if (dis[index] + e[i][2] < dis[e[i][0]])
//				{
//					road[e[i][0]]->clear();
//					road[e[i][0]]->push_back(road[index]);
//					dis[e[i][0]] = dis[index] + e[i][2];
//				}
//				else if (dis[index] + e[i][2] == dis[e[i][0]])
//					road[e[i][0]]->push_back(road[index]);
//			}
//		}
//		time++;
//	}
//}
//int sent1 = 0x3fffffff, recv1 = 0x3fffffff;
//vector<node*>min_path, cur_path;
//void DFS()
//{
//	int visited[501] = { 0 };
//	while (!cur_path.empty())
//	{
//		int pop = 1;
//		node* p = cur_path.back();
//		for (int i = visited[p->id]; i < p->size; i++)
//		{
//			cur_path.push_back(p->father[i]);
//			cout << cur_path.back()->id << " ";
//			visited[p->id]++;
//			pop = 0;
//			break;
//		}
//		if (cur_path.back()->id == 0||pop)
//		{
//			//for (int i = 0; i < cur_path.back()->size; i++)
//			//	visited[cur_path.back()->father[i]->id] = 0;
//			if (cur_path.back()->id == 0)
//			{
//				int sent2 = 0, recv2 = 0;
//				for (int i = cur_path.size() - 2; i >= 0; i--)
//				{
//					if (v[cur_path[i]->id] - C / 2 >= 0)
//					{
//						recv2 += v[cur_path[i]->id] - C / 2;
//					}
//					else if (C / 2 - v[cur_path[i]->id] <= recv2)
//					{
//						recv2 -= C / 2 - v[cur_path[i]->id];
//					}
//					else
//					{
//						sent2 += C / 2 - v[cur_path[i]->id] - recv2;
//						recv2 = 0;
//					}
//					//cout << recv2 << " ";
//				}
//				//cout << endl;
//				if (sent2 < sent1 || (sent2 == sent1 && recv2 < recv1))
//				{
//					min_path = cur_path;
//					recv1 = recv2;
//					sent1 = sent2;
//				}
//			}
//			cur_path.pop_back();
//			if(!cur_path.empty())cout << cur_path.back()->id << " ";
//		}
//	}
//}
//int main()
//{
//	cin >> C >> N >> P >> M;
//	for (int i = 0; i < 501; i++)
//		road[i] = new node();
//	road[0]->id = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		dis[i] = 0x3fffffff;
//		road[i]->id = i;
//		cin >> v[i];
//	}
//	for (int i = 0; i < M; i++)
//	{
//		e[i] = new int[3];
//		cin >> e[i][0] >> e[i][1] >> e[i][2];
//	}
//	//init
//	for (int i = 0; i < M; i++)
//	{
//		if (e[i][0] == 0)
//		{
//			dis[e[i][1]] = e[i][2];
//			road[e[i][1]]->push_back(road[0]);
//		}
//	}
//	dis[0] = 0;
//	visited[0] = 1;
//	cur_path.push_back(road[P]);
//	Dijsktra();
//	DFS();
//	cout << "size is:" << min_path.size() << endl;
//	cout << sent1 << " " << min_path.back()->id;
//	for (int i = min_path.size() - 2; i >= 0; i--)
//	{
//		cout << "->" << min_path[i]->id;
//	}
//	cout << " " << recv1;
//}
////int main()
////{
////	cin >> C >> N >> P >> M;
////	for (int i = 0; i < 501; i++)
////		road[i] = new node();
////	road[0]->id = 0;
////	for (int i = 1; i <= N; i++)
////	{
////		dis[i] = 0x3fffffff;
////		road[i]->id = i;
////		cin >> v[i];
////	}
////	for (int i = 0; i < M; i++)
////	{
////		e[i] = new int[3];
////		cin >> e[i][0] >> e[i][1] >> e[i][2];
////	}
////	//init
////	for (int i = 0; i < M; i++)
////	{
////		if (e[i][0] == 0)
////		{
////			dis[e[i][1]] = e[i][2];
////			road[e[i][1]]->father = road[0];
////			get_bike(e[i][1], road[0], bike[e[i][1]][0], bike[e[i][1]][1]);
////		}
////	}
////	dis[0] = 0;
////	visited[0] = 1;
////	int time = 0;
////	while (time < N)
////	{
////		int min = 0x3fffffff, index = -1;
////		for (int i = 1; i <= N; i++)
////		{
////			if (!visited[i] && dis[i] < min)
////			{
////				min = dis[i];
////				index = i;
////			}
////		}
////		visited[index] = 1;
////		//update bike
////		get_bike(index, road[index]->father, bike[index][0], bike[index][1]);
////		for (int i = 0; i < M; i++)
////		{
////			if (e[i][0] == index && !visited[e[i][1]])
////			{
////				if (dis[index] + e[i][2] < dis[e[i][1]])
////				{
////					dis[e[i][1]] = dis[index] + e[i][2];
////					road[e[i][1]]->father = road[e[i][0]];
////					//update bike
////					get_bike(e[i][1], road[e[i][0]], bike[e[i][1]][0], bike[e[i][1]][1]);
////				}
////				else if (dis[index] + e[i][2] == dis[e[i][1]])
////				{
////					int sent1, recv1, sent2, recv2;
////					sent1 = bike[e[i][1]][0];
////					recv1 = bike[e[i][1]][1];
////					get_bike(e[i][1], road[e[i][0]], sent2, recv2);
////					if (sent2 < sent1 || (sent2 == sent1 && recv2 < recv1))
////					{
////						road[e[i][1]]->father = road[e[i][0]];
////						//update bike
////						get_bike(e[i][1], road[e[i][0]], bike[e[i][1]][0], bike[e[i][1]][1]);
////					}
////				}
////			}
////			if (e[i][1] == index && !visited[e[i][0]])
////			{
////				if (dis[index] + e[i][2] < dis[e[i][0]])
////				{
////					dis[e[i][0]] = dis[index] + e[i][2];
////					road[e[i][0]]->father = road[e[i][1]];
////					//update bike
////					get_bike(e[i][0], road[e[i][1]], bike[e[i][0]][0], bike[e[i][0]][1]);
////				}
////				else if (dis[index] + e[i][2] == dis[e[i][0]])
////				{
////					int sent1, recv1, sent2, recv2;
////					sent1 = bike[e[i][0]][0];
////					recv1 = bike[e[i][0]][1];
////					get_bike(e[i][0], road[e[i][1]], sent2, recv2);
////					if (sent2 < sent1 || (sent2 == sent1 && recv2 < recv1))
////					{
////						road[e[i][0]]->father = road[e[i][1]];
////						//update bike
////						get_bike(e[i][0], road[e[i][1]], bike[e[i][0]][0], bike[e[i][0]][1]);
////					}
////				}
////			}
////		}
////		time++;
////	}
////	vector<int>path;
////	cout << bike[P][0] << " ";
////	node* p = road[P];
////	path.push_back(P);
////	while (p->id != 0)
////	{
////		p = p->father;
////		path.push_back(p->id);
////	}
////	cout << path.back();
////	for (int i = path.size() - 2; i >= 0; i--)
////	{
////		cout << "->" << path[i];
////	}
////	cout << " " << bike[P][1];
////}

/*ans*/
//#include<iostream>
//#include<vector>
//using namespace std;
//const int maxn = 505, inf = 0x3fffffff;
//int C, N, P, M;
//int curweight[maxn];
//int visited[maxn];
//int G[maxn][maxn];
//int dis[maxn];
//vector<int> pre[maxn];
//void Dijkstra()
//{
//	for (int i = 0; i <= N; ++i)
//	{
//		int u, udist, mindist = inf;
//		for (int j = 0; j <= N; ++j)//寻找最短距离 
//		{
//			if (!visited[j] && dis[j] < mindist)
//			{
//				u = j;
//				udist = mindist = dis[j];
//			}
//		}
//		visited[u] = true;
//		for (int v = 0; v <= N; ++v)
//		{
//			if (!visited[v] && G[u][v])
//			{
//				if (dis[u] + G[u][v] < dis[v])
//				{
//					dis[v] = dis[u] + G[u][v];
//					pre[v].clear();
//					pre[v].push_back(u);
//				}
//				else if (dis[u] + G[u][v] == dis[v])
//				{
//					pre[v].push_back(u);
//				}
//			}
//		}
//	}
//}
//bool flag;
//vector<int>optpath, temppath;
//int optsent = inf, optback = inf;
//void dfs(int v)
//{
//	if (v == 0)
//	{
//		temppath.push_back(v);
//		int tempneed = 0, tempremain = 0;
//		for (int i = temppath.size() - 1; i >= 0; i--)
//		{
//			int id = temppath[i];
//			if (curweight[id] > 0)
//				tempremain += curweight[id];
//			else
//			{
//				int absW = curweight[id] * -1;
//				if (tempremain > absW)//手上的足以补足 
//				{
//					tempremain += curweight[id];
//				}
//				else//不足以补足，需要从起点带 
//				{
//					tempneed += absW - tempremain;
//					tempremain = 0;
//				}
//			}
//		}
//		if (tempneed < optsent)//首先选择往外带最少的 
//		{
//			optpath = temppath;
//			optsent = tempneed;
//			optback = tempremain;
//		}
//		else if (tempneed == optsent)
//		{
//
//			if (tempremain < optback)//比较往回拿最少的
//			{
//				optpath = temppath;
//				optback = tempremain;
//			}
//		}
//		temppath.pop_back();
//		return;
//	}
//	temppath.push_back(v);
//	for (int i = 0; i < pre[v].size(); i++)
//		dfs(pre[v][i]);
//	temppath.pop_back();
//}
//int main(int argc, char* argv[]) {
//	cin >> C >> N >> P >> M;
//	for (int i = 1; i <= N; ++i)
//		cin >> curweight[i];
//	for (int i = 0; i < M; ++i)
//	{
//		int s1, s2, t;
//		cin >> s1 >> s2 >> t;
//		G[s1][s2] = G[s2][s1] = t;
//	}
//	//初始化 
//	for (int i = 0; i <= N; ++i)//下标从0到N 
//	{
//		dis[i] = inf;
//		if (i > 0)
//			curweight[i] -= C / 2;//把每个站点的点权都减去Cmax/2 
//	}
//	dis[0] = 0;
//	Dijkstra();
//	dfs(P);
//	cout << optsent << " ";
//	for (int i = optpath.size() - 1; i >= 0; i--)
//	{
//		cout << optpath[i];
//		if (i > 0)
//			cout<<"->";
//		else
//			cout<<" ";
//	}
//	cout << optback;
//	return 0;
//}

//1030：双重权重+记录路径
/*
#include<iostream>
#include<vector>
using namespace std;
int** G;
int visited[505] = { 0 };
int dis[505];
int cost[505];
int road[505];
int N, M, S, D;
int main()
{
	cin >> N >> M >> S >> D;
	G = new int* [M];
	for (int i = 0; i < N; i++)
	{
		road[i] = -1;
		dis[i] = cost[i] = 0x3f3f3f3f;
	}
	for (int i = 0; i < M; i++)
	{
		G[i] = new int[4];
		cin >> G[i][0] >> G[i][1] >> G[i][2] >> G[i][3];
		if (G[i][0] == S)
		{
			dis[G[i][1]] = G[i][2];
			cost[G[i][1]] = G[i][3];
			road[G[i][1]] = S;
		}
		if (G[i][1] == S)
		{
			dis[G[i][0]] = G[i][2];
			cost[G[i][0]] = G[i][3];
			road[G[i][0]] = S;
		}
	}
	dis[S] = cost[S] = 0;
	visited[S] = 1;
	//cout << dis[1];
	//dijsktra
	int time = 0;
	while (time < N)
	{
		int min = 0x3f3f3f3f, index = -1;
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && dis[i] < min)
			{
				min = dis[i];
				index = i;
			}
		}
		visited[index] = 1;
		//cout << index << " ";
		for (int i = 0; i < M; i++)
		{
			if (G[i][0] == index && !visited[G[i][1]])
			{
				if (G[i][2] + dis[index] < dis[G[i][1]])
				{
					dis[G[i][1]] = G[i][2] + dis[index];
					cost[G[i][1]] = cost[index] + G[i][3];
					road[G[i][1]] = index;
				}
				else if (G[i][2] + dis[index] == dis[G[i][1]] && G[i][3] + cost[index] < cost[G[i][1]])
				{
					cost[G[i][1]] = G[i][3] + cost[index];
					road[G[i][1]] = index;
				}
			}

			if (G[i][1] == index && !visited[G[i][0]])
			{
				if (G[i][2] + dis[index] < dis[G[i][0]])
				{
					dis[G[i][0]] = G[i][2] + dis[index];
					cost[G[i][0]] = cost[index] + G[i][3];
					road[G[i][0]] = index;
				}
				else if (G[i][2] + dis[index] == dis[G[i][0]] && G[i][3] + cost[index] < cost[G[i][0]])
				{
					cost[G[i][0]] = G[i][3] + cost[index];
					road[G[i][0]] = index;
				}
			}

		}
		time++;
	}
	int k = D;
	vector<int>path;
	while (1)
	{
		path.push_back(k);
		if (k == S)
			break;
		k = road[k];
	}
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << dis[D] << " " << cost[D];
}*/

//1072：三重权重
/*
#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
int N, M, K, D;
int** G;
int dis[1020];
int visited[1020];
vector<double*>sol;
int main()
{
	string s1, s2;
	int a, b;
	cin >> N >> M >> K >> D;
	G = new int* [K];
	for (int i = 0; i < K; i++)
	{
		G[i] = new int[3];
		cin >> s1 >> s2;
		if (s1[0] == 'G')
		{
			int index = 1000;
			for (int j = s1.size() - 1; j > 0; j--)
				index += (s1[j] - '0') * pow(10, s1.size() - 1 - j);
			a = index;
		}
		else
			a = atoi(s1.c_str());
		if (s2[0] == 'G')
		{
			int index = 1000;
			for (int j = s2.size() - 1; j > 0; j--)
				index += (s2[j] - '0') * pow(10, s2.size() - 1 - j);
			b = index;
		}
		else
			b = atoi(s2.c_str());
		G[i][0] = a;
		G[i][1] = b;
		cin >> G[i][2];
	}
	for (int i = 0; i < 1020; i++)
	{
		dis[i] = 0x3fffffff;
		visited[i] = 0;
	}
	//Dijsktra * M
	for (int i = 1; i <= M; i++)
	{
		memset(dis, 0, sizeof(dis));
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < 1020; j++)
			dis[j] = 0x3fffffff;
		for (int j = 0; j < K; j++)
		{
			if (G[j][0] == 1000 + i)
				dis[G[j][1]] = G[j][2];
			if (G[j][1] == 1000 + i)
				dis[G[j][0]] = G[j][2];
		}
		visited[1000 + i] = 1;
		int time = 0;
		bool service = true;
		while (time < N)
		{
			int min = 0x3fffffff, index = -1;
			for (int j = 1; j < 1020; j++)
			{
				if (!visited[j] && dis[j] < min)
				{
					min = dis[j];
					index = j;
				}
			}
			visited[index] = 1;
			for (int j = 0; j < K; j++)
			{
				if (G[j][0] == index && !visited[G[j][1]])
				{
					if (G[j][2] + dis[index] < dis[G[j][1]])
						dis[G[j][1]] = G[j][2] + dis[index];
				}
				if (G[j][1] == index && !visited[G[j][0]])
				{
					if (G[j][2] + dis[index] < dis[G[j][0]])
						dis[G[j][0]] = G[j][2] + dis[index];
				}
			}
			time++;
		}
		int mindis = 0x3fffffff;
		double totaldis = 0;
		for (int j = 1; j <= N; j++)
		{
			if (dis[j] > D)
			{
				//cout << "G" << i << " cannot service " << j << endl;
				service = false;
				break;
			}
			if (dis[j] < mindis)
				mindis = dis[j];
			totaldis += dis[j];
		}
		if (service)
		{
			double* p = new double[3];
			p[0] = i;
			p[1] = mindis;
			p[2] = totaldis / N;
			sol.push_back(p);
		}
	}
	if (sol.empty())
		cout << "No Solution";
	else
	{
		//cout << sol.size() << endl;//!
		int index = -1;
		double mindis = 0, avadis = 0x3fffffff;
		for (int i = 0; i < sol.size(); i++)
		{
			if (sol[i][1] > mindis)
			{
				mindis = sol[i][1];
				avadis = sol[i][2];
				index = sol[i][0];
			}
			else if (sol[i][1] == mindis && sol[i][2] < avadis)
			{
				avadis = sol[i][2];
				index = sol[i][0];
			}
			else if (sol[i][1] == mindis && sol[i][2] == avadis && sol[i][0] < index)
				index = sol[i][0];
		}
		cout << 'G' << index << endl;
		cout << setiosflags(ios::fixed) << setprecision(1) << mindis << " ";
		cout << setiosflags(ios::fixed) << setprecision(1) << avadis;
	}
}
*/

//1087：双重权重+记录路径
/*
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N, K;
string S;
map<string, int>city2id;
string id2city[205];
int** G;
int V[205];
int dis[205];
int visited[205];
int happy[205];
int road[205];
int num[205];
int leastcount[205];
int main()
{
	cin >> N >> K >> S;
	G = new int* [K];
	string c1, c2;
	int s;
	for (int i = 0; i < 205; i++)
		dis[i] = 0x3fffffff;
	city2id.insert(pair<string, int>(S, 0));
	id2city[0] = S;
	for (int i = 1; i < N; i++)
	{
		cin >> c1 >> s;
		city2id.insert(pair<string, int>(c1, i));
		id2city[i] = c1;
		V[i] = s;
	}
	for (int i = 0; i < K; i++)
	{
		G[i] = new int[3];
		cin >> c1 >> c2 >> s;
		G[i][0] = city2id[c1];
		G[i][1] = city2id[c2];
		G[i][2] = s;
		if (c1 == S)
		{
			dis[city2id[c2]] = s;
			happy[city2id[c2]] = V[city2id[c2]];
			road[city2id[c2]] = city2id[S];
			num[city2id[c2]]++;
			leastcount[city2id[c2]]++;
		}
		if (c2 == S)
		{
			dis[city2id[c1]] = s;
			happy[city2id[c1]] = V[city2id[c1]];
			road[city2id[c1]] = city2id[S];
			num[city2id[c1]]++;
			leastcount[city2id[c1]]++;
		}
	}
	dis[city2id[S]] = 0;
	visited[city2id[S]] = 1;
	happy[city2id[S]] = 0;
	int time = 0;
	while (time < N)
	{
		int min = 0x3fffffff, index = -1;
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && dis[i] < min)
			{
				min = dis[i];
				index = i;
			}
		}
		visited[index] = 1;
		for (int i = 0; i < K; i++)
		{
			if (G[i][0] == index)
			{
				if (G[i][2] + dis[index] < dis[G[i][1]])
				{
					dis[G[i][1]] = G[i][2] + dis[index];
					road[G[i][1]] = index;
					happy[G[i][1]] = happy[road[G[i][1]]] + V[G[i][1]];
					num[G[i][1]] = num[index] + 1;
					leastcount[G[i][1]] = leastcount[index];
				}
				else if (G[i][2] + dis[index] == dis[G[i][1]])
				{
					leastcount[G[i][1]] += leastcount[index];
					if (happy[index] + V[G[i][1]] > happy[G[i][1]])
					{
						road[G[i][1]] = index;
						happy[G[i][1]] = happy[road[G[i][1]]] + V[G[i][1]];
						num[G[i][1]] = num[index] + 1;
					}
					else if (G[i][2] + dis[index] == dis[G[i][1]] && happy[index] + V[G[i][1]] == happy[G[i][1]] && num[index] + 1 < num[G[i][1]])
					{
						road[G[i][1]] = index;
						num[G[i][1]] = num[index] + 1;
					}
				}
			}
			if (G[i][1] == index)
			{
				if (G[i][2] + dis[index] < dis[G[i][0]])
				{
					dis[G[i][0]] = G[i][2] + dis[index];
					road[G[i][0]] = index;
					happy[G[i][0]] = happy[road[G[i][0]]] + V[G[i][0]];
					num[G[i][0]] = num[index] + 1;
					leastcount[G[i][0]] = leastcount[index];
				}
				else if (G[i][2] + dis[index] == dis[G[i][0]])
				{
					leastcount[G[i][0]] += leastcount[index];
					if (happy[index] + V[G[i][0]] > happy[G[i][0]])
					{
						road[G[i][0]] = index;
						happy[G[i][0]] = happy[road[G[i][0]]] + V[G[i][0]];
						num[G[i][0]] = num[index] + 1;
					}
					else if (G[i][2] + dis[index] == dis[G[i][0]] && happy[index] + V[G[i][0]] == happy[G[i][0]] && num[index] + 1 < num[G[i][0]])
					{
						road[G[i][0]] = index;
						num[G[i][0]] = num[index] + 1;
					}
				}
			}
		}
		time++;
	}
	vector<int>path;
	int p = city2id["ROM"];
	while (1)
	{
		path.push_back(p);
		if (p == city2id[S])
			break;
		p = road[p];
	}
	cout << leastcount[city2id["ROM"]] << " " << dis[city2id["ROM"]] << " " << happy[city2id["ROM"]] << " " << happy[city2id["ROM"]] / num[city2id["ROM"]] << endl;
	for (int i = path.size() - 1; i >= 0; i--)
		if (i == 0)
			cout << id2city[path[i]];
		else
			cout << id2city[path[i]] << "->";
}
*/
