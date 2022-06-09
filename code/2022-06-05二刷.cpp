// 再次学习算法知识，准备6.5的PAT考试
/*1003：最短路径*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M, C1, C2, maxteam = 0, num_path = 0;
//int city_team[505];
//int road[505][505];
//vector<int>father[505];//路径，记录父节点
//void dijsktra()
//{
//	//init
//	bool visited[505] = { 0 };
//	int dis[505];
//	for (int i = 0; i < N; i++)
//	{
//		if (road[C1][i] != 0)
//		{
//			dis[i] = road[C1][i];
//			father[i].push_back(C1);
//		}
//		else dis[i] = 0x3fffffff;
//	}
//	dis[C1] = 0;
//	//每次记录距离源点最短的点V，这就是最短距离
//	visited[C1] = 1;
//	while (!visited[C2])
//	{
//		int index, mindis = 0x3fffffff;
//		for (int i = 0; i < N; i++)
//		{
//			if (!visited[i] && dis[i] < mindis)
//			{
//				mindis = dis[i];
//				index = i;
//			}
//		}
//		visited[index] = 1;
//		for (int i = 0; i < N; i++)
//		{
//			if (road[index][i] != 0)
//			{
//				//如果其他点经由V到源点的距离更短，那么就清空father
//				if (road[index][i] + dis[index] < dis[i])
//				{
//					father[i].clear();
//					father[i].push_back(index);
//					dis[i] = road[index][i] + dis[index];
//				}
//				//如果距离相同，那么添加father
//				else if (road[index][i] + dis[index] == dis[i])
//					father[i].push_back(index);
//			}
//		}
//	}
//}
////深度遍历每条路径并计算最多的team
//void dfs(int team, int city)
//{
//	if (city == C1)
//	{
//		if (team + city_team[city] > maxteam)
//			maxteam = city_team[city] + team;
//		num_path++;
//		return;
//	}
//	for (int i = 0; i < father[city].size(); i++)
//		dfs(team + city_team[city], father[city][i]);
//}
//int main()
//{
//	int a, b, c;
//	cin >> N >> M >> C1 >> C2;
//	for (int i = 0; i < N; i++)
//		cin >> city_team[i];
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		road[a][b] = road[b][a] = c;
//	}
//	dijsktra();
//	dfs(0, C2);
//	cout << num_path << " " << maxteam;
//}

/*1018：最短路径*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int Cmax, N, SP, M;
//int msend = 0x3fffffff, mrecv = 0x3fffffff;
//int bike[505];
//int road[505][505];
//vector<int>father[505];
//vector<int>cpath, path;
//void dijsktra()
//{
//	bool visited[505] = { 0 };
//	int dis[505];
//	for (int i = 1; i <= N; i++)
//	{
//		if (road[0][i] != 0)
//		{
//			dis[i] = road[0][i];
//			father[i].push_back(0);
//		}
//		else dis[i] = 0x3fffffff;
//	}
//	visited[0] = 1;
//	while (!visited[SP])
//	{
//		int index, mindis = 0x3fffffff;
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && dis[i] < mindis)
//			{
//				index = i;
//				mindis = dis[i];
//			}
//		}
//
//		visited[index] = 1;
//		for (int i = 1; i <= N; i++)
//		{
//			if (!visited[i] && road[index][i] != 0)
//			{
//				if (road[index][i] + dis[index] < dis[i])
//				{
//					father[i].clear();
//					father[i].push_back(index);
//					dis[i] = road[index][i] + dis[index];
//				}
//				else if (road[index][i] + dis[index] == dis[i])
//					father[i].push_back(index);
//			}
//		}
//	}
//}
//
//void printpath(vector<int>p)
//{
//	for (int i = p.size() - 1; i >= 0; i--)
//	{
//		if (i != 0)cout << p[i] << "->";
//		else cout << p[i] << " ";
//	}
//}
//
//
//void dfs(int node)
//{
//	cpath.push_back(node);
//	if (node == 0)
//	{
//		int cur = 0, send = 0, cnode;
//		for (int i = cpath.size() - 2; i >= 0; i--)
//		{
//			cnode = cpath[i];
//			if (bike[cnode] >= Cmax / 2)cur += bike[cnode] - Cmax / 2;
//			else if (bike[cnode] + cur >= Cmax / 2)cur -= Cmax / 2 - bike[cnode];
//			else
//			{
//				send += Cmax / 2 - bike[cnode] - cur;
//				cur = 0;
//			}
//		}
//		if (send < msend)
//		{
//			path = cpath;
//			msend = send;
//			mrecv = cur;
//		}
//		else if (send == msend && cur < mrecv)
//		{
//			path = cpath;
//			mrecv = cur;
//		}
//		cpath.pop_back();
//		return;
//	}
//	for (int i = 0; i < father[node].size(); i++)
//	{
//		dfs(father[node][i]);
//	}
//	cpath.pop_back();
//}
//int main()
//{
//	int a, b, c;
//	cin >> Cmax >> N >> SP >> M;
//	for (int i = 1; i <= N; i++)
//		cin >> bike[i];
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		road[a][b] = road[b][a] = c;
//	}
//	dijsktra();
//	dfs(SP);
//	cout << msend << " ";
//	printpath(path);
//	cout << mrecv;
//}

/*1111: 最短路径、实际*/
/*一直卡一个测试点，下次还是分开写吧*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M, S, D, minval = 0x3fffffff;
//int road[505][505][2];
//bool connected[505][505];
//vector<int>father[2][505];
//vector<int>curpath, finpath;
//void dijsktra(int a)
//{
//	bool visited[505] = { 0 };
//	int dis[505];
//	for (int i = 0; i < N; i++)
//	{
//		if (connected[S][i])
//		{
//			dis[i] = road[S][i][a];
//			father[a][i].push_back(S);
//		}
//		else dis[i] = 0x3fffffff;
//	}
//
//	visited[S] = 1;
//	while (!visited[D])
//	{
//		int index, mindis = 0x3fffffff;
//		for (int i = 0; i < N; i++)
//		{
//			if (!visited[i] && dis[i] < mindis)
//			{
//				index = i;
//				mindis = dis[i];
//			}
//		}
//
//		visited[index] = 1;
//		for (int i = 0; i < N; i++)
//		{
//			if (!visited[i] && connected[index][i])
//			{
//				if (dis[index] + road[index][i][a] < dis[i])
//				{
//					father[a][i].clear();
//					father[a][i].push_back(index);
//					dis[i] = dis[index] + road[index][i][a];
//				}
//				else if(dis[index] + road[index][i][a] == dis[i])
//					father[a][i].push_back(index);
//			}
//		}
//	}
//}
//
//void dfs(int node, int val, int num, int a)
//{
//	curpath.push_back(node);
//	if (node == S)
//	{
//		if (!a)
//		{
//			if (val < minval)
//			{
//				finpath = curpath;
//				minval = val;
//			}
//		}
//		else
//		{
//			if (num < minval)
//			{
//				finpath = curpath;
//				minval = num;
//			}
//		}
//		curpath.pop_back();
//		return;
//	}
//	for (int i = 0; i < father[a][node].size(); i++)
//		dfs(father[a][node][i], val + road[node][father[a][node][i]][a], num + 1, a);
//	curpath.pop_back();
//}
//int main()
//{
//	vector<int>length, time;
//	int a, b, c, d, e;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c >> d >> e;
//		road[a][b][0] = d, road[a][b][1] = e;
//		road[b][a][0] = d, road[b][a][1] = e;
//		connected[a][b] = 1;
//		if (!c)
//			connected[b][a] = 1;
//	}
//	cin >> S >> D;
//	dijsktra(0);
//	dijsktra(1);
//	dfs(D, 0, 1, 0);
//	length = finpath;
//	minval = 0x3fffffff;
//	dfs(D, 0, 1, 1);
//	time = finpath;
//	if (length == time)
//	{
//		int l = 0, t = 0;
//		for (int i = length.size() - 2; i >= 0; i--)
//		{
//			l += road[length[i]][length[i + 1]][0];
//			t += road[length[i]][length[i + 1]][1];
//		}
//		printf("Distance = %d; Time = %d: ", l, t);
//		for (int i = length.size() - 1; i >= 0; i--)
//		{
//			if (i != 0)cout << length[i] << " -> ";
//			else cout << length[i];
//		}
//	}
//	else
//	{
//		int l = 0, t = 0;
//		for (int i = length.size() - 2; i >= 0; i--)
//			l += road[length[i]][length[i + 1]][0];
//		for (int i = time.size() - 2; i >= 0; i--)
//			t += road[time[i]][time[i + 1]][1];
//		printf("Distance = %d: ", l);
//		for (int i = length.size() - 1; i >= 0; i--)
//		{
//			if (i != 0)cout << length[i] << " -> ";
//			else cout << length[i] << endl;
//		}
//		printf("Time = %d: ", t);
//		for (int i = time.size() - 1; i >= 0; i--)
//		{
//			if (i != 0)cout << time[i] << " -> ";
//			else cout << time[i];
//		}
//	}
//}

/*1043: 二叉搜索树*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class node
//{
//public:
//	int val;
//	node* left, * right;
//	node(int v) { val = v; left = right = 0; }
//};
//int N;
//int tree[1005];
//vector<int>pod;
//node* root, * fake = new node(-1);
//node* isBST(int a, int b)
//{
//	if (a < b)//问题4：没有判断a<b导致空树情况
//	{
//		int theroot = tree[a];
//		node* thisnode = new node(theroot);
//		int mid = b;//问题1：mid=-1使得无法判断空树
//		for (int i = a + 1; i < b; i++)//问题2：i=a开始错误，左子树不包含root
//		{
//			if (mid == b && tree[i] >= theroot)//问题3：没有添加mid==b导致mid值变化
//				mid = i;
//			if (mid < b && tree[i] < theroot)return fake;
//		}
//		node* l = isBST(a + 1, mid), * r = isBST(mid, b);
//		if (l != fake)thisnode->left = l;
//		else return fake;
//		if (r != fake)thisnode->right = r;
//		else return fake;
//		return thisnode;
//	}
//	else return 0;
//}
//node* isMirBST(int a, int b)
//{
//	if (a < b)
//	{
//		int theroot = tree[a];
//		node* thisnode = new node(theroot);
//		int mid = b;
//		for (int i = a + 1; i < b; i++)
//		{
//			if (mid == b && tree[i] < theroot)
//				mid = i;
//			if (mid < b && tree[i] >= theroot)
//				return fake;
//		}
//		node* l = isMirBST(a + 1, mid), * r = isMirBST(mid, b);
//		if (l != fake)thisnode->left = l;
//		else return fake;
//		if (r != fake)thisnode->right = r;
//		else return fake;
//		return thisnode;
//	}
//	else return 0;
//}
//void postorder(node* n)
//{
//	if (n != 0)
//	{
//		postorder(n->left);
//		postorder(n->right);
//		pod.push_back(n->val);
//	}
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)cin >> tree[i];
//	root = isBST(0, N);
//	if (root != fake)
//	{
//		cout << "YES" << endl;
//		postorder(root);
//		for (int i = 0; i < N; i++)
//			if (i != N - 1)cout << pod[i] << " ";
//			else cout << pod[i];
//	}
//	else
//	{
//		root = isMirBST(0, N);
//		if (root != fake)
//		{
//			cout << "YES" << endl;
//			postorder(root);
//			for (int i = 0; i < N; i++)
//				if (i != N - 1)cout << pod[i] << " ";
//				else cout << pod[i];
//		}
//		else cout << "NO";
//	}
//}

/*1106: 树的搜索*/
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//int N;
//double r, P;
//int height = 1, num;
//class node
//{
//public:
//	int id;
//	vector<int>child;
//	node(int v) { id = v; child.clear(); }
//};
//node* tree[100005];
//void levelorder()
//{
//	int cur = 1, next = 0;
//	int flag = 0;
//	queue<int>Q;
//	Q.push(0);
//	while (!Q.empty())
//	{
//		node* thisnode = tree[Q.front()];
//		Q.pop();
//		cur--;
//		if (!thisnode->child.empty())
//		{
//			for (int i = 0; i < thisnode->child.size(); i++)
//			{
//				if (thisnode->child[i] != 0)
//				{
//					Q.push(thisnode->child[i]);
//					next++;
//				}
//			}
//		}
//		else
//		{
//			flag = 1;
//			num++;
//		}
//
//		if (cur == 0)
//		{
//			if (flag)return;
//			swap(next, cur);
//			height++;
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> N >> P >> r;
//	for (int i = 0; i < N; i++)
//	{
//		int c;
//		tree[i] = new node(i);
//		cin >> n;
//		for (int j = 0; j < n; j++)
//		{
//			cin >> c;
//			tree[i]->child.push_back(c);
//		}
//	}
//	levelorder();
//	printf("%.4f %d", P * pow(1.0 + r / 100.0, height - 1), num);
//}

