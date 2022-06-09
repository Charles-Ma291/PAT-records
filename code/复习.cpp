/*1040：动态规划*/
//#include<iostream>
//#include<string>
//using namespace std;
//int dp[1001][1001];
//int main()
//{
//	string s;
//	getline(cin, s);
//	int length = s.size(), max_size = 1;
//	for (int i = length - 1; i >= 0; i--)
//	{
//		for (int j = i; j < length; j++)
//		{
//			if (i == j)dp[i][j] = 1;
//			else if ((j - i == 1 && s[i] == s[j]))
//			{
//				dp[i][j] = 1;
//				if (max_size < 2)max_size = 2;
//			}
//			else if (j - i > 1 && s[i] == s[j])
//			{
//				dp[i][j] = dp[i + 1][j - 1];
//				if (dp[i][j] && max_size < j - i + 1)max_size = j - i + 1;
//			}
//		}
//	}
//	cout << max_size;
//}

/*1068: 动态规划*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N, M;
//int dp[10001][101];
//int need[10001][101];
//vector<int>c, ans;
//int main()
//{
//	cin >> N >> M;
//	c.resize(N + 1);
//	for (int i = 1; i <= N; i++)
//		cin >> c[i];
//	sort(c.begin() + 1, c.end(), greater<int>());
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= M; j++)
//		{
//			if (c[i] <= j)
//			{
//				if (dp[i - 1][j] <= dp[i - 1][j - c[i]] + c[i])
//				{
//					dp[i][j] = dp[i - 1][j - c[i]] + c[i];
//					need[i][j] = 1;
//				}
//				else
//					dp[i][j] = dp[i - 1][j];
//			}
//		}
//	}
//	if (dp[N][M] == M)
//	{
//		int n = N, m = M;
//		while (n > 0)
//		{
//			if (need[n][m])
//			{
//				ans.push_back(c[n]);
//				m -= c[n];
//			}
//			n--;
//		}
//		for (int i = 0; i < ans.size(); i++)
//			if (i != ans.size() - 1)
//				cout << ans[i] << " ";
//			else cout << ans[i];
//	}
//	else cout << "No Solution";
//}

/*1101: 排序*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//int n[100002];
//int maxn[100002], minn[100002];
//vector<int>ans;
//int main()
//{
//	cin >> N;
//	minn[N + 1] = 0x3fffffff;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> n[i];
//		if (n[i] > maxn[i - 1])maxn[i] = n[i];
//		else maxn[i] = maxn[i - 1];
//		minn[i] = 0x3fffffff;
//	}
//	for (int i = N; i > 0; i--)
//	{
//		if (n[i] < minn[i + 1])minn[i] = n[i];
//		else minn[i] = minn[i + 1];
//		if (n[i] > maxn[i - 1] && n[i] < minn[i + 1])ans.push_back(n[i]);
//	}
//	sort(ans.begin(), ans.end());
//	cout << ans.size() << endl;
//	for (int i = 0; i < ans.size(); i++)
//		if (i != ans.size() - 1)cout << ans[i] << " ";
//		else cout << ans[i];
//	cout << endl;
//}

/*1044: 二分查找*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M, minc = 0x3fffffff;
//int d[100001];
//int sum[100001];
//int check[2001];
//vector<pair<int, int>>ans;
//int cmp(pair<int, int>a, pair<int, int>b) { return a.first < b.first; }
//void getChain(int x, int y)
//{
//	int left = x, right = y;
//	int r = (left + right) / 2;
//	while (left < right)
//	{
//		if (sum[r] - sum[x - 1] >= M)
//			right = r;
//		else left = r + 1;
//		r = (left + right) / 2;
//	}
//	if (sum[r] - sum[x - 1] >= M && sum[r] - sum[x - 1] <= minc)
//	{
//		if (sum[r] - sum[x - 1] < minc)
//		{
//			ans.clear();
//			minc = sum[r] - sum[x - 1];
//		}
//		ans.push_back(pair<int, int>(x, r));
//	}
//}
//int main()
//{
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> d[i];
//		sum[i] = sum[i - 1] + d[i];
//	}
//	for (int i = 1; i <= N; i++)
//		getChain(i, N);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i].first << "-" << ans[i].second << endl;
//	}
//}

/*模拟考试1.1*/
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//int N, M;
//int n[101][10001], f[101][10001];
//map<int, int>c[101];
//vector<pair<int, int>>fake[101];
//vector<pair<int,int>>s;
//int cmp(pair<int, int>a, pair<int, int>b) { return a.second < b.second; }
//int main()
//{
//	cin >> N >> M;
//	s.resize(N + 1);
//	for (int i = 0; i < M; i++)
//	{
//		pair<int, int>t;
//		for (int j = 1; j <= N; j++)
//		{
//			if (i == 0)s[j].first = j;
//			cin >> n[i][j];
//			if (c[i].find(n[i][j]) != c[i].end())
//			{
//				f[i][c[i][n[i][j]]]++;
//				f[i][j]++;
//			}
//			else
//				c[i][n[i][j]] = j;
//		}
//		for (int j = 1; j <= N; j++)
//		{
//			t.first = j;
//			t.second = f[i][j];
//			fake[i].push_back(t);
//		}
//		sort(fake[i].begin(), fake[i].end(), cmp);
//		for (int j = N-1; j >= 0; j--)
//		{
//			if (j != N-1 && fake[i][j].second != fake[i][j + 1].second)break;
//			s[fake[i][j].first].second++;
//		}
//	}
//	sort(s.begin(), s.end(), cmp);
//	cout << s[N-1].first;
//}

