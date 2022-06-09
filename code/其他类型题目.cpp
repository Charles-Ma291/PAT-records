/*1007：动态规划*/
/*二维矩阵方法太耗时，转用动规*/
//#include<iostream>
//using namespace std;
//long long mat[10000][10000];
//long long main()
//{
//	long long N, Max = -0x3fffffff;
//	pair<long long, long long>index;
//	cin >> N;
//	for (long long i = 0; i < N; i++)
//	{
//		cin >> mat[i][i];
//		if (mat[i][i] > Max)
//		{
//			Max = mat[i][i];
//			index.first = index.second = i;
//		}
//		else if (mat[i][i] == Max && i < index.first && i < index.second)
//		{
//			index.first = index.second = i;
//		}
//		for (long long j = i - 1; j >= 0; j--)
//		{
//			mat[j][i] = mat[j][j] + mat[j + 1][i];
//			if (mat[j][i] > Max)
//			{
//				Max = mat[j][i];
//				index.first = j;
//				index.second = i;
//			}
//			else if (mat[j][i] == Max && j < index.first && j < index.second)
//			{
//				index.first = j;
//				index.second = i;
//			}
//		}
//	}
//	if (Max < 0)
//		cout << 0 << " " << mat[0][0] << " " << mat[N - 1][N - 1];
//	else cout << Max << " " << mat[index.first][index.first] << " " << mat[index.second][index.second];
//}

//#include<iostream>
//using namespace std;
//long long num[10000];
//long long main()
//{
//	long long N, cur = 0, sum = -0x3fffffff;
//	pair<long long, long long>pos1(0, 0), pos2(0, 0);
//	cin >> N;
//	for (long long i = 0; i < N; i++)
//	{
//		cin >> num[i];
//		cur += num[i];
//		pos1.second = i;
//		if (cur > sum)
//		{
//			sum = cur;
//			pos2 = pos1;
//		}
//		if (cur < 0)
//		{
//			cur = 0;
//			pos1.first = i + 1;
//		}
//	}
//	if (sum < 0)cout << 0 << " " << num[0] << " " << num[N - 1];
//	else cout << sum << " " << num[pos2.first] << " " << num[pos2.second];
//}

/*1040：动态规划*/
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//long long d[1001][1001];
//long long main()
//{
//	string str;
//	getline(cin, str);
//	long long length = str.size(), ans = 1;
//	for (long long i = 0; i < length; i++)
//	{
//		d[i][i] = 1;
//		if (i < length - 1 && str[i] == str[i + 1])
//		{
//			d[i][i + 1] = 1;
//			ans = 2;
//		}
//	}
//	for (long long L = 3; L <= length; L++)
//	{
//		for (long long i = 0; i + L <= length; i++)
//		{
//			if (str[i] == str[i + L - 1])
//			{
//				d[i][i + L - 1] = d[i + 1][i + L - 2];
//				if (d[i][i + L - 1])ans = L;
//			}
//		}
//	}
//	cout << ans;
//}

/*1045: 动态规划*/
//#include<iostream>
//using namespace std;
//long long n;
//long long order[201];
//long long colors[10002];
//long long dp[10002][201];
//long long main()
//{
//	long long N, t;
//	cin >> N;
//	cin >> N;
//	for (long long i = 0; i < N; i++)
//	{
//		cin >> t;
//		order[t] = i + 1;
//	}
//	cin >> n;
//	for (long long i = 0; i < n; i++)
//		cin >> colors[i];
//	for (long long i = n - 1; i >= 0; i--)
//	{
//		long long level = 1;
//		for (long long j = i; j < n; j++)
//		{
//			long long new_level = order[colors[j]];
//			if (j == n - 1)
//			{
//				if (new_level != 0)
//					for (long long k = 1; k <= new_level; k++)
//						dp[j][k] = 1;
//			}
//			else
//			{
//				if (new_level < level)
//				{
//					if (new_level == 0)
//						for (long long k = 1; k <= N; k++)
//							dp[j][k] = dp[j + 1][k];
//					else
//						for (long long k = new_level; k < level; k++)
//							dp[j][k] = dp[j + 1][k];
//				}
//				else if (new_level == level)dp[j][level] = dp[j + 1][level] + 1;
//				else
//				{
//					if (dp[j + 1][level] > dp[j + 1][new_level] + 1)
//					{
//						dp[j][level] = dp[j + 1][level];
//					}
//					else
//					{
//						dp[j][level] = dp[j + 1][new_level] + 1;
//						for (long long k = level + 1; k <= new_level; k++)
//							dp[j][k] = dp[j][level];
//						level = new_level;
//					}
//				}
//			}
//		}
//	}
//	//for (long long i = 0; i < n; i++)
//	//{
//	//	for (long long j = 1; j <= N; j++)
//	//		cout << dp[i][j] << " ";
//	//	cout << endl;
//	//}
//	cout << dp[0][1];
//}