/*1110: 二叉搜索树*/
//#include<iostream>
//#include<queue>
//#include<string>
//using namespace std;
//class node
//{
//public:
//	int id, left, right, father;
//	node(int x) { id = x; left = right = father = -1; }
//	node() { id = left = right = father = -1; }
//};
//node tree[25];
//int N, root = -1;
//int levelorder()
//{
//	queue<int>Q;
//	int curr = 1, next = 0, last;
//	int flag = 0;
//	Q.push(root);
//	while (!Q.empty())
//	{
//		node thisnode = tree[Q.front()];
//		last = thisnode.id;
//		Q.pop();
//		curr--;
//		if (thisnode.left != -1)//初始化为-1而不是0，因为有0号节点
//		{
//			if (flag)return -1;
//			Q.push(thisnode.left);
//			next++;
//		}
//		else flag = 1;
//		if (thisnode.right != -1)
//		{
//			if (flag)return -1;
//			Q.push(thisnode.right);
//			next++;
//		}
//		else flag = 1;
//		if (curr == 0)swap(curr, next);
//	}
//	return last;
//}
//int main()
//{
//	cin >> N;
//	string a, b;//P:错误地用char而不是string
//	for (int i = 0; i < N; i++)
//	{
//		tree[i].id = i;
//		cin >> a >> b;
//		if (a != "-")
//		{
//			int l = atoi(a.c_str());
//			tree[l].father = i;
//			tree[i].left = l;
//		}
//		if (b != "-")
//		{
//			int r = atoi(b.c_str());
//			tree[r].father = i;
//			tree[i].right = r;
//		}
//	}
//	int curr = 0;
//	while (root != curr)//P: 用father寻找树根
//	{
//		root = curr;
//		if (tree[curr].father != -1)curr = tree[curr].father;
//	}
//	int res = levelorder();
//	if (res >= 0)cout << "YES " << res;
//	else cout << "NO " << root;
//}

/*1119：树的遍历*/
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//int N, isunique = 1;
//int pre[35], post[35];
//vector<int>order;
//class node
//{
//public:
//	int id;
//	node* left, * right;
//	node(int x) { id = x; left = right = 0; }
//};
//node* root;
//node* buildTree(int a1, int b1, int a2, int b2)
//{
//	if (a1 < b1)
//	{
//		node* thisroot = new node(pre[a1]);
//		unordered_map<int, int>bucket;
//		int mid = -1, flag = 1;
//		for (int i = a1 + 1; i < b1; i++)
//		{
//			flag = 1;
//			bucket[pre[i]]++;
//			for (int j = 0; j < i - a1; j++)
//			{
//				if (bucket.find(post[a2 + j]) == bucket.end())
//				{
//					flag = 0;
//					break;
//				}
//			}
//			if (flag)
//			{
//				mid = i;
//				break;
//			}
//		}
//		if (mid == b1 - 1)isunique = 0;//P: 什么情况下树是不唯一的？不能区分左子树和右子树的情况下
//		if (mid >= 0)thisroot->left = buildTree(a1 + 1, mid + 1, a2, a2 + mid - a1);
//		if (mid >= 0)thisroot->right = buildTree(mid + 1, b1, a2 + mid - a1, b2 - 1);
//		return thisroot;
//	}
//	else return 0;
//}
//void inorder(node* n)
//{
//	if (n != 0)
//	{
//		inorder(n->left);
//		order.push_back(n->id);
//		inorder(n->right);
//	}
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> pre[i];
//	for (int i = 0; i < N; i++)
//		cin >> post[i];
//	root = buildTree(0, N, 0, N);
//	inorder(root);
//	if (isunique)cout << "Yes" << endl;
//	else cout << "No" << endl;
//	for (int i = 0; i < N; i++)
//		if (i != N - 1)cout << order[i] << " ";
//		else cout << order[i];
//}

/*1155：二叉堆*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N;
//int seq[1005];
//int big, small, neither;
//class node
//{
//public:
//	int val;
//	node* left, * right;
//	node(int x) { val = x; left = right = 0; }
//};
//node* tree[2100];
//vector<node*>path;
//void ordertree(node* root)
//{
//	path.push_back(root);
//	if (root->left == 0 && root->right == 0)
//	{
//		for (int i = 0; i < path.size(); i++)
//		{
//			if (i != 0)
//			{
//				if (path[i - 1]->val > path[i]->val && !small && !neither)big = 1;
//				if (path[i - 1]->val < path[i]->val && !big && !neither)small = 1;
//				if (path[i - 1]->val > path[i]->val && small && !neither)neither = 1;
//				if (path[i - 1]->val < path[i]->val && big && !neither)neither = 1;
//			}
//			if (i != path.size() - 1)cout << path[i]->val << " ";
//			else cout << path[i]->val << endl;
//		}
//	}
//	else
//	{
//		if (root->right != 0)ordertree(root->right);
//		if (root->left != 0)ordertree(root->left);
//	}
//	path.pop_back();
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> seq[i];
//		tree[i] = new node(seq[i]);
//	}
//	for (int i = 0; i < N; i++)
//	{
//		tree[i]->left = tree[2 * i + 1];
//		tree[i]->right = tree[2 * i + 2];
//	}
//	ordertree(tree[0]);
//	if (neither)cout << "Not Heap";
//	else if (big)cout << "Max Heap";
//	else cout << "Min Heap";
//}

/*1107: 并查集*/
//#pragma warning (disable:4996) 
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int id, father;
//	vector<int>hobby;
//	node(int x) { id = father = x; }
//};
//int N;
//node* net[1005];
//int closure[1005];
//map<int, int>society;
//int getFather(node* n)
//{
//	int prev = 0, curr = n->father;
//	while (prev != curr)
//	{
//		prev = curr;
//		curr = net[curr]->father;
//	}
//	return curr;
//}
//int main()
//{
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		int n, h;
//		net[i] = new node(i);
//		scanf("%d: ", &n);
//		net[i]->hobby.resize(n);
//		for (int j = 0; j < n; j++)
//		{
//			cin >> h;
//			net[i]->hobby[j] = h;
//			if (closure[h] == 0)closure[h] = getFather(net[i]);
//			else
//			{
//				//这一行一开始的时候并没有写，导致错了三个，很重要
//				//当一个人的某一个爱好已经有了closure的归属后，代表这个人已经有了一个father
//				//而更改这个人的father意味着将合并两个closure，也就是说需要更改这个人father的father
//				net[getFather(net[i])]->father = getFather(net[closure[h]]);
//				net[i]->father = getFather(net[closure[h]]);
//			}
//		}
//	}
//	vector<int>output;
//	for (int i = 1; i <= N; i++)
//		society[getFather(net[i])]++;
//	for (auto i : society)
//		output.push_back(i.second);
//	sort(output.begin(), output.end(), greater<int>());
//	cout << output.size() << endl;
//	for (int i = 0; i < output.size(); i++)
//	{
//		if (i != output.size() - 1)cout << output[i] << " ";
//		else cout << output[i];
//	}
//}