/*1.2*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class node
//{
//public:
//	int data;
//	node* next;
//};
//int N;
//node* tail;
//node n[100000];
//vector<int>res;
//int Rank[100000];
//int main()
//{
//	int t;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> t;
//		n[i].data = i;
//		if (t == -1)
//			tail = &n[i];
//		else
//			n[t].next = &n[i];
//	}
//	node* p = tail;
//	int num = N;
//	while (p != 0)
//	{
//		Rank[p->data] = num;
//		num--;
//		p = p->next;
//	}
//	for (int i = 0; i < N; i++)
//		if (i != N - 1)cout << Rank[i] << " ";
//		else cout << Rank[i];
//}

/*1.3*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M;
//int num[100001];
//vector<int>s[100001];
//vector<int>querys;
//int bfs(int x)
//{
//	int n = 1;
//	for (int i = 0; i < s[x].size(); i++)
//	{
//		if (num[s[x][i]] == 0)num[s[x][i]] = bfs(s[x][i]);
//		n += num[s[x][i]];
//	}
//	return n;
//}
//int main()
//{
//	int t;
//	cin >> N;
//	for (int i = 2; i <= N; i++)
//	{
//		cin >> t;
//		s[t].push_back(i);
//	}
//	cin >> M;
//	querys.resize(M);
//	for (int i = 0; i < M; i++)
//		cin >> querys[i];
//	for (int i = 0; i < M; i++)
//		cout << bfs(querys[i]) << endl;
//}

/*1.4*/
#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<string.h>
//using namespace std;
//int N, M, s_time, K;
//int p[1001][3];
//int h[101][1001];
//int init[1001];
//int dic[1001][1001];
//vector<pair<int, int>>G[1001];//表示到达的地方和花销
//int findRoad(int a, int b)
//{
//	int dis[1001], visited[1001] = { 0 };
//	memcpy(dis, init, sizeof(dis));
//	for (int i = 0; i < G[a].size(); i++)
//		dis[G[a][i].first] = G[a][i].second;
//	int cur = a;
//	visited[a] = 1;
//	while (1)
//	{
//		int mind = 0x3fffffff, index;
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && dis[i] < mind)
//			{
//				mind = dis[i];
//				index = i;
//			}
//		}
//		visited[index] = 1;
//		dic[a][index] = dis[index];
//		if (index == b)break;
//		for (int i = 0; i < G[index].size(); i++)
//		{
//			if (dis[index] + G[index][i].second < dis[G[index][i].first])
//				dis[G[index][i].first] = dis[index] + G[index][i].second;
//		}
//		cur = index;
//	}
//	return dis[b];
//}
//int main()
//{
//	int a, b, c;
//	int mm, hh;
//	scanf("%d %d %d:%d", &N, &M, &hh, &mm);
//	s_time = hh * 60 + mm;
//	init[0] = 0x3fffffff;
//	for (int i = 1; i <= N; i++)
//	{
//		scanf("%d:%d %d %d", &hh, &mm, &p[i][1], &p[i][2]);
//		p[i][0] = hh * 60 + mm;
//		init[i] = 0x3fffffff;
//	}
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		G[a].push_back(pair<int, int>(b, c));
//		G[b].push_back(pair<int, int>(a, c));
//	}
//	cin >> K;
//	int maxr = 0, mtime;
//	for (int i = 0; i < K; i++)
//	{
//		int ctime = s_time, rew = 0;
//		int visited[1001] = { 0 }, flag = 1;
//		for (int j = 0; j < N; j++)
//			cin >> h[i][j];
//		for (int j = 0; j < N; j++)
//		{
//			if (visited[h[i][j]] || h[i][j] > N || h[i][j] == 0)
//			{
//				flag = 0;
//				break;
//			}
//			if (j == 0)
//			{
//				if (dic[0][h[i][j]] == 0)dic[0][h[i][j]] = findRoad(0, h[i][j]);
//				ctime += dic[0][h[i][j]];
//				rew += p[h[i][j]][1];
//				if (ctime > p[h[i][j]][0])rew -= p[h[i][j]][2];
//				visited[h[i][j]] = 1;
//			}
//			else
//			{
//				if (dic[h[i][j - 1]][h[i][j]] == 0)dic[h[i][j - 1]][h[i][j]] = findRoad(h[i][j - 1], h[i][j]);
//				ctime += dic[h[i][j - 1]][h[i][j]];
//				rew += p[h[i][j]][1];
//				if (ctime > p[h[i][j]][0])rew -= p[h[i][j]][2];
//				visited[h[i][j]] = 1;
//			}
//		}
//		if (flag)
//		{
//			if (dic[0][h[i][N - 1]] == 0)dic[0][h[i][N - 1]] = findRoad(0, h[i][N - 1]);
//			ctime += dic[0][h[i][N - 1]];
//			if (rew > maxr)
//			{
//				maxr = rew;
//				mtime = ctime;
//			}
//			else if (rew == maxr && ctime < mtime)
//				mtime = ctime;
//		}
//	}
//	hh = mtime / 60;
//	mm = mtime - hh * 60;
//	printf("%d %02d:%02d", maxr, hh, mm);
//}