/*1068: 动态规划*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//long long dp[10001][101];
//long long need[10001][101];
//vector<long long>s, ans;
//long long main()
//{
//	long long N, M;
//	cin >> N >> M;
//	s.resize(N + 1);
//	for (long long i = 1; i <= N; i++)
//		cin >> s[i];
//	sort(s.begin() + 1, s.end(), greater<long long>());
//	for (long long i = 1; i <= N; i++)
//	{
//		for (long long j = 1; j <= M; j++)
//		{
//			if (s[i] <= j && dp[i - 1][j - s[i]] + s[i] >= dp[i - 1][j])
//			{
//				dp[i][j] = dp[i - 1][j - s[i]] + s[i];
//				need[i][j] = 1;
//			}
//			else
//				dp[i][j] = dp[i - 1][j];
//		}
//	}
//	long long a = N, b = M;
//	while (a > 0)
//	{
//		if (need[a][b])
//		{
//			ans.push_back(s[a]);
//			b -= s[a];
//		}
//		a--;
//	}
//	if (dp[N][M])cout << "No Solution";
//	else
//		for (long long i = 0; i < ans.size(); i++)
//			if (i != ans.size() - 1)
//				cout << ans[i] << " ";
//			else cout << ans[i];
//}

/*1010: 二分查找*/
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//string n1, n2;
//long long tag, ra;
//long long N1;
//long long getNum(long long r)
//{
//	 long long sum = 0;
//	for (long long i = n2.size() - 1; i >= 0; i--)
//	{
//		if (n2[i] >= '0' && n2[i] <= '9')
//			sum += (n2[i] - '0') * pow(r, n2.size() - 1 - i);
//		else
//			sum += (n2[i] - 'a' + 10) * pow(r, n2.size() - 1 - i);
//	}
//	return sum;
//}
//long long calculate(long long a, long long b)
//{
//	if (a > b)return -1;
//	long long r = (a + b) / 2;
//	long long t = getNum(r);
//	if (t == N1)return r;
//	if (t > N1)
//		return calculate(a, r - 1);
//	if (t < N1)
//		return calculate(r + 1, b);
//}
//long long main()
//{
//	char p = '0';
//	long long min_radix, max_radix, least;
//	long long last, cur;
//	cin >> n1 >> n2 >> tag >> ra;
//	if (tag == 2)swap(n1, n2);
//	for (long long i = n1.size() - 1; i >= 0; i--)
//	{
//		if (n1[i] >= '0' && n1[i] <= '9')
//			N1 += (n1[i] - '0') * pow(ra, n1.size() - 1 - i);
//		else N1 += (n1[i] - 'a' + 10) * pow(ra, n1.size() - 1 - i);
//	}
//
//	for (long long i = 0; i < n2.size(); i++)
//		if (n2[i] > p)p = n2[i];
//
//	if (p >= '0' && p <= '9')min_radix = p - '0' + 1;
//	else min_radix = p - 'a' + 10 + 1;
//
//	last = getNum(min_radix);
//	least = min_radix;
//	for (max_radix = min_radix + 10;; max_radix += 10)
//	{
//		cur = getNum(max_radix);
//		if (cur == last || cur > N1)break;
//		min_radix = max_radix;
//		last = cur;
//	}
//	long long radix = calculate(min_radix, max_radix);
//	if (radix < 0)cout << "Impossible";
//	else
//	{
//		while (getNum(radix - 1) == N1 && radix - 1 >= least)radix--;
//		cout << radix;
//	}
//}