/*1118：并查集*/
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//class node
//{
//public:
//	int father, id;
//	vector<int>birds;
//	node(int x) { father = id = x; }
//};
//int N, Q, numbirds;
//node* pic[10005];
//int closure[10005];
//int getFather(node* n)
//{
//	int prev = 0, curr = n->id, f;
//	while (prev != curr)
//	{
//		prev = curr;
//		curr = pic[curr]->father;
//	}
//	f = curr;
//	prev = 0, curr = n->id;
//	while (prev != curr)
//	{
//		prev = curr;
//		curr = pic[curr]->father;
//		pic[prev]->father = f;
//	}
//	return f;
//}
//int main()
//{
//	cin >> N;
//	int n;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> n;
//		pic[i] = new node(i);
//		pic[i]->birds.resize(n);
//		for (int j = 0; j < n; j++)
//		{
//			int b;
//			cin >> b;
//			if (b > numbirds)numbirds = b;
//			if (closure[b] == 0)closure[b] = i;
//			else
//			{
//				int fa = getFather(pic[closure[b]]), fb = getFather(pic[i]);
//				pic[fa]->father = fb;
//				getFather(pic[closure[b]]);
//			}
//		}
//	}
//	map<int, int>ele;
//	for (int i = 1; i <= numbirds; i++)
//		ele[getFather(pic[closure[i]])]++;
//	cout << ele.size() << " " << numbirds << endl;
//	cin >> Q;
//	int a, b;
//	for (int i = 0; i < Q; i++)
//	{
//		cin >> a >> b;
//		if (pic[closure[a]]->father == pic[closure[b]]->father)cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//}

/*洛谷P1551：并查集*/
//#include<iostream>
//using namespace std;
//int m, n, p;
//int father[5005];
//int getFather(int x)
//{
//	int prev = 0, curr = x, f;
//	while (prev != curr)
//	{
//		prev = curr;
//		curr = father[curr];
//	}
//	f = curr, prev = 0, curr = x;
//	while (prev != curr)
//	{
//		prev = curr;
//		curr = father[curr];
//		father[prev] = f;
//	}
//	return f;
//}
//int main()
//{
//	int a, b;
//	cin >> n >> m >> p;
//	for (int i = 1; i <= n; i++)father[i] = i;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a >> b;
//		int fa = getFather(a), fb = getFather(b);
//		if (fa != fb)father[fa] = fb;
//		getFather(a);
//	}
//	for (int i = 0; i < p; i++)
//	{
//		cin >> a >> b;
//		if (getFather(a) != getFather(b))cout << "No" << endl;
//		else cout << "Yes" << endl;
//	}
//}

/*1010: 二分查找*/
//#include<iostream>
//#include<math.h>
//#include<string.h>
//using namespace std;
//string N[3];
//int tag, r;
//long long a, b;
//long long getNum(long long radix, string n)
//{
//	long long sum = 0;
//	for (int i = n.size() - 1; i >= 0; i--)
//	{
//		if (n[i] >= '0' && n[i] <= '9')
//			sum += (n[i] - '0') * pow(radix, n.size() - 1 - i);
//		else sum += (n[i] - 'a' + 10) * pow(radix, n.size() - 1 - i);
//	}
//	return sum;
//}
//long long findRadix(long long& minr, long long& maxr, string n)
//{
//	long long midr;
//	while (minr < maxr)
//	{
//		midr = (minr + maxr) / 2;
//		b = getNum(midr, n);
//		if (a < b || b < 0)maxr = midr;
//		if (a > b)minr = midr + 1;
//		if (a == b)break;
//	}
//	if (a == b)return midr;
//	else return 0;
//}
//int main()
//{
//	cin >> N[1] >> N[2] >> tag >> r;
//	a = getNum(r, N[tag]);
//	string n;
//	if (tag == 1)n = N[2]; else n = N[1];
//	long long radix = 0;//测试点7：进制会很大以至于超出int范围，需改为longlong
//	for (int i = 0; i < n.size(); i++)
//	{
//		if (n[i] >= '0' && n[i] <= '9')
//		{
//			if (n[i] - '0' >= radix)
//				radix = n[i] - '0' + 1;
//		}
//		else if (n[i] - 'a' + 10 >= radix)
//			radix = n[i] - 'a' + 11;
//	}
//	long long minr = radix, maxr = minr * 2, minnum = radix;
//	while (1)
//	{
//		cout << radix << endl;
//		long long x = findRadix(minr, maxr, n);
//		if (a == b)
//		{
//			radix = x;
//			break;
//		}
//		else if (minr == radix * 2)
//		{
//			radix *= 2;
//			minr = radix, maxr = minr * 2;
//		}
//		else break;
//	}
//	if (a == b)
//	{
//		while (1)
//		{
//			if (getNum(radix - 1, n) == a && radix - 1 >= minnum)
//				radix--;
//			else break;
//		}
//		if (radix < 2)radix = 2;
//		cout << radix;
//	}
//	else cout << "Impossible";
//}

/*1044：二分查找*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M, mincost = 0x3fffffff;
//int chain[100005];
//vector<pair<int, int>>arr;
//int findPos(int x)
//{
//	int left = x, right = N + 1, mid;
//	while (left < right)
//	{
//		mid = (left + right) / 2;
//		if (chain[mid] - chain[x - 1] > M)
//			right = mid;
//		if (chain[mid] - chain[x - 1] < M)
//			left = mid + 1;
//		if (chain[mid] - chain[x - 1] == M)
//			return mid;
//	}
//	return -1;
//}
//void findBest(int x)
//{
//	int left = x, right = N + 1, mid;
//	while (left < right)
//	{
//		mid = (left + right) / 2;
//		if (chain[mid] - chain[x - 1] > M)
//			right = mid;
//		if (chain[mid] - chain[x - 1] < M)
//			left = mid + 1;
//	}
//	int spend = chain[left] - chain[x - 1];
//	if (spend > M)
//	{
//		if (spend < mincost)
//		{
//			mincost = spend;
//			arr.clear();
//			arr.push_back(pair<int, int>(x, left));
//		}
//		else if(spend==mincost)
//			arr.push_back(pair<int, int>(x, left));
//	}
//}
//int main()
//{
//	int x;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> x;
//		chain[i] = x + chain[i - 1];
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		x = findPos(i);
//		if (x > 0)
//		{
//			mincost = M;
//			printf("%d-%d\n", i, x);
//		}
//	}
//	if (mincost > M)
//	{
//		for (int i = 1; i <= N; i++)
//			findBest(i);
//	}
//	for (int i = 0; i < arr.size(); i++)
//		printf("%d-%d\n", arr[i].first, arr[i].second);
//}

/*1078：二次方探查*/
//#include<iostream>
//#include<math.h>
//#include<vector>
//using namespace std;
//int M, N, hashsize;
//vector<pair<int, int>>input;
//int table[100000];
//int isPrime(int x)
//{
//	if (x == 1)return 2;
//	for (int i = 2; i <= sqrt(x); i++)
//		if (x % i == 0)return 0;
//	return 1;
//}
//int findPos(int x)
//{
//	for (int i = 0; i < hashsize; i++)
//	{
//		int index = x + i * i, pos = index % hashsize;
//		if (table[pos] == 0)
//		{
//			table[pos] = 1;
//			return pos;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int a;
//	cin >> M >> N;
//	input.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> input[i].first;
//	for (hashsize = M; !isPrime(hashsize); hashsize++);
//	for (int i=0;i<N;i++)
//		input[i].second = findPos(input[i].first);
//	for (int i = 0; i < N; i++)
//	{
//		if (i != N - 1)
//		{
//			if (input[i].second < 0)cout << "- ";
//			else cout << input[i].second << " ";
//		}
//		else
//		{
//			if (input[i].second < 0)cout << "-";
//			else cout << input[i].second;
//		}
//	}
//}

/*1021: 连通分量*/
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int id;
//	vector<node*>child;
//	node(int x) { id = x; }
//};
//int N, visited[10005];
//node* graph[10005];
//pair<int, int> bfs(int x)//返回高度，遍历节点数
//{
//	node* root = graph[x];
//	int level = 0, cnt = 0, next = 0, curr = 1;
//	queue<node*>Q;
//	if (!visited[root->id])Q.push(root);
//	visited[root->id] = 1;
//	while (!Q.empty())
//	{
//		node* top = Q.front();
//		Q.pop();
//		curr--;
//		cnt++;
//		for (int i = 0; i < top->child.size(); i++)
//			if (!visited[top->child[i]->id])
//			{
//				Q.push(top->child[i]);
//				visited[top->child[i]->id] = 1;
//				next++;
//			}
//		if (curr == 0)
//		{
//			swap(curr, next);
//			level++;
//		}
//	}
//	return pair<int, int>(level, cnt);
//}
//int main()
//{
//	int a, b;
//	int height = 0, components = 0;
//	vector<int>nodes;
//	cin >> N;
//	for (int i = 1; i <= N; i++)graph[i] = new node(i);
//	for (int i = 1; i <= N - 1; i++)
//	{
//		cin >> a >> b;
//		graph[a]->child.push_back(graph[b]);
//		graph[b]->child.push_back(graph[a]);
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		pair<int, int>x = bfs(i);
//		if (x.second == N)
//		{
//			if (x.first > height)
//			{
//				height = x.first;
//				nodes.clear();
//				nodes.push_back(i);
//			}
//			else if (x.first == height)
//				nodes.push_back(i);
//			memset(visited, 0, sizeof(visited));
//		}
//		else if (x.first != 0)components++;
//	}
//	if (components != 0)
//		printf("Error: %d components", components);
//	else
//	{
//		sort(nodes.begin(), nodes.end());
//		for (int i = 0; i < nodes.size(); i++)
//			cout << nodes[i] << endl;
//	}
//}