/*1.1 超时，改用unorder map*/
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//int ans[10001];
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int f[10001], minn = 0x2fffffff;
//		unordered_map<int, int>m;
//		for (int j = 1; j <= N; j++)
//		{
//			cin >> f[j];
//			m[f[j]]++;
//		}
//		for (auto j : m)
//			if (j.second < minn)
//				minn = j.second;
//		for (int j = 1; j <= N; j++)
//			if (m[f[j]] == minn)ans[j]++;
//	}
//	int maxn = 0, index;
//	for (int i = 1; i <= N; i++)
//	{
//		if (ans[i] > maxn)
//		{
//			maxn = ans[i];
//			index = i;
//		}
//	}
//	cout << index;
//}

/*1.4 怀疑是dijstra算法写错了*/


/*1018：最短路径*/

/*还是考虑的少了，没有用dfs，最后有一个测试点过不去，经检验不用dfs确实不行*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int C, N, P, M;
//vector<int>G[505];
//int edge[505][505];
//int bike[505], send[505], take[505];
//int dis[505], visited[505], path[505];
//void dijsktra(int x)
//{
//	for (int i = 1; i <= N; i++)
//	{
//		if (edge[0][i] != 0)
//		{
//			dis[i] = edge[0][i];
//			path[i] = 0;
//			if (C / 2 >= bike[i])send[i] = C / 2 - bike[i];
//			else take[i] = bike[i] - C / 2;
//		}
//		else dis[i] = send[i] = 0x3fffffff;
//	}
//	int cur = 0;
//	visited[0] = 1;
//	while (cur != x)
//	{
//		int mind = 0x3fffffff, index;
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && dis[i] < mind)
//			{
//				mind = dis[i];
//				index = i;
//			}
//		}
//		visited[index] = 1;
//		for (int i = 0; i < G[index].size(); i++)
//		{
//			int to = G[index][i];
//			if (dis[index] + edge[index][to] < dis[to])
//			{
//				dis[to] = dis[index] + edge[index][to];
//				path[to] = index;
//				if (bike[to] >= C / 2)
//				{
//					send[to] = send[index];
//					take[to] = take[index] + bike[to] - C / 2;
//				}
//				else if (bike[to] + take[index] >= C / 2)
//				{
//					send[to] = send[index];
//					take[to] = take[index] - C / 2 + bike[to];
//				}
//				else
//				{
//					send[to] = send[index] + C / 2 - bike[to] - take[index];
//					take[to] = 0;
//				}
//			}
//			else if (dis[index] + edge[index][to] == dis[to])
//			{
//				int s;
//				if (bike[to] >= C / 2)
//				{
//					s = send[index];
//					if (s < send[to])
//					{
//						send[to] = s;
//						take[to] = take[index] + bike[to] - C / 2;
//						path[to] = index;
//					}
//					else if (s == send[to] && take[index] + bike[to] - C / 2 < take[to])
//					{
//						take[to] = take[index] + bike[to] - C / 2;
//						path[to] = index;
//					}
//				}
//				else if (bike[to] + take[index] >= C / 2)
//				{
//					s = send[index];
//					if (s < send[to])
//					{
//						send[to] = s;
//						take[to] = take[index] - C / 2 + bike[to];
//						path[to] = index;
//					}
//					else if (s == send[to] && take[index] - C / 2 + bike[to] < take[to])
//					{
//						take[to] = take[index] - C / 2 + bike[to];
//						path[to] = index;
//					}
//				}
//				else
//				{
//					s = send[index] + C / 2 - bike[to] - take[index];
//					if (s < send[to])
//					{
//						send[to] = s;
//						take[to] = 0;
//						path[to] = index;
//					}
//				}
//			}
//		}
//		cur = index;
//	}
//}
//int main()
//{
//	vector<int>road;
//	int a, b, c;
//	cin >> C >> N >> P >> M;
//	for (int i = 1; i <= N; i++)
//		cin >> bike[i];
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		G[a].push_back(b);
//		G[b].push_back(a);
//		edge[a][b] = edge[b][a] = c;
//	}
//	dijsktra(P);
//	cout << send[P] << " 0";
//	for (int i = P; i != 0;)
//	{
//		road.push_back(i);
//		i = path[i];
//	}
//	for (int i = road.size() - 1; i >= 0; i--)
//		cout << "->" << road[i];
//	cout << " " << take[P];
//}

/*改用dfs*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int C, N, P, M;
//vector<int>G[505];
//int edge[505][505];
//int bike[505];
//vector<int>path[505];
//vector<int>ans, temp;
//int send = 0x3fffffff, take = 0x3fffffff;
//void dijsktra()
//{
//	int visited[505] = { 0 }, dis[505];
//	for (int i = 1; i <= N; i++)
//		if (edge[0][i] != 0)
//		{
//			dis[i] = edge[0][i];
//			path[i].push_back(0);
//		}
//		else dis[i] = 0x3fffffff;
//	int cur = 0;
//	visited[0] = 1;
//	while (cur != P)
//	{
//		int mind = 0x3fffffff, index;
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && dis[i] < mind)
//			{
//				mind = dis[i];
//				index = i;
//			}
//		}
//		visited[index] = 1;
//		for (int i = 0; i < G[index].size(); i++)
//		{
//			int n = G[index][i];
//			if (!visited[n] && dis[index] + edge[index][n] <= dis[n])
//			{
//				if (dis[index] + edge[index][n] < dis[n])
//				{
//					dis[n] = dis[index] + edge[index][n];
//					path[n].clear();
//				}
//				path[n].push_back(index);
//			}
//		}
//		cur = index;
//	}
//}
//void dfs(int curr)
//{
//	if (curr == 0)
//	{
//		int s = 0, t = 0;
//		for (int i = temp.size() - 1; i >= 0; i--)
//		{
//			if (bike[temp[i]] >= C / 2)
//				t += bike[temp[i]] - C / 2;
//			else
//			{
//				if (bike[temp[i]] + t >= C / 2)
//					t -= C / 2 - bike[temp[i]];
//				else
//				{
//					s += C / 2 - bike[temp[i]] - t;
//					t = 0;
//				}
//			}
//		}
//		if (s < send)
//		{
//			ans = temp;
//			send = s;
//			take = t;
//		}
//		else if (s == send && t < take)
//		{
//			ans = temp;
//			take = t;
//		}
//		return;
//	}
//	temp.push_back(curr);
//	for (int i = 0; i < path[curr].size(); i++)
//		dfs(path[curr][i]);
//	temp.pop_back();
//}
//int main()
//{
//	int a, b, c;
//	cin >> C >> N >> P >> M;
//	for (int i = 1; i <= N; i++)
//		cin >> bike[i];
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		G[a].push_back(b);
//		G[b].push_back(a);
//		edge[a][b] = edge[b][a] = c;
//	}
//	dijsktra();
//	dfs(P);
//	cout << send << " 0";
//	for (int i = ans.size() - 1; i >= 0; i--)
//	{
//		cout << "->" << ans[i];
//	}
//	cout << " " << take;
//}

/*Floyd实现*/
//#include<iostream>
//using namespace std;
//int N, M;
//int path[100][100], dis[100][100];
//int main()
//{
//	int a, b, c;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		dis[a][b] = c;
//		path[a][b] = b;
//	}
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (i != j && dis[i][j] == 0)
//				dis[i][j] = 0x3fffffff;
//	for(int k=0;k<N;k++)
//		for(int i=0;i<N;i++)
//			for (int j = 0; j < N; j++)
//			{
//				if (dis[i][j] > dis[i][k] + dis[k][j])
//				{
//					dis[i][j] = dis[i][k] + dis[k][j];
//					path[i][j] = k;
//				}
//			}
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			printf("%2d", path[i][j]);
//		cout << endl;
//	}
//}