/*1044: 二分查找*/

/*有一个测试点超时*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//int N, M, cost = 0x3fffffff;
//int c[100001];
//int sum[100001];
//vector<pair<int, int>>ans;
//vector<pair<int, int>>mincost;
//int cmp(pair<int, int>a, pair<int, int>b) { return a.first < b.first; }
//void getChain(int x, int y)
//{
//	if (x > y || sum[y] - sum[x] + c[x] < M)return;
//	if (sum[y] - sum[x] + c[x] == M)
//	{
//		ans.push_back(pair<int, int>(x, y));
//		return;
//	}
//	if (ans.empty())
//	{
//		if (sum[y] - sum[x] + c[x] > M && sum[y] - sum[x] + c[x] <= cost)
//		{
//			if (sum[y] - sum[x] + c[x] < cost)
//			{
//				cost = sum[y] - sum[x] + c[x];
//				mincost.clear();
//			}
//			mincost.push_back(pair<int, int>(x, y));
//		}
//	}
//	if (x == y)return;
//	int r = (x + y) / 2, sum = 0;
//	for (int i = r; i >= x && sum <= M; i--)
//	{
//		sum += c[i];
//		int temp = sum;
//		for (int j = r + 1; j <= y && sum <= M; j++)
//		{
//			sum += c[j];
//			if (sum == M)
//			{
//				ans.push_back(pair<int, int>(i, j));
//			}
//		}
//		sum = temp;
//	}
//	sum = 0;
//	if (ans.empty())
//	{
//		for (int i = r; i >= x && sum <= cost; i--)
//		{
//			sum += c[i];
//			int temp = sum;
//			for (int j = r + 1; j <= y && sum <= cost; j++)
//			{
//				sum += c[j];
//				if (sum > M && sum <= cost)
//				{
//					if (sum < cost)
//					{
//						mincost.clear();
//						cost = sum;
//					}
//					mincost.push_back(pair<int, int>(i, j));
//				}
//			}
//			sum = temp;
//		}
//	}
//	getChain(x, r);
//	getChain(r + 1, y);
//}
//int main()
//{
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> c[i];
//		sum[i] = sum[i - 1] + c[i];
//	}
//	getChain(1, N);
//	if (ans.empty())
//	{
//		sort(mincost.begin(), mincost.end(), cmp);
//		for (int i = 0; i < mincost.size(); i++)
//		{
//			if (i == 0 || mincost[i] != mincost[i - 1])cout << mincost[i].first << "-" << mincost[i].second << endl;
//		}
//	}
//	else
//	{
//		sort(ans.begin(), ans.end(), cmp);
//		for (int i = 0; i < ans.size(); i++)
//		{
//			if (i == 0 || ans[i] != ans[i - 1])cout << ans[i].first << "-" << ans[i].second << endl;
//		}
//	}
//}

/*1085: 二分查找*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//long long N, p;
//vector<long long>n;
//int getNum(long long x, long long y)
//{
//	long long left = x, right = y, r = right;
//	long long s = n[x] * p;
//	while (left < r)
//	{
//		if (n[r - 1] <= s)
//		{
//			if (r == right)return r - x;
//			left = r;
//			r = (r + right) / 2 + 1;
//		}
//		else
//		{
//			right = r;
//			r = (r + left) / 2;
//		}
//	}
//	return r - x;
//}
//int main()
//{
//	cin >> N >> p;
//	n.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> n[i];
//	sort(n.begin(), n.end());
//	int cnt = 0, cur;
//	for (int i = 0; i < N && N - i>cnt; i++)
//	{
//		cur = getNum(i, N);
//		if (cur > cnt)cnt = cur;
//	}
//	cout << cnt;
//}

/*1033: 贪心算法*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//double C, D, gas, N;
//vector<pair<double, double>>s;
//int cmp(pair<double, double>a, pair<double, double>b) { return a.second < b.second; }
//int main()
//{
//	cin >> C >> D >> gas >> N;
//	s.resize(N + 1);
//	for (int i = 0; i < N; i++)
//		cin >> s[i].first >> s[i].second;
//	s[N].first = 0, s[N].second = D;
//	sort(s.begin(), s.end(), cmp);
//	double i = 0, c = 0, maxd = C * gas, cnt = 0;
//	if (s[i].second != 0)
//	{
//		printf("The maximum travel distance = %.2f", 0);
//		return 0;
//	}
//	while (s[i].first > 0)
//	{
//		int j = i + 1;
//		for (; s[j].second - s[i].second <= maxd; j++)
//			if (s[j].first < s[i].first)break;
//		//没找到便宜的油站
//		int k = i + 1;
//		double m = 0x3fffffff, index, need;
//		if (s[j].second - s[i].second > maxd)
//		{
//			//不可达
//			if (j == i + 1)
//			{
//				printf("The maximum travel distance = %.2f", s[i].second + maxd);
//				return 0;
//			}
//			cnt += (C - c) * s[i].first;
//			c = C;
//			for (; k < j; k++)
//			{
//				if (s[k].first < m)
//				{
//					m = s[k].first;
//					index = k;
//				}
//			}
//			//向相对便宜的油站出发
//			c -= (s[index].second - s[i].second) / gas;
//			i = index;
//		}
//		else//找到了
//		{
//			need = (s[j].second - s[i].second) / gas;
//			if (need <= c)c -= need;
//			else
//			{
//				need -= c;
//				c = 0;
//				cnt += need * s[i].first;
//			}
//			i = j;
//		}
//	}
//	printf("%.2f", cnt);
//}

/*1037: 贪心算法*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//vector<long long>pc, nc, pb, nb;
//int main()
//{
//	long long sum = 0;
//	long long t;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> t;
//		if (t >= 0)pc.push_back(t);
//		else nc.push_back(t);
//	}
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> t;
//		if (t >= 0)pb.push_back(t);
//		else nb.push_back(t);
//	}
//	sort(pc.begin(), pc.end(), greater<int>());
//	sort(pb.begin(), pb.end(), greater<int>());
//	sort(nc.begin(), nc.end());
//	sort(nb.begin(), nb.end());
//	for (int i = 0; i < pc.size() && i < pb.size(); i++)
//		sum += pc[i] * pb[i];
//	for (int i = 0; i < nc.size() && i < nb.size(); i++)
//		sum += nc[i] * nb[i];
//	cout << sum;
//}

/*1038: 贪心算法*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int N;
//vector<string>s;
//int cmp(string a, string b)
//{
//	int i;
//	for (i = 0; i < a.size() && i < b.size(); i++)
//	{
//		if (a[i] < b[i])return 1;
//		if (a[i] > b[i])return 0;
//	}
//	if (i == a.size())
//	{
//		for (int ai = 0; ai < a.size(); ai++)
//		{
//			for (int bi = i; bi < b.size(); bi++)
//			{
//				if (a[ai] > b[bi])return 0;
//				if (a[ai] < b[bi])return 1;
//			}
//		}
//		return 0;
//	}
//	if (i == b.size())
//	{
//		for (int bi = 0; bi < b.size(); bi++)
//		{
//			for (int ai = i; ai < a.size(); ai++)
//			{
//				if (a[ai] > b[bi])return 0;
//				if (a[ai] < b[bi])return 1;
//			}
//		}
//		return 0;
//	}
//}
//int main()
//{
//	cin >> N;
//	s.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> s[i];
//	sort(s.begin(), s.end(), cmp);
//	int flag = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		for (int j = 0; j < s[i].size(); j++)
//		{
//			if (s[i][j] != '0')flag = 1;
//			if (flag)cout << s[i][j];
//		}
//	}
//	if (!flag)cout << 0;
//}