/*1006: 搜索*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class signtime
//{
//public:
//	int hh, mm, ss;
//	bool operator <(signtime t)
//	{
//		if (hh < t.hh)return true;
//		else if (hh == t.hh && mm < t.mm)return true;
//		else if (hh == t.hh && mm == t.mm && ss < t.ss)return true;
//		return false;
//	}
//};
//class person
//{
//public:
//	string id;
//	signtime tin, tout;
//	person() = default;
//};
//int M;
//vector<person>record;
//int cmp1(person a, person b) { return a.tin < b.tin; }
//int cmp2(person a, person b) { return b.tout < a.tout; }
//int main()
//{
//	string s1, s2;
//	cin >> M;
//	record.resize(M);
//	for (int i = 0; i < M; i++)
//	{
//		cin >> record[i].id;
//		scanf("%d:%d:%d %d:%d:%d", &record[i].tin.hh, &record[i].tin.mm, &record[i].tin.ss,
//			&record[i].tout.hh, &record[i].tout.mm, &record[i].tout.ss);
//	}
//	sort(record.begin(), record.end(), cmp1);
//	s1 = record.front().id;
//	sort(record.begin(), record.end(), cmp2);
//	s2 = record.front().id;
//	cout << s1 << " " << s2;
//}

/*1009: 模拟*/
//#include<iostream>
//#include<map>
//#include<algorithm>
//using namespace std;
//class term
//{
//public:
//	int exp;
//	double coe;
//};
//int ka, kb;
//term A[15], B[15];
//map<int, double, greater<int>>product;
//int main()
//{
//	cin >> ka;
//	for (int i = 0; i < ka; i++)cin >> A[i].exp >> A[i].coe;
//	cin >> kb;
//	for (int i = 0; i < kb; i++)cin >> B[i].exp >> B[i].coe;
//	for (int i = 0; i < ka; i++)
//		for (int j = 0; j < kb; j++)
//			product[A[i].exp + B[j].exp] += A[i].coe * B[j].coe;
//	for (auto i = product.begin(); i != product.end(); i++)
//		if (i->second == 0)product.erase(i);
//	cout << product.size();
//	for (auto i : product)printf(" %d %.1f", i.first, i.second);
//}

/*1017: 模拟*/
//#pragma warning(disable:4996)
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//class person
//{
//public:
//	int arrive, P;
//};
//int N, K, open = 8 * 3600, close = 17 * 3600;
//vector<person>customers;
//int cmp(person a, person b) { return a.arrive < b.arrive; }
//int main()
//{
//	priority_queue<int, vector<int>, greater<int>>bank;//大小K记录了K个服务结束的时间，按先后排序
//	int a, b, c, cnt = 0, total = 0;
//	cin >> N >> K;
//	customers.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d:%d:%d %d", &a, &b, &c, &customers[i].P);
//		customers[i].arrive = a * 3600 + b * 60 + c;
//		customers[i].P *= 60;
//	}
//	sort(customers.begin(), customers.end(), cmp);
//	for (int i = 0; i < K; i++)bank.push(open);
//	for (int i = 0; i < N; i++)
//	{
//		if (customers[i].arrive <= close)
//		{
//			if (bank.top() <= customers[i].arrive)//顾客来的晚，不用等
//			{
//				bank.pop();
//				bank.push(customers[i].arrive + customers[i].P);
//			}
//			else
//			{
//				total += bank.top() - customers[i].arrive;
//				bank.push(bank.top() + customers[i].P);
//				bank.pop();
//			}
//			cnt++;
//		}
//	}
//	cout << cnt << endl;
//	printf("%.1f", (double)total / cnt / 60);
//}

/*1026: 模拟，未完成*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class table
//{
//public:
//	int id, opentime;
//	table(int x)
//	{
//		id = x;
//		opentime = 8 * 3600;
//	}
//	table() = default;
//};
//class player
//{
//public:
//	int arrive, playtime, vip, waiting;
//};
//class Tuple
//{
//public:
//	int arr, play, wait;
//	Tuple(int a, int b, int c) { arr = a, play = b, wait = c; }
//};
//int N, K, M, open = 8 * 3600, close = 21 * 3600;
//vector<player> p;
//vector<Tuple>res;
//vector<int>viplist;
//int vt[105];
//int cmp(player a, player b) { return a.arrive < b.arrive; }
//int cmp2(table a, table t)
//{
//	if (a.opentime < t.opentime)return 1;
//	else if (a.opentime == t.opentime && a.id < t.id)return 1;
//	return 0;
//}
//int cmp3(Tuple a, Tuple b) { return a.arr < b.arr; }
//int main()
//{
//	int a, b, c;
//	cin >> N;
//	p.resize(N);
//	vector<table> q, vq;
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d:%d:%d %d %d", &a, &b, &c, &p[i].playtime, &p[i].vip);
//		p[i].arrive = a * 3600 + b * 60 + c;
//		p[i].playtime *= 60;
//		p[i].waiting = 1;
//	}
//	sort(p.begin(), p.end(), cmp);
//	for (int i = 0; i < N; i++)if (p[i].vip)viplist.push_back(i);
//	cin >> K >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> vt[i];
//		vq.push_back(*new table(vt[i]));
//	}
//	sort(vq.begin(), vq.end(), cmp2);
//	for (int i = 1; i <= K; i++)
//	{
//		int isvip = 0;
//		for(int j=0;j<M;j++)
//			if (vt[j] == i)
//			{
//				isvip = 1;
//				break;
//			}
//		if (!isvip)
//			q.push_back(*new table(i));
//	}
//	sort(q.begin(), q.end(), cmp2);
//	//初始化完成，q和vq为桌子
//	for (int i = 0; i < N; i++)
//	{
//		//没人排队，所有桌子都能用
//		if (p[i].waiting && p[i].arrive <= close && q.front().opentime <= close && vq.front().opentime <= close)
//		{
//			if (p[i].arrive >= q.front().opentime)
//			{
//				q.front().opentime = p[i].arrive + p[i].playtime;
//				res.push_back(*new Tuple(p[i].arrive, p[i].arrive, 0));
//				sort(q.begin(), q.end(), cmp2);
//				p[i].waiting = 0;
//			}
//			else if (p[i].arrive >= vq.front().opentime)
//			{
//				vq.front().opentime = p[i].arrive + p[i].playtime;
//				res.push_back(*new Tuple(p[i].arrive, p[i].arrive, 0));
//				sort(vq.begin(), vq.end(), cmp2);
//				p[i].waiting = 0;
//			}
//			else  //有人排队，vip桌子要优先提供给vip的人用
//			{
//				for (int j = 0; j < viplist.size(); j++)
//				{
//					if (p[viplist[j]].waiting && vq.front().opentime <= close)//先看vip桌空闲的时候有没有vip排队
//					{
//						if (p[viplist[j]].arrive <= vq.front().opentime)
//						{
//							vq.front().opentime += p[viplist[j]].playtime;
//							p[viplist[j]].waiting = 0;
//							res.push_back(*new Tuple(p[viplist[j]].arrive, vq.front().opentime,
//								vq.front().opentime - p[viplist[j]].arrive));
//							sort(vq.begin(), vq.end(), cmp2);
//							j = -1;//再检查一遍
//						}
//						else break;
//					}
//				}
//				if (p[i].waiting && q.front().opentime <= close && vq.front().opentime <= close)
//				{
//					if (q.front().opentime <= vq.front().opentime)
//					{
//						q.front().opentime += p[i].playtime;
//						p[i].waiting = 0;
//						res.push_back(*new Tuple(p[i].arrive, q.front().opentime, q.front().opentime - p[i].arrive));
//						sort(q.begin(), q.end(), cmp2);
//					}
//					else
//					{
//						vq.front().opentime += p[i].playtime;
//						p[i].waiting = 0;
//						res.push_back(*new Tuple(p[i].arrive, vq.front().opentime, vq.front().opentime - p[i].arrive));
//						sort(vq.begin(), vq.end(), cmp2);
//					}
//				}
//			}
//		}
//	}
//	sort(res.begin(), res.end(), cmp3);
//	for (int i = 0; i < res.size(); i++)
//	{
//		int hh1, mm1, ss1, hh2, mm2, ss2, t;
//		hh1 = res[i].arr / 3600, hh2 = res[i].play / 3600;
//		mm1 = (res[i].arr - hh1 * 3600) / 60, mm2 = (res[i].play - hh2 * 3600) / 60;
//		ss1 = (res[i].arr - hh1 * 3600 - mm1 * 60), ss2 = (res[i].play - hh2 * 3600 - mm2 * 60);
//		if (res[i].wait % 60 == 0)t = res[i].wait / 60;
//		else t = res[i].wait / 60 + 1;
//		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", hh1, mm1, ss1, hh2, mm2, ss2, t);
//	}
//}

/*1042: 模拟*/
//#include<iostream>
//#include<string>
//using namespace std;
//string cards[55];
//int N;
//int order[55];
//void init()
//{
//	string a[5] = { "-", "S", "H", "C", "D" };
//	for (int i = 1; i <= 4; i++)
//		for (int j = 1; j <= 13; j++)
//			cards[(i - 1) * 13 + j] = a[i] + to_string(j);
//	cards[53] = "J1", cards[54] = "J2";
//}
//void shuffle()
//{
//	string next[55];
//	for (int i = 1; i <= 54; i++)
//		next[order[i]] = cards[i];
//
//	for (int i = 1; i <= 54; i++)cards[i] = next[i];
//}
//int main()
//{
//	cin >> N;
//	for (int i = 1; i <= 54; i++)cin >> order[i];
//	init();
//	for (int i = 0; i < N; i++)
//		shuffle();
//	for (int i = 1; i <= 54; i++)
//		if (i != 54)cout << cards[i] << " ";
//		else cout << cards[i];
//}

/*1046: 模拟*/
//#include<iostream>
//using namespace std;
//int N, total, M;
//int road[100005];
//int main()
//{
//	int a, b, d;
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> a;
//		road[i] = a + road[i - 1];
//	}
//	total = road[N];
//	cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		if (a > b)swap(a, b);
//		d = min(road[b - 1] - road[a - 1], total - road[b - 1] + road[a - 1]);
//		cout << d << endl;
//	}
//}