/*模拟考试2.1*/
//#include<iostream>
//using namespace std;
//int N, K;
//int arr[10001][2];
//int c[10001];
//int q[1001];
//int getIndex(int x)
//{
//	int left = 0, right = N - 1;
//	int mid;
//	while (left < right)
//	{
//		mid = (left + right) / 2;
//		if (c[mid] > x)right = mid;
//		else left = mid + 1;
//	}
//	return left;
//}
//int main()
//{
//	int maxa = 0;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> arr[i][0] >> arr[i][1];
//		if (i == 0)c[i] = arr[i][1];
//		else c[i] = c[i - 1] + arr[i][1];
//	}
//	for (int i = 0; i < K; i++)
//		cin >> q[i];
//	for (int i = 0; i < K; i++)
//	{
//		if (q[i] < 0 || q[i] >= c[N - 1])cout << "Illegal Access" << endl;
//		else
//		{
//			int index = getIndex(q[i]);
//			if (index > maxa)maxa = index;
//			if (index != 0)cout << arr[index][0] + (q[i] - c[index - 1]) * 4 << endl;
//			else cout << arr[index][0] + q[i] * 4 << endl;
//		}
//	}
//	cout << maxa + 1;
//}

/*2.2*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//int r[10001];
//vector<pair<int, int>>h, p;
//int cmp(pair<int, int>a, pair<int, int>b) { return a.second > b.second; }
//int main()
//{
//	cin >> N;
//	h.resize(N);
//	p.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> h[i].second;
//		h[i].first = N - i;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cin >> p[i].second;
//		p[i].first = i + 1;
//	}
//	sort(h.begin(), h.end(), cmp);
//	sort(p.begin(), p.end(), cmp);
//	for (int i = 0; i < N; i++)
//	{
//		r[h[i].first] = p[i].first;
//	}
//	for (int i = 1; i <= N; i++)
//		if (i != N)cout << r[i] << " ";
//		else cout << r[i];
//}

/*2.3*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M;
//vector<int>G[101];
//int edge[101][101];
//int main()
//{
//	int a, b, maxn = 0, index;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		G[a].push_back(b);
//		G[b].push_back(a);
//		edge[a][b] = edge[b][a] = 1;
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		int n = 1, curr = i;
//		int visited[101] = { 0 };
//		while (1)
//		{
//			int next = 0x3fffffff;
//			visited[curr] = 1;
//			for (int j = 0; j < G[curr].size(); j++)
//			{
//				if (!visited[G[curr][j]] && G[curr][j] < next)
//					next = G[curr][j];
//			}
//			if (next == 0x3fffffff)break;
//			curr = next;
//			n++;
//		}
//		if (n > maxn)
//		{
//			maxn = n;
//			index = i;
//		}
//	}
//	cout << index << " " << maxn;
//}

/*2.4*/
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//int N;
//class node
//{
//public:
//	int key, pri;
//	node* left, * right;
//};
//node* tree;
//vector<node>n, ans;
//void levelorder()
//{
//	node* top;
//	queue<node*>Q;
//	Q.push(tree);
//	while (!Q.empty())
//	{
//		top = Q.front();
//		ans.push_back(*top);
//		if (top->left != 0)Q.push(top->left);
//		if (top->right != 0)Q.push(top->right);
//		Q.pop();
//	}
//}
//node* findRoot(int a, int b)
//{
//	if (a > b)return NULL;
//	node* p;
//	int mini = 0x3fffffff, index;
//	for (int i = a; i <= b; i++)
//	{
//		if (n[i].pri < mini)
//		{
//			mini = n[i].pri;
//			index = i;
//		}
//	}
//	p = &n[index];
//	p->left = findRoot(a, index - 1);
//	p->right = findRoot(index + 1, b);
//	return p;
//}
//int cmp(node a, node b) { return a.key < b.key; }
//int main()
//{
//	cin >> N;
//	n.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> n[i].key >> n[i].pri;
//	sort(n.begin(), n.end(), cmp);
//	tree = findRoot(0, N - 1);
//
//	levelorder();
//	for (int i = 0; i < ans.size(); i++)
//		if (i != ans.size() - 1)cout << ans[i].key << " ";
//		else cout << ans[i].key << endl;
//	for (int i = 0; i < ans.size(); i++)
//		if (i != ans.size() - 1)cout << ans[i].pri << " ";
//		else cout << ans[i].pri << endl;
//
//}