/*1065: 模拟*/
//#pragma warning (disable:4996)
//#include<iostream>
//using namespace std;
//using gg = long long;
//int main() {
//	gg n = 9223372036854775808;
//	cout << n;
//	//scanf("%lld", &n);
//	//for (gg i = 1; i <= n; i++) {
//	//	gg a, b, c;
//	//	scanf("%lld %lld %lld", &a, &b, &c);
//	//	gg res = a + b, flag;
//	//	if (a > 0 && b > 0 && res < 0) flag = true;		//都溢出了肯定比C大
//	//	else if (a < 0 && b < 0 && res >= 0) flag = false;//都溢出了肯定比C小
//	//	else flag = a + b > c;
//	//	printf("Case #%lld: %s\n", i, (flag ? "true" : "false"));
//	//}
//	//return 0;
//}

/*1105: 模拟*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N, n, m;
//vector<int>arr;
//int matrix[10005][10005];
//void travel()
//{
//	int left = 0, right = n - 1, up = 1, down = m - 1;
//	int i = 0, j = 0;
//	char pos = 'r';
//	for (int a = 0; a < N;)
//	{
//		switch (pos)
//		{
//		case 'r':
//			if (j == right)
//			{
//				pos = 'd';
//				right--;
//			}
//			else
//			{
//				matrix[i][j] = arr[a];
//				j++;
//				a++;
//			}
//			break;
//
//		case 'd':
//			if (i == down)
//			{
//				pos = 'l';
//				down--;
//			}
//			else
//			{
//				matrix[i][j] = arr[a];
//				i++;
//				a++;
//			}
//			break;
//
//		case 'l':
//			if (j == left)
//			{
//				pos = 'u';
//				left++;
//			}
//			else
//			{
//				matrix[i][j] = arr[a];
//				j--;
//				a++;
//			}
//			break;
//		case 'u':
//			if (i == up)
//			{
//				pos = 'r';
//				up++;
//			}
//			else
//			{
//				matrix[i][j] = arr[a];
//				i--;
//				a++;
//			}
//			break;
//		}
//	}
//}
//int main()
//{
//	cin >> N;
//	arr.resize(N);
//	for (int i = 0; i < N; i++)cin >> arr[i];
//	sort(arr.begin(), arr.end(), greater<int>());
//	for (int i = sqrt(N); i > 0; i--)
//		if (N % i == 0)
//		{
//			n = i;
//			m = N / i;
//			break;
//		}
//	travel();
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (j != n - 1)cout << matrix[i][j] << " ";
//			else cout << matrix[i][j];
//		}
//		cout << endl;
//	}
//}

/*1153: 模拟*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//int N, M;
//class student
//{
//public:
//	string id;
//	int score;
//	student() = default;
//};
//student cards[10005], query[105];
//int cmp(student a, student b)
//{
//	if (a.score > b.score)return 1;
//	else if (a.score == b.score && a.id < b.id)return 1;
//	return 0;
//}
//int cmp2(pair<string, int>a, pair<string, int>b)
//{
//	if (a.second > b.second)return 1;
//	else if (a.second == b.second && a.first < b.first)return 1;
//	return 0;
//}
//void deal()
//{
//	vector<student>res;
//	int total;
//	for (int i = 0; i < M; i++)
//	{
//		printf("Case %d: %d %s\n", i + 1, query[i].score, query[i].id.c_str());
//		switch (query[i].score)
//		{
//		case 1:
//			res.clear();
//			for (int k = 0; k < N; k++)
//			{
//				if (cards[k].id.substr(0, 1) == query[i].id)
//					res.push_back(cards[k]);
//			}
//			sort(res.begin(), res.end(), cmp);
//			if (res.size() > 0)
//				for (int k = 0; k < res.size(); k++)
//					printf("%s %d\n", res[k].id.c_str(), res[k].score);
//			else printf("NA\n");
//			break;
//
//		case 2:
//			res.clear();
//			for (int k = 0; k < N; k++)
//			{
//				if (cards[k].id.substr(1, 3) == query[i].id)
//					res.push_back(cards[k]);
//			}
//			total = 0;
//			for (int k = 0; k < res.size(); k++)
//				total += res[k].score;
//			if (res.size() > 0)printf("%d %d\n", res.size(), total);
//			else printf("NA\n");
//			break;
//
//		case 3:
//			res.clear();
//			unordered_map<string, int>out;
//			for (int k = 0; k < N; k++)
//			{
//				if (cards[k].id.substr(4, 6) == query[i].id)
//				{
//					out[cards[k].id.substr(1, 3)]++;
//				}
//			}
//			vector<pair<string, int>>p;
//			for (auto i : out)p.push_back(pair<string, int>(i.first, i.second));
//			sort(p.begin(), p.end(), cmp2);
//			if (p.size() > 0)
//				for (int k = 0; k < p.size(); k++)
//					printf("%s %d\n", p[k].first.c_str(), p[k].second);
//			else printf("NA\n");
//
//			
//			break;
//
//		}
//	}
//}
//int main()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)cin >> cards[i].id >> cards[i].score;
//	for (int i = 0; i < M; i++)cin >> query[i].score >> query[i].id;
//	deal();
//}

/*1081: 分数*/
//#pragma warning (disable:4996)
//#include<iostream>
//using namespace std;
//typedef long long ll;
//int N;
//class frac
//{
//public:
//	ll num, dem;
//};
//frac n[105];
//ll findGYS(ll a, ll b)
//{
//	ll m = min(a, b), n = max(a, b), t;
//	while (n % m != 0)
//	{
//		t = n % m;
//		n = m, m = t;
//	}
//	return m;
//}
//int main()
//{
//	cin >> N;
//	ll common = 1, sum = 0, inte, gys;
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%lld/%lld", &n[i].num, &n[i].dem);
//		gys = findGYS(abs(n[i].num), n[i].dem);//及时约分以免数字超出long long范围
//		n[i].num /= gys, n[i].dem /= gys;
//		gys = findGYS(common, n[i].dem);
//		common = common * n[i].dem / gys;
//	}
//	for (int i = 0; i < N; i++)
//		sum += n[i].num * common / n[i].dem;
//	inte = sum / common;
//	sum -= inte * common;
//	if (sum != 0)
//	{
//		gys = findGYS(abs(sum), common);
//		sum /= gys;
//		common /= gys;
//	}
//	if (inte == 0)
//		if (sum != 0)printf("%lld/%lld", sum, common);
//		else cout << 0;
//	else if (sum == 0)cout << inte;
//	else printf("%lld %lld/%lld", inte, abs(sum), common);
//}

/*1131: DFS, 未完成*/
//#include<iostream>
//#include<vector>
//using namespace std;
////	first = staion, second = line
//int visited[10000];
//vector<pair<int, int>>station[10000];
//vector<pair<int, int>>path;
//vector<vector<pair<int, int>>>res;
//int N, K, length, minlength;
//void findWay(int s, int e)
//{
//	visited[s] = 1;
//	if (s == e)
//	{
//		if (length < minlength)
//		{
//			res.clear();
//			res.push_back(path);
//			minlength = length;
//		}
//		else if (length == minlength)
//			res.push_back(path);
//		visited[s] = 0;
//		length--;
//		return;
//	}
//	for (int i = 0; i < station[s].size(); i++)
//	{
//		if (!visited[station[s][i].first])
//		{
//			path.push_back(station[s][i]);
//			length++;
//			findWay(station[s][i].first, e);
//		}
//	}
//	if(!path.empty())path.pop_back();
//	length--;
//	visited[s] = 0;
//}
//void plot(vector<pair<int, int>>p, int s)
//{
//	int currline = p[0].second, index = 0;
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (p[i].second != currline || i == p.size() - 1)
//		{
//			int stat;
//			if (index == 0)stat = s; else stat = p[index].first;
//			printf("Take Line#%d from %04d to %04d.\n", currline, stat, p[i-1].first);
//			index = i - 1;
//			currline = p[i].second;
//		}
//	}
//}
//int main()
//{
//	cin >> N;
//	int a, line[105];
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> a;
//		for (int j = 0; j < a; j++)
//		{
//			cin >> line[j];
//			if (j > 0)
//			{
//				station[line[j - 1]].push_back(pair<int, int>(line[j], i));
//				station[line[j]].push_back(pair<int, int>(line[j - 1], i));
//			}
//		}
//	}
//	cin >> K;
//	int b;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> a >> b;
//		path.clear(), res.clear();
//		length = 0;
//		minlength = 0x2fffffff;
//		memset(visited, 0, sizeof(visited));
//		findWay(a, b);
//		int transfer, mintran = 0x3fffffff, index;
//		for (int k = 0; k < res.size(); k++)
//		{
//			transfer = 0;
//			int curr = res[k][0].second;
//			for (int j = 0; j < res[k].size(); j++)
//			{
//				if (res[k][j].second != curr)
//				{
//					curr = res[k][j].second;
//					transfer++;
//				}
//			}
//			if (transfer < mintran)
//			{
//				mintran = transfer;
//				index = k;
//			}
//		}
//		//找到距离最短、换乘最少的路径index
//		cout << minlength << endl;
//		for (int i = 0; i < res.size(); i++)
//		{
//			plot(res[i], a);
//			cout << "-----------------" << endl;
//		}
//	}
//}