/*二分查找下标一定要谨慎*/
//#include<iostream>
//using namespace std;
//int N, K;
//int c[10001];
//int arr[10001];
//int querys[1001];
//int findNum(int x)
//{
//	int left = 1, right = N;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (c[mid] <= x)left = mid + 1;
//		else right = mid - 1;
//	}
//	return left;
//}
//int main()
//{
//	int t;
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> arr[i] >> t;
//		c[i] = c[i - 1] + t;
//	}
//	for (int i = 0; i < K; i++)
//		cin >> querys[i];
//	int maxn = 0;
//	for (int i = 0; i < K; i++)
//	{
//		if (querys[i] < 0 || querys[i] >= c[N])
//			cout << "Illegal Access" << endl;
//		else
//		{
//			int index = findNum(querys[i]);
//			if (index > maxn)maxn = index;
//			cout << arr[index] + (querys[i] - c[index - 1]) * 4 << endl;
//		}
//	}
//	cout << maxn;
//}

/*1107: 并查集*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//int hobby[1001];
//int father[1001];
//int closter[1001];
//vector<pair<int, vector<int>>>ans;
//vector<int>members[1001];
//int findFather(int x)
//{
//	int c = x, a = -1;
//	while (c != a)
//	{
//		a = c;
//		c = father[c];
//	}
//	return c;
//}
//void Union(int a, int b)
//{
//	int fa = findFather(a), fb = findFather(b);
//	if (fa != fb)father[fa] = fb;
//}
//int cmp(pair<int, vector<int>>a, pair<int, vector<int>>b) { return a.first > b.first; }
//int main()
//{
//	cin >> N;
//	int n, h;
//	for (int i = 1; i <= N; i++)
//	{
//		scanf("%d: ", &n);
//		father[i] = i;
//		for (int j = 0; j < n; j++)
//		{
//			cin >> h;
//			if (hobby[h] == 0)hobby[h] = i;
//			else
//				Union(i, hobby[h]);
//		}
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		int f = findFather(i);
//		closter[f]++;
//		members[f].push_back(i);
//	}
//	for (int i = 1; i <= N; i++)
//		if (closter[i] != 0)ans.push_back(pair<int, vector<int>>(closter[i], members[i]));
//	sort(ans.begin(), ans.end(), cmp);
//	cout << ans.size() << endl;
//	for (int i = 0; i < ans.size(); i++)
//		if (i != ans.size() - 1)cout << ans[i].first << " ";
//		else cout << ans[i].first << endl;
//	for (int i = 0; i < ans.size(); i++)
//	{
//		for (int j = 0; j < ans[i].second.size(); j++)
//		{
//			if (j != ans[i].second.size() - 1)cout << ans[i].second[j] << " ";
//			else cout << ans[i].second[j] << endl;
//		}
//	}
//}
//

/*模拟考试3.1*/
//#include<iostream>
//using namespace std;
//int N;
//int f[40];
//void calculate(int x)
//{
//	if (x == 0 || x == 1)f[x] = 1;
//	else f[x] = f[x - 1] + f[x - 2];
//}
//int findNum()
//{
//	int left = 0, right = 39;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (f[mid] == N)return f[mid];
//		if (right - left == 1)
//		{
//			if (f[right] - N < N - f[left])
//				return f[right];
//			else return f[left];
//		}
//		if (f[mid] < N)left = mid;
//		if (f[mid] > N)right = mid;
//	}
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < 40; i++)calculate(i);
//	cout << findNum();
//}