/*1007: 动态规划*/
/*不使用动态规划的情况下最后一个测试点超时*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class node
//{
//public:
//	int index, val;
//	node() = default;
//};
//int N;
//node sum[10005];
//int cmp1(node a, node b)
//{
//	if (a.val < b.val)return 1;
//	else if (a.val == b.val && a.index < b.index)return 1;
//	else return 0;
//}
//int cmp2(node a, node b)
//{
//	if (a.val > b.val)return 1;
//	else if (a.val == b.val && a.index < b.index)return 1;
//	else return 0;
//}
//
//node getMax(int a, int b)
//{
//	vector<node>temp(sum + a, sum + b);
//	sort(temp.begin(), temp.end(), cmp2);
//	return temp[0];
//}
//node getMin(int a, int b)
//{
//	vector<node>temp(sum + a, sum + b);
//	sort(temp.begin(), temp.end(), cmp1);
//	return temp[0];
//}
//int main()
//{
//	int a, nega = 1, res = -0x3fffffff, imax, imin;
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> a;
//		sum[i].val = sum[i - 1].val + a;
//		sum[i].index = i;
//		if (a >= 0)nega = 0;
//	}
//	node x, y;
//	x = sum[0], y = getMax(1, N + 1);
//	for (int i = 1; i <= N; i++)
//	{
//		if (sum[i - 1].val < x.val)x = sum[i - 1];
//		if (sum[i - 1].val == y.val)y = getMax(i, N + 1);
//		if (y.val - x.val > res)
//		{
//			res = y.val - x.val;
//			imax = y.index, imin = x.index;
//		}
//	}
//	if (nega)printf("%d %d %d", 0, sum[1].val, sum[N].val - sum[N - 1].val);
//	else printf("%d %d %d", res, sum[imin + 1].val - sum[imin].val, sum[imax].val - sum[imax - 1].val);
//}

/*使用动态规划*/
//#include<iostream>
//using namespace std;
//int N;
//int arr[10005], dp[10005];
//int main()
//{
//	int start = 1, tempstart = 1, end1 = 1, tempend, smax = -1, nega = 1;
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> arr[i];
//		if (arr[i] >= 0)nega = 0;
//		if (dp[i - 1] < 0)
//		{
//			dp[i] = arr[i];
//			tempstart = tempend = i;
//		}
//		else
//		{
//			dp[i] = dp[i - 1] + arr[i];
//			tempend = i;
//		}
//		if (dp[i] > smax)
//		{
//			smax = dp[i];
//			start = tempstart;
//			end1 = tempend;
//		}
//	}
//	if (nega)printf("%d %d %d", 0, arr[1], arr[N]);
//	else printf("%d %d %d", smax, arr[start], arr[end1]);
//}

/**/

/*模拟1.1*/
//#include<iostream>
//using namespace std;
//int N, T, K;
//int check(string x)
//{
//	int score = 0, maxlength = 0, uplength = 1;
//	char samel = x[0];
//	if (x[0] == 'f')score -= 2;
//	if (x[N - 1] == 'a')score -= 1;
//	for (int i = 0; i < N; i++)
//	{
//		if (x[i] == 'a' && i != N - 1 && (x[i + 1] == 'h' || x[i + 1] == 'e'))score -= 4;
//		if (x[i] == samel)
//			maxlength++;
//		if (x[i] != samel || i == N - 1)
//		{
//			if (maxlength > 5)score += 3;
//			samel = x[i];
//			maxlength = 1;
//		}
//
//		if (i > 0)
//		{
//			if (x[i] - x[i - 1] == 1)
//				uplength++;
//			if (x[i] - x[i - 1] != 1 || i == N - 1)
//			{
//				if (uplength > 3)score += 5;
//				uplength = 1;
//			}
//		}
//	}
//	return score;
//}
//int main()
//{
//	int res;
//	string test;
//	cin >> N >> T >> K;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> test;
//		res = check(test);
//		if (res > T)printf("%d!!!\n", res);
//		else printf("%d\n", res);
//	}
//}

/*二分1.2*/
/*我真是吐了，原来cin才是最耗时的那个，gjb东西*/
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int N, K;
//vector<int>res;
//int findMin(int x)
//{
//	int left = 0, right = res.size(), mid;
//	while (left < right)
//	{
//		mid = (left + right) / 2;
//
//	}
//}
//int main()
//{
//	int a, nmin = 0x7fffffff, index;
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a;
//		if (res.size() != K)
//			res.push_back(a);
//		else 
//		{
//			index = findMin(a);
//			if (index > 0)res[index] = a;
//		}
//	}
//	a = 0;
//	//if (N < K)l.sort(greater<int>());
//	//for (auto i : l)
//	//{
//	//	if (a++ == 0)cout << i;
//	//	else cout << " " << i;
//	//}
//}

/*BST1.3*/
//#include<iostream>
//#include<vector>
//using namespace std;
//class node
//{
//public:
//	int val;
//	node* left, * right;
//	node(int x) { val = x; }
//};
//int N;
//node* tree[1005];
//vector<int>res;
//int getMax(node* root)
//{
//	if (root != 0)
//	{
//		int l = getMax(root->left);
//		int r = getMax(root->right);
//		return max(root->val, max(l, r));
//	}
//	return 0;
//}
//int getMin(node* root)
//{
//	if (root != 0)
//	{
//		int l = getMin(root->left);
//		int r = getMin(root->right);
//		return min(root->val, min(l, r));
//	}
//	return 0x3fffffff;
//}
//int checkBST(node* root)
//{
//	if (root == 0)return 1;
//	int flag = 0;
//	int l = getMax(root->left);
//	int r = getMin(root->right);
//	if (l < root->val && r >= root->val)flag = 1;
//	return flag && checkBST(root->left) && checkBST(root->right);
//}
//void inorder(node* root)
//{
//	if (root == 0)return;
//	inorder(root->left);
//	res.push_back(root->val);
//	inorder(root->right);
//}
//int main()
//{
//	int a;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a;
//		tree[i] = new node(a);
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (2 * i + 1 < N && tree[2 * i + 1]->val != -1)tree[i]->left = tree[2 * i + 1];
//		if (2 * i + 2 < N && tree[2 * i + 2]->val != -1)tree[i]->right = tree[2 * i + 2];
//	}
//	if (checkBST(tree[0]))cout << "YES\n";
//	else cout << "NO\n";
//	inorder(tree[0]);
//	for (int i = 0; i < res.size(); i++)
//	{
//		if (i == 0)cout << res[i];
//		else cout << " " << res[i];
//	}
//}

/*模拟、dfs1.4*/
/*应改用bfs求解距离*/
//#include<iostream>
//using namespace std;
//string seq;
//int N, M, rex, rey;
//int ix, iy;
//char map[105][105];
//void string2dis(int& x, int& y, string s)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		switch (s[i])
//		{
//		case '0':
//			x--;
//			break;
//		case '1':
//			y++;
//			break;
//		case '2':
//			x++;
//			break;
//		case '3':
//			y--;
//			break;
//		}
//	}
//}
//int checkSeq()
//{
//	int flag = 1;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= M; j++)
//		{
//			int a = i, b = j;
//			string2dis(a, b, seq);
//			a = min(max(1, a), N), b = min(max(1, b), N);
//			if (map[a][b] != 'X')
//			{
//				flag = 0;
//				break;
//			}
//		}
//	}
//	return flag;
//}
//int getDis(int x, int y)
//{
//	if (map[x][y] == 'X')return 0;
//	if (x > rex)
//	{
//		if (y > rey && map[x][y - 1] != '#')return 1 + getDis(x, y - 1);
//		else if (y < rey && map[x][y + 1] != '#')return 1 + getDis(x, y + 1);
//		else if (y == rey && map[x - 1][y] != '#')return 1 + getDis(x - 1, y);
//	}
//	else if (x < rex)
//	{
//		if (y > rey && map[x][y - 1] != '#')return 1 + getDis(x, y - 1);
//		else if (y < rey && map[x][y + 1] != '#')return 1 + getDis(x, y + 1);
//		else if (y == rey && map[x + 1][y] != '#')return 1 + getDis(x + 1, y);
//	}
//}
//void findFar(int x, int y)
//{
//	int d, xx, yy, dmax = 0;
//	for (int j = 1; j <= M; j++)
//	{
//		for (int i = N; i > 0; i--)
//		{
//			xx = min(max(1, i + x), N), yy = min(max(1, j + y), M);
//			d = getDis(xx, yy);
//			if (d > dmax)
//			{
//				dmax = d;
//				ix = xx;
//				iy = yy;
//			}
//		}
//	}
//}
//string genSeq()
//{
//	string temp = "";
//	int i = ix, j = iy;
//	while (map[i][j] != 'X')
//	{
//		if (i > rex)
//		{
//			temp.append("0");
//			i--;
//			continue;
//		}
//		if (j < rey)
//		{
//			temp.append("1");
//			j++;
//			continue;
//		}
//		if (i < rex)
//		{
//			temp.append("2");
//			i++;
//			continue;
//		}
//		if (j > rey)
//		{
//			temp.append("3");
//			j--;
//			continue;
//		}
//	}
//	return temp;
//}
//int main()
//{
//	string temp = "";
//	int dx = 0, dy = 0;
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= M; j++)
//		{
//			cin >> map[i][j];
//			if (map[i][j] == 'X')
//			{
//				rex = i;
//				rey = j;
//			}
//		}
//	for (int i = 0; i <= M + 1; i++)
//		map[0][i] = map[N + 1][i] = '#';
//	for (int i = 0; i <= N + 1; i++)
//		map[i][0] = map[i][M + 1] = '#';
//
//	//while (1)
//	//{
//		string2dis(dx, dy, temp);//根据上次生成的序列计算点的偏移量
//		findFar(dx, dy);//找到图中最远的那个点
//		temp = genSeq();//生成最远的那个点到X的路径序列
//		seq.append(temp);
//		//if (checkSeq())break;
//		string2dis(dx, dy, temp);
//		findFar(dx, dy);
//		cout << ix << " " << iy << endl;
//	//}
//	//cout << seq;
//}

/*1040: 动态规划*/
//#include<iostream>
//#include<string>
//using namespace std;
//string str;
//int dp[1005][1005];
//int checkSym(int x, int y)
//{
//	for (int i = x, j = y; i <= j; i++, j--)
//	{
//		if (str[i] != str[j])return 0;
//	}
//	return 1;
//}
//int main()
//{
//	getline(cin, str);
//	for (int i = str.size() - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < str.size(); j++)
//		{
//			if (i > j)dp[i][j] = 0;
//			if (i == j)dp[i][j] = 1;
//			if (i < j)
//			{
//				if (str[i] == str[j] && checkSym(i, j))dp[i][j] = 2 + dp[i + 1][j - 1];
//				else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//			}
//		}
//	}
//	cout << dp[0][str.size() - 1];
//}