/*3.2*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	string S, P;
//	int length = 0x3fffffff, a, b;
//	cin >> S >> P;
//	int k = 0;
//	for (int i = 0; i < S.size(); i++)
//	{
//		k = 0;
//		for (int j = i; j < S.size() && j - i + 1 < length; j++)
//		{
//			if (S[j] == P[k])
//				k++;
//			if (k == P.size())
//			{
//				a = i;
//				b = j;
//				length = j - i + 1;
//			}
//		}
//	}
//	for (int i = a; i <= b; i++)
//		cout << S[i];
//}

/*3.3*/
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int N, K;
//int querys[100];
//class node
//{
//public:
//	int id;
//	node* father;
//};
//vector<node*>nodes[1001];
//node* dic[10001];
//int main()
//{
//	vector<int>path;
//	cin >> N;
//	cin.get();
//	string n;
//	for (int i = 0; i < N; i++)
//	{
//		getline(cin, n);
//		node* t = new node();
//		t->id = atoi(n.c_str());
//		dic[t->id] = t;
//		if (i == 0)nodes[i].push_back(t);
//		else
//		{
//			int d = n.size() - 4;
//			nodes[d].push_back(t);
//			t->father = nodes[d - 1].back();
//		}
//	}
//	cin >> K;
//	for (int i = 0; i < K; i++)
//		cin >> querys[i];
//	for (int i = 0; i < K; i++)
//	{
//		path.clear();
//		node* p = dic[querys[i]];
//		if (p != 0)
//		{
//			while (p->id != 0)
//			{
//				path.push_back(p->id);
//				p = p->father;
//			}
//			cout << "0000";
//			for (int j = path.size() - 1; j >= 0; j--)
//				printf("->%04d", path[j]);
//			cout << endl;
//		}
//		else printf("Error: %04d is not found.\n", querys[i]);
//	}
//}