/*1045: 动态规划*/
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//int N, M, L;
//unordered_map<int, int>favor, dislike;
//int str[10005], dp[10005][205];
//int main()
//{
//	int a;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a;
//		favor[a] = i;
//	}
//	for (int i = 1; i <= N; i++)
//		if (favor.find(i) == favor.end())
//			dislike[i]++;
//	cin >> L;
//	for (int i = 0; i < L; i++)cin >> str[i];
//	for (int i = L - 1; i >= 0; i--)
//	{
//		for (int j = M - 1; j >= 0; j--)
//		{
//			if (dislike[str[i]])dp[i][j] = dp[i + 1][j];
//			else
//			{
//				if (favor[str[i]] == j)dp[i][j] = dp[i + 1][j] + 1;
//				if (favor[str[i]] < j)dp[i][j] = dp[i + 1][j];
//				if (favor[str[i]] > j)dp[i][j] = max(dp[i + 1][j], dp[i + 1][favor[str[i]]] + 1);
//			}
//		}
//	}
//	cout << dp[0][0];
//}

/*1134: hash*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N, M, K;
//vector<int>net[10000];
//int visited[10000];
//int main()
//{
//	int a, b, num;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b;
//		net[a].push_back(b);
//		net[b].push_back(a);
//	}
//	cin >> K;
//	for (int i = 0; i < K; i++)
//	{
//		memset(visited, 0, sizeof(visited));
//		num = M;
//		cin >> a;
//		for (int j = 0; j < a; j++)
//		{
//			cin >> b;
//			visited[b] = 1;
//			for (int x = 0; x < net[b].size(); x++)
//				if (!visited[net[b][x]])num--;
//		}
//		if (num == 0)printf("Yes\n");
//		else printf("No\n");
//	}
//}

/*1095: 模拟*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//class record
//{
//public:
//	string id;
//	int t, flag;
//};
//int N, K;
//unordered_map<string, int>total;
//vector<record>logs, cars;
//int cmp(record a, record b)
//{
//	if (a.id < b.id)return 1;
//	else if (a.id == b.id && a.t < b.t)return 1;
//	return 0;
//}
//int cmp2(record a, record b) { return a.t < b.t; }
//int main()
//{
//	string state;
//	int a, b, c, t;
//	cin >> N >> K;
//	logs.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> logs[i].id;
//		scanf("%d:%d:%d", &a, &b, &c);
//		cin >> state;
//		if (state == "in")logs[i].flag = 1; else logs[i].flag = -1;
//		logs[i].t = a * 3600 + b * 60 + c;
//	}
//	sort(logs.begin(), logs.end(), cmp);
//
//	string curr = logs[0].id;
//	int s = -1, index;
//	for (int i = 0; i < N; i++)
//	{
//		if (logs[i].id != curr)
//		{
//			curr = logs[i].id;
//			s = -1;
//		}
//		if (logs[i].id == curr)
//		{
//			if (logs[i].flag == 1)
//			{
//				index = i;
//				s = 1;
//			}
//			else if (s == 1)
//			{
//				cars.push_back(logs[index]);
//				cars.push_back(logs[i]);
//				s = -1;
//				total[curr] += logs[i].t - logs[index].t;
//			}
//		}
//	}
//	sort(cars.begin(), cars.end(), cmp2);
//	int j = 0, last = 0, cnt = 0;
//	for (int i = 0; i < K; i++)
//	{
//		scanf("%d:%d:%d", &a, &b, &c);
//		t = a * 3600 + b * 60 + c;
//		while (j < cars.size() && t >= cars[j].t)
//		{
//			cnt += cars[j].flag;
//			j++;
//		}
//		printf("%d\n", cnt + last);
//		last += cnt;
//		cnt = 0;
//	}
//	
//	vector<string>most;
//	int spend = 0;
//	for (auto i : total)
//	{
//		if (i.second > spend)
//		{
//			most.clear();
//			most.push_back(i.first);
//			spend = i.second;
//		}
//		else if (i.second == spend)
//			most.push_back(i.first);
//	}
//	sort(most.begin(), most.end());
//	for (auto i : most)
//		printf("%s ", i.c_str());
//	a = spend / 3600;
//	b = (spend - a * 3600) / 60;
//	c = spend - a * 3600 - b * 60;
//	printf("%02d:%02d:%02d", a, b, c);
//}

/*1052: 链表*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//class node
//{
//public:
//	int addr, key, next;
//};
//int N, head;
//vector<node>input, List;
//unordered_map<int, int>add2index;
//int cmp(node a, node b) { return a.key < b.key; }
//int main()
//{
//	cin >> N >> head;
//	input.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d %d %d", &input[i].addr, &input[i].key, &input[i].next);
//		add2index[input[i].addr] = i;
//	}
//	if (add2index.find(head) != add2index.end())
//		for (int i = head; i != -1; i = input[add2index[i]].next)
//			List.push_back(input[add2index[i]]);
//	else 
//	{
//		cout << 0 << " " << -1;
//		return 0;
//	}
//	sort(List.begin(), List.end(), cmp);
//	printf("%d %05d\n", List.size(), List[0].addr);
//	for (int i = 0; i < List.size(); i++)
//	{
//		if (i != List.size() - 1)printf("%05d %d %05d\n", List[i].addr, List[i].key, List[i + 1].addr);
//		else printf("%05d %d %d\n", List[i].addr, List[i].key, -1);
//	}
//}

/*1029: 排序*/
//#pragma warning (disable:4996)
//#include<iostream>
//using namespace std;
//int s[2][200005];
//int N, M;
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)scanf("%d", &s[0][i]);
//	cin >> M;
//	for (int i = 0; i < M; i++)scanf("%d", &s[1][i]);
//	int i[2] = { 0 }, cnt = 0, curr;
//	if (s[0][0] < s[1][0])curr = 0; else curr = 1;
//	while (cnt != (M + N - 1) / 2)
//	{
//		i[curr]++;
//		if (i[0] == N)curr = 1;
//		else if (i[1] == M)curr = 0;
//		else if (s[0][i[0]] < s[1][i[1]])curr = 0;
//		else curr = 1;
//		cnt++;
//	}
//	cout << s[curr][i[curr]];
//}

/*数学2.1*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N, maxp;
//vector<int>primes, tempsol, commsol;
//vector<vector<int>>sol, res;
//void getAllprime()
//{
//	int isp = 0;
//	for (int i = 2; i <= maxp; i++)
//	{
//		isp = 1;
//		for (auto j : primes)
//		{
//			if (i % j == 0)
//			{
//				isp = 0;
//				break;
//			}
//		}
//		if (isp)primes.push_back(i);
//	}
//}
//void getSol(int common, int index)
//{
//	for (int i = index + 1; i < primes.size(); i++)
//	{
//		if (primes[i] - tempsol.back() == common)
//			tempsol.push_back(primes[i]);
//		if (tempsol.size() == N)
//		{
//			sol.push_back(tempsol);
//			commsol.push_back(common);
//			return;
//		}
//	}
//}
//int cmp(vector<int>a, vector<int>b) { return a[0] > b[0]; }
//int main()
//{
//	cin >> N >> maxp;
//	primes.push_back(2);
//	getAllprime();
//	if (primes.size() < N)
//	{
//		cout << primes.back();
//		return 0;
//	}
//	for (int i = primes.size() - N; i >= 0; i--)
//	{
//		for (int j = i + 1; j < primes.size(); j++)
//		{
//			tempsol.clear();
//			tempsol.push_back(primes[i]);
//			tempsol.push_back(primes[j]);
//			getSol(primes[j] - primes[i], j);
//		}
//	}
//	if (sol.size() == 0)cout << primes.back();
//	else
//	{
//		int maxcommon = 0;
//		for (int i = 0; i < sol.size(); i++)
//		{
//			if (commsol[i] > maxcommon)
//			{
//				res.clear();
//				res.push_back(sol[i]);
//				maxcommon = commsol[i];
//			}
//			else if (commsol[i] == maxcommon)
//				res.push_back(sol[i]);
//		}
//		sort(res.begin(), res.end(), cmp);
//		for (int i = 0; i < res[0].size(); i++)
//		{
//			if (i != res[0].size() - 1)cout << res[0][i] << " ";
//			else cout << res[0][i];
//		}
//	}
//}

/*dp2.2*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//vector<pair<int, int>>req;
//int dp[2005];
//int cmp(pair<int, int>a, pair<int, int>b) { return a.first < b.first; }
//int main()
//{
//	int a, b, c;
//	cin >> N;
//	req.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d:%d:%d", &a, &b, &c);
//		req[i].first = a * 3600 + b * 60 + c;
//		scanf("%d:%d:%d", &a, &b, &c);
//		req[i].second = a * 3600 + b * 60 + c;
//	}
//	sort(req.begin(), req.end(), cmp);
//	for (int i = N - 1; i >= 0; i--)
//	{
//		int j;
//		for (j = i + 1; j < N && req[j].first < req[i].second; j++);
//		dp[i] = max(dp[i + 1], dp[j] + 1);
//	}
//	cout << dp[0];
//}

/*堆2.3*/
//#include<iostream>
//#include<string>
//#include<vector>
//#include<unordered_map>
//#include<math.h>
//using namespace std;
//int N, M;
//int tree[2100];
//unordered_map<int, int>pos;
//void checktree(int index)
//{
//	int father = (index - 1) / 2, i = index;
//	while (father >= 0 && tree[i] > tree[father])
//	{
//		swap(tree[i], tree[father]);
//		i = father;
//		father = (father - 1) / 2;
//	}
//}
//pair<int, int> getNum(string s)
//{
//	vector<char>n;
//	pair<int, int>res;
//	res.first = res.second = 0;
//	int num = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')n.push_back(s[i]);
//		else
//		{
//			if (num == 0)
//				for (int k = 0; k < n.size(); k++)
//					res.first += (n[k] - '0') * pow(10, n.size() - k - 1);
//			else
//				for (int k = 0; k < n.size(); k++)
//					res.second += (n[k] - '0') * pow(10, n.size() - k - 1);
//			num++;
//			n.clear();
//		}
//	}
//	if (!n.empty())
//	{
//		for (int k = n.size() - 1; k >= 0; k--)
//			if (n[k] != '-')res.second += (n[k] - '0') * pow(10, n.size() - k - 1);
//			else res.second = -res.second;
//	}
//	return res;
//}
//int main()
//{
//	vector<int>out;
//	string s;
//	int x, y;
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> tree[i];
//		checktree(i);
//	}
//	cin.get();
//	for (int i = 0; i < N; i++)pos[tree[i]] = i;
//	for (int i = 0; i < M; i++)
//	{
//		getline(cin, s);
//		pair<int, int>num = getNum(s);
//		int digitnum = 0;
//		for (int l = num.first; l > 0; l /= 10)digitnum++;
//		if (s.back() == 't')
//		{
//			x = num.first;
//			if (tree[0] == x)out.push_back(1);
//			else out.push_back(0);
//		}
//		if (s.back() == 's')
//		{
//			x = num.first, y = num.second;
//			if (pos.find(x) == pos.end() || pos.find(y) == pos.end() || x == y)
//			{
//				out.push_back(0);
//				continue;
//			}
//			if ((pos[x] - 1) / 2 == (pos[y] - 1) / 2)out.push_back(1);
//			else out.push_back(0);
//		}
//		if (s[digitnum + 8] == 'p' && s[digitnum + 9] == 'a')
//		{
//			x = num.first, y = num.second;
//			if (pos.find(x) == pos.end() || pos.find(y) == pos.end() || x == y)
//			{
//				out.push_back(0);
//				continue;
//			}
//			if ((pos[y] - 1) / 2 == pos[x])out.push_back(1);
//			else out.push_back(0);
//		}
//		if (s[digitnum + 8] == 'l' && s[digitnum + 9] == 'e')
//		{
//			x = num.first, y = num.second;
//			if (pos.find(x) == pos.end() || pos.find(y) == pos.end() || x == y)
//			{
//				out.push_back(0);
//				continue;
//			}
//			if (2 * pos[y] + 1 == pos[x])out.push_back(1);
//			else out.push_back(0);
//		}
//
//		if (s[digitnum + 8] == 'r' && s[digitnum + 9] == 'i')
//		{
//			x = num.first, y = num.second;
//			if (pos.find(x) == pos.end() || pos.find(y) == pos.end() || x == y)
//			{
//				out.push_back(0);
//				continue;
//			}
//			if (2 * pos[y] + 2 == pos[x])out.push_back(1);
//			else out.push_back(0);
//		}
//	}
//	for (auto i : out)cout << i;
//}

/*floyd2.4*/
//#include<iostream>
//using namespace std;
//int N, M;
//int graph[205][205], dis[205][205];
//void floyd()
//{
//	for (int k = 0; k <= N; k++)
//		for (int i = 0; i <= N; i++)
//			for (int j = 0; j <= N; j++)
//				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
//}
//int main()
//{
//	int a, b, c;
//	cin >> N >> M;
//	for (int i = 0; i <= N; i++)
//		for (int j = 0; j <= N; j++)
//			graph[i][j] = 0x2fffffff;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		graph[a][b] = graph[b][a] = c;
//	}
//	floyd();
//	int visited[205] = { 0 }, curr = 0, total = 0, index, mindis;
//	cout << 0;
//	visited[0] = 1;
//	for (int i = 0; i < N; i++)
//	{
//		index = -1, mindis = 0x2fffffff;
//		for (int j = 0; j <= N; j++)
//		{
//			if (!visited[j] && graph[curr][j] < mindis)
//			{
//				index = j;
//				mindis = graph[curr][j];
//			}
//		}
//		if (index == -1)break;
//		visited[index] = 1;
//		cout << " " << index;
//		curr = index;
//		total += mindis;
//	}
//	cout << endl;
//	if (index == -1)
//	{
//		int f = 0;
//		for (int i = 0; i <= N; i++)
//			if (!visited[i])
//				if (f == 0)
//				{
//					cout << i;
//					f = 1;
//				}
//				else cout << " " << i;
//	}
//	else cout << total;
//}

/*欧拉筛法寻找n以内的素数*/
//#include<iostream>
//#include<vector>
//#include<time.h>
//using namespace std;
//int flag[2000000];
//void findNum(int x)
//{
//	vector<int>prime;
//	for (int i = 0; i <= x; i++)flag[i] = 1;
//	for (int i = 2; i <= x; i++)
//	{
//		if (flag[i])
//		{
//			prime.push_back(i);
//			for (int j = i; j * i <= x; j++)
//				flag[j * i] = 0;
//		}
//	}
//	for (auto i : prime)cout << i << " ";
//}
//int main()
//{
//	int N;
//	cin >> N;
//	clock_t start = clock();
//	findNum(N);
//	clock_t finish = clock();
//	printf("\nProgram runs %f secs", (double)(finish - start) / CLOCKS_PER_SEC);
//}

/*1016: 模拟*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<map>
//int rate[24];
//int N, mon, daycost;
//using namespace std;
//class date
//{
//public:
//	int day, hour, minute;
//	int date2int()
//	{
//		return minute + hour * 60 + day * 24 * 60;
//	}
//};
//class call
//{
//public:
//	string id;
//	int t, flag;
//};
//vector<call>record, info;
//date int2date(int x)
//{
//	date d;
//	d.day = x / 1440;
//	d.hour = (x - d.day * 1440) / 60;
//	d.minute = x - d.day * 1440 - d.hour * 60;
//	return d;
//}
//int cost(int a, int b)
//{
//	int sum = 0;
//	date d1 = int2date(a), d2 = int2date(b);
//	if (d1.day != d2.day)
//	{
//		sum += (60 - d1.minute) * rate[d1.hour];
//		for (int i = d1.hour + 1; i < 24; i++)
//			sum += 60 * rate[i];
//		for (int i = d1.day + 1; i < d2.day; i++)
//			sum += daycost;
//		for (int i = 0; i < d2.hour; i++)
//			sum += 60 * rate[i];
//		sum += d2.minute * rate[d2.hour];
//	}
//	else if (d1.hour != d2.hour)
//	{
//		sum += (60 - d1.minute) * rate[d1.hour];
//		for (int i = d1.hour + 1; i < d2.hour; i++)
//			sum += 60 * rate[i];
//		sum += d2.minute * rate[d2.hour];
//	}
//	else
//		sum += (d2.minute - d1.minute) * rate[d1.hour];
//	return sum;
//}
//int cmp(call a, call b)
//{
//	if (a.id < b.id)return 1;
//	else if (a.id == b.id && a.t < b.t)return 1;
//	return 0;
//}
//int main()
//{
//	string s;
//	date d;
//	for (int i = 0; i < 24; i++)
//	{
//		cin >> rate[i];
//		daycost += 60 * rate[i];
//	}
//	cin >> N;
//	record.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> record[i].id;
//		scanf("%d:%d:%d:%d", &mon, &d.day, &d.hour, &d.minute);
//		cin >> s;
//		if (s == "on-line")record[i].flag = 1;
//		else record[i].flag = -1;
//		record[i].t = d.date2int();
//	}
//	sort(record.begin(), record.end(), cmp);
//	//record--->info
//	string curr = record[0].id;
//	int state = -1;
//	for (int i = 0; i < record.size(); i++)
//	{
//		date d = int2date(record[i].t);
//		if (record[i].id != curr)
//		{
//			curr = record[i].id;
//			state = -1;
//		}
//		if (record[i].flag == 1)
//			state = 1;
//		else if (state == 1)
//		{
//			info.push_back(record[i - 1]);
//			info.push_back(record[i]);
//			state = -1;
//		}
//	}
//	curr = info[0].id;
//	printf("%s %02d\n", curr.c_str(), mon);
//	double pay = 0;
//	date d1, d2;
//	for (int i = 0; i < info.size(); i++)
//	{
//		if (info[i].id != curr)
//		{
//			curr = info[i].id;
//			printf("Total amount: $%.2f\n", pay);
//			printf("%s %02d\n", curr.c_str(), mon);
//			pay = 0;
//		}
//		if (info[i].flag == -1)
//		{
//			d1 = int2date(info[i - 1].t);
//			d2 = int2date(info[i].t);
//			double c = (double)cost(info[i - 1].t, info[i].t) / 100;
//			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", d1.day, d1.hour, d1.minute,
//				d2.day, d2.hour, d2.minute, info[i].t - info[i - 1].t, c);
//			pay += c;
//		}
//	}
//	printf("Total amount: $%.2f\n", pay);
//}

/*1049: 数学问题*/
//#include<iostream>
//using namespace std;
//int p[40];//p[i]=1-9...9(9*i)
//string N;
//void getNum(int x)
//{
//	for (int i = 1; i <= x; i++)
//		p[i] = 9 * p[i - 1] + pow(10, i - 1);
//}
//int main()
//{
//	cin >> N;
//	getNum(N.size());
//	int sum = 0;
//	for (int i = 0; i < N.size(); i++)
//	{
//		if (i == 0)sum += p[N.size() - 1];
//		else
//		{
//			for (int j = 1; j < N[i - 1] - '0'; j++)
//			{
//				if (j == 1)sum += pow(10, N.size() - i - 1) - 1;
//				sum += p[N.size() - i];
//			}
//		}
//	}
//	int num1 = 0;
//	for (int i = 0; i < N.size() - 1; i++)
//		if (N[i] == '1')num1++;
//	sum += (N.back() - '0' + 1) * num1;
//	if (N.back() >= '1')sum++;
//	cout << sum << " " << p[N.size()];
//}