/*3.4*/
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<string>
//using namespace std;
//int N, M, K;
//map<int, int>order;
//vector<pair<vector<int>, int>>eq, ans, temp;
//int dic[100], pro[100], rea[100];
//int visited[100];
//int cmp(pair<vector<int>, int>a, pair<vector<int>, int>b)
//{
//	if (order[a.second] < order[b.second])return 1;
//	else if (order[a.second] == order[b.second])
//	{
//		int i;
//		for (i = 0; i < a.first.size() && i < b.first.size(); i++)
//		{
//			if (a.first[i] < b.first[i])return 1;
//			if (a.first[i] > b.first[i])return 0;
//		}
//		if (i == a.first.size())return 1;
//		else return 0;
//	}
//	else return 0;
//}
//int findEq(int x)
//{
//	int ende;
//	if (x == M)return 1;
//	if (x != M - 1)ende = dic[pro[x + 1]];
//	else ende = eq.size();
//	for (int i = dic[pro[x]]; i < ende; i++)
//	{
//		int flag = 1;
//		for (int k = 0; k < eq[i].first.size(); k++)
//		{
//			if (visited[eq[i].first[k]])
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//		{
//			temp.push_back(eq[i]);
//			for (int k = 0; k < eq[i].first.size(); k++)
//				visited[eq[i].first[k]] = 1;
//			if (findEq(x + 1))return 1;
//			temp.pop_back();
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int t;
//	string e;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> t;
//		rea[t] = 1;
//	}
//	cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> t;
//		pro[i] = t;
//		order[t] = i + 1;
//		if (rea[t])
//		{
//			vector<int>* r = new vector<int>();
//			r->push_back(t);
//			eq.push_back(pair<vector<int>, int>(*r, t));
//		}
//	}
//	cin >> K;
//	cin.get();
//	for (int i = 0; i < K; i++)
//	{
//		getline(cin, e);
//		int j = 0;
//		vector<int>* r = new vector<int>();
//		while (j < e.size() - 2)
//		{
//			if (e[j] >= '0' && e[j] <= '9')
//			{
//				r->push_back(e[j + 1] - '0' + (e[j] - '0') * 10);
//				j++;
//			}
//			j++;
//		}
//		eq.push_back(pair<vector<int>, int>(*r, (e[j] - '0') * 10 + e[j + 1] - '0'));
//	}
//	sort(eq.begin(), eq.end(), cmp);
//	for (int i = 0; i < eq.size(); i++)
//	{
//		if (dic[eq[i].second] == 0)dic[eq[i].second] = i;
//	}
//	dic[eq[0].second] = 0;
//	if(!findEq(0))return 0;
//	for (int i = 0; i < temp.size(); i++)
//	{
//		for (int j = 0; j < temp[i].first.size(); j++)
//		{
//			if (j != temp[i].first.size() - 1)printf("%02d + ", temp[i].first[j]);
//			else printf("%02d -> ", temp[i].first[j]);
//		}
//		printf("%02d\n", temp[i].second);
//	}
//}

