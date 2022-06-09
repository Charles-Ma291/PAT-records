//PART5：排序

/*1012*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int grades[1000000][4];
//int stu[1000000];
//vector<pair<int, int>>C, M, E, A;
//vector<int>querys;
//int n, m;
//int cmp(pair<int, int>a, pair<int, int>b) { return a.second > b.second; }
//int main()
//{
//	int a, b, c, d;
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a >> b >> c >> d;
//		stu[a] = 1;
//		grades[a][1] = b;
//		grades[a][2] = c;
//		grades[a][3] = d;
//		grades[a][0] = (b + c + d) / 3;
//		C.push_back(pair<int, int>(a, b));
//		M.push_back(pair<int, int>(a, c));
//		E.push_back(pair<int, int>(a, d));
//		A.push_back(pair<int, int>(a, grades[a][0]));
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a;
//		querys.push_back(a);
//	}
//	sort(C.begin(), C.end(), cmp);
//	sort(E.begin(), E.end(), cmp);
//	sort(M.begin(), M.end(), cmp);
//	sort(A.begin(), A.end(), cmp);
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0)grades[A[i].first][0] = i + 1;
//		else if (A[i].second == A[i - 1].second)grades[A[i].first][0] = grades[A[i - 1].first][0];
//		else grades[A[i].first][0] = i + 1;
//
//		if (i == 0)grades[C[i].first][1] = i + 1;
//		else if (C[i].second == C[i - 1].second)grades[C[i].first][1] = grades[C[i - 1].first][1];
//		else grades[C[i].first][1] = i + 1;
//
//		if (i == 0)grades[M[i].first][2] = i + 1;
//		else if (M[i].second == M[i - 1].second)grades[M[i].first][2] = grades[M[i - 1].first][2];
//		else grades[M[i].first][2] = i + 1;
//
//		if (i == 0)grades[E[i].first][3] = i + 1;
//		else if (E[i].second == E[i - 1].second)grades[E[i].first][3] = grades[E[i - 1].first][3];
//		else grades[E[i].first][3] = i + 1;
//
//	}
//	for (int i = 0; i < m; i++)
//	{
//		if (stu[querys[i]])
//		{
//			int rank = 0x3fffffff, index;
//			for (int j = 0; j < 4; j++)
//			{
//				if (grades[querys[i]][j] < rank)
//				{
//					rank = grades[querys[i]][j];
//					index = j;
//				}
//			}
//			switch (index)
//			{
//			case 0:
//				cout << rank << " A" << endl;
//				break;
//			case 1:
//				cout << rank << " C" << endl;
//				break;
//			case 2:
//				cout << rank << " M" << endl;
//				break;
//			case 3:
//				cout << rank << " E" << endl;
//				break;
//			}
//		}
//		else cout << "N/A" << endl;
//	}
//}

/*1016*/
/*过于复杂，debug失败*/
//#pragma warning(disable : 4996)
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<iomanip>
//using namespace std;
//int rates[24], N;
//map<string, int>name2id;
//string id2name[1002];
//class call
//{
//public:
//	int time[4];
//	int name, flag;
//};
//class bill
//{
//public:
//	int start[4], finish[4], lasting;
//	int cnt;
//};
//vector<call>records[1002];
//vector<bill>res[1002];
//int cmp(call a, call b)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (a.time[i] < b.time[i])return 1;
//		if (a.time[i] > b.time[i])return 0;
//	}
//	return 0;
//}
//int main()
//{
//	string n;
//	for (int i = 0; i < 24; i++)
//		cin >> rates[i];
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		call t;
//		cin >> n;
//		if (name2id.find(n) == name2id.end())name2id[n] = name2id.size();
//		t.name = name2id[n];
//		id2name[t.name] = n;
//		scanf("%d:%d:%d:%d", &t.time[0], &t.time[1], &t.time[2], &t.time[3]);
//		cin >> n;
//		if (n == "on-line")t.flag = 1;
//		else t.flag = 0;
//		records[t.name].push_back(t);
//	}
//	for (auto p = name2id.begin(); p != name2id.end(); p++)
//	{
//		call prev = records[p->second][0];
//		sort(records[p->second].begin(), records[p->second].end(), cmp);
//		for (int i = 1; i < records[p->second].size(); i++)
//		{
//			call curr = records[p->second][i];
//			if (curr.flag != prev.flag && prev.flag == 1)
//			{
//				bill t;
//				for (int j = 0; j < 4; j++)
//				{
//					t.start[j] = prev.time[j];
//					t.finish[j] = curr.time[j];
//				}
//				if (t.start[1] == t.finish[1])
//				{
//					if (t.start[2] == t.finish[2])
//					{
//						t.cnt = rates[t.start[2]] * (t.finish[3] - t.start[3]);
//						t.lasting = t.finish[3] - t.start[3];
//					}
//					else
//					{
//						t.cnt = rates[t.start[2]] * (60 - t.start[3]);
//						t.lasting = (60 - t.start[3]);
//						for (int j = t.start[2] + 1; j < t.finish[2]; j++)
//						{
//							t.cnt += rates[j] * 60;
//							t.lasting += 60;
//						}
//						t.cnt += rates[t.finish[3]] * t.finish[3];
//						t.lasting += t.finish[3];
//					}
//				}
//				else
//				{
//					int day1 = t.start[1], day2 = t.finish[1];
//					int h1 = t.start[2], h2 = t.finish[2];
//					int m1 = t.start[3], m2 = t.finish[3];
//					t.cnt = rates[h1] * (60 - m1);
//					t.lasting = (60 - m1);
//					for (int j = h1 + 1; j < 24; j++)
//					{
//						t.cnt += rates[j] * 60;
//						t.lasting += 60;
//					}
//					t.cnt += rates[h2] * m2;
//					t.lasting += m2;
//					for (int j = 0; j < h2; j++)
//					{
//						t.cnt += rates[j] * 60;
//						t.lasting += 60;
//					}
//					for (int j = day1 + 1; j < day2; j++)
//					{
//						for (int k = 0; k < 24; k++)
//						{
//							t.cnt += rates[k] * 60;
//							t.lasting += 60;
//						}
//					}
//				}
//				res[p->second].push_back(t);
//			}
//			prev = curr;
//		}
//	}
//	for (auto p = name2id.begin(); p != name2id.end(); p++)
//	{
//		int month = -1, total = 0;
//		for (int i = 0; i < res[p->second].size(); i++)
//		{
//			if (month != res[p->second][i].start[0])
//			{
//				if (i != 0)cout << "Total amount: $" << setiosflags(ios::fixed) << setprecision(2) << (double)total / 100 << endl;
//				cout << p->first << " ";
//				printf("%02d\n", res[p->second][i].start[0]);
//				month = res[p->second][i].start[0];
//				total = 0;
//			}
//			total += res[p->second][i].cnt;
//			printf("%02d:%02d:%02d %02d:%02d:%02d %d $", res[p->second][i].start[1], res[p->second][i].start[2], res[p->second][i].start[3],
//				res[p->second][i].finish[1], res[p->second][i].finish[2], res[p->second][i].finish[3], res[p->second][i].lasting);
//			cout << setiosflags(ios::fixed) << setprecision(2) << (double)res[p->second][i].cnt / 100 << endl;
//		}
//		cout << "Total amount: $" << setiosflags(ios::fixed) << setprecision(2) << (double)total / 100 << endl;
//	}
//}

/*1025*/
//#pragma warning(disable : 4996)
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//class test
//{
//public:
//	pair<ll, int>info;
//	int final_rank, location, local_rank;
//};
//class node
//{
//public:
//	int result, location, local_rank;
//	node(int a, int b, int c) :result(a), location(b), local_rank(c) {};
//};
//int N;
//vector<test>list;
//vector<pair<ll, int>>score[102];
//map<ll, vector<node>>record;//用于存id和对应的location，localrank
//int cmp1(test a, test b)
//{
//	if (a.info.second > b.info.second)return 1;
//	else if (a.info.second == b.info.second && a.info.first < b.info.first)return 1;
//	return 0;
//}
//int cmp2(pair<ll, int>a, pair<ll, int>b)
//{
//	if (a.second > b.second)return 1;
//	else if (a.second == b.second && a.first < b.first)return 1;
//	return 0;
//}
//int main()
//{
//	int k;
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> k;
//		for (int j = 0; j < k; j++)
//		{
//			pair<ll, int>t;
//			test T;
//			cin >> t.first >> t.second;
//			T.info = t;
//			record[t.first].push_back(node(t.second, i, 0));
//			score[i].push_back(t);
//			list.push_back(T);
//		}
//		sort(score[i].begin(), score[i].end(), cmp2);
//		int cur = 1;
//		for (int j = 0; j < k; j++)
//		{
//			if (!(j != 0 && score[i][j].second == score[i][j - 1].second))cur = j + 1;
//			record[score[i][j].first].back().local_rank = cur;
//		}
//	}
//	sort(list.begin(), list.end(), cmp1);
//	int cur = 1;
//	for (int i = 0; i < list.size(); i++)
//	{
//		if (!(i != 0 && list[i].info.second == list[i - 1].info.second))
//		{
//			cur = i + 1;
//		}
//		list[i].final_rank = cur;
//		ll id = list[i].info.first;
//		for (int j = 0; j < record[id].size(); j++)
//		{
//			if (record[id][j].result == list[i].info.second)
//			{
//				list[i].local_rank = record[id][j].local_rank;
//				list[i].location = record[id][j].location;
//			}
//		}
//	}
//
//	cout << list.size() << endl;
//	for (int i = 0; i < list.size(); i++)
//	{
//		printf("%15lld", list[i].info.first);
//		cout << " " << list[i].final_rank << " " << list[i].location << " " << list[i].local_rank << endl;
//	}
//}

/*1028*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class stu
//{
//public:
//	int id, grade;
//	string name;
//};
//int N, C;
//vector<stu>table;
//int cmp1(stu a, stu b) { return a.id < b.id; }
//int cmp2(stu a, stu b)
//{
//	if (a.name < b.name)return 1;
//	else if (a.name == b.name && a.id < b.id)return 1;
//	return 0;
//}
//int cmp3(stu a, stu b)
//{
//	if (a.grade < b.grade)return 1;
//	else if (a.grade == b.grade && a.id < b.id)return 1;
//	return 0;
//}
//int main()
//{
//	cin >> N >> C;
//	table.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> table[i].id >> table[i].name >> table[i].grade;
//	if (C == 1)sort(table.begin(), table.end(), cmp1);
//	if (C == 2)sort(table.begin(), table.end(), cmp2);
//	if (C == 3)sort(table.begin(), table.end(), cmp3);
//	for (int i = 0; i < N; i++)
//		printf("%06d %s %d\n", table[i].id, table[i].name.c_str(), table[i].grade);
//}

/*1055*/
//#pragma warning (disable:4996)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class person
//{
//public:
//	string name;
//	int age, wealth;
//};
//int N, K;
//int querys[1002][3];
//vector<person>people;
//int cmp(person a, person b)
//{
//	if (a.wealth > b.wealth)return 1;
//	else if (a.wealth == b.wealth && a.age < b.age)return 1;
//	else if (a.wealth == b.wealth && a.age == b.age && a.name < b.name)return 1;
//	return 0;
//}
//int main()
//{
//	cin >> N >> K;
//	people.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> people[i].name >> people[i].age >> people[i].wealth;
//	for (int i = 1; i <= K; i++)
//		cin >> querys[i][0] >> querys[i][1] >> querys[i][2];
//	sort(people.begin(), people.end(), cmp);
//	int num;
//	for (int i = 1; i <= K; i++)
//	{
//		printf("Case #%d:\n", i);
//		num = 0;
//		for (int j = 0; j < N && num < querys[i][0]; j++)
//		{
//			if (people[j].age >= querys[i][1] && people[j].age <= querys[i][2])
//			{
//				printf("%s %d %d\n", people[j].name.c_str(), people[j].age, people[j].wealth);
//				num++;
//			}
//		}
//		if (num == 0 && querys[i][0] != 0)cout << "None" << endl;
//	}
//}

/*1062*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class person
//{
//public:
//	int id, talent, virtue;
//};
//int N, L, H;
//vector<person>people;
//int getLevel(person a)
//{
//	if (a.talent >= L && a.virtue >= L)
//		if (a.talent >= H && a.virtue >= H)
//			return 1;
//		else if (a.talent < H && a.virtue >= H)
//			return 2;
//		else if (a.talent < H && a.virtue < H && a.virtue >= a.talent)
//			return 3;
//		else return 4;
//	else return 5;
//}
//int cmp(person a, person b)
//{
//	int la = getLevel(a), lb = getLevel(b);
//	if (la < lb)return 1;
//	else if (la == lb && a.virtue + a.talent > b.virtue + b.talent)return 1;
//	else if (la == lb && a.virtue + a.talent == b.virtue + b.talent && a.virtue > b.virtue)return 1;
//	else if (la == lb && a.virtue + a.talent == b.virtue + b.talent && a.virtue == b.virtue && a.id < b.id)return 1;
//	return 0;
//}
//int main()
//{
//	person temp;
//	cin >> N >> L >> H;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> temp.id >> temp.virtue >> temp.talent;
//		if (getLevel(temp) < 5)
//			people.push_back(temp);
//	}
//	sort(people.begin(), people.end(), cmp);
//	cout << people.size() << endl;
//	for (int i = 0; i < people.size(); i++)
//		printf("%08d %d %d\n", people[i].id, people[i].virtue, people[i].talent);
//}

/*1075*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//class stu
//{
//public:
//	int id, total_score, perfect, flag;
//	int s[6], ispush[6];
//	stu() { id = total_score = perfect = flag = 0; memset(s, 0, sizeof(s)); memset(ispush, 0, sizeof(ispush)); }
//};
//int N, M, K;
//int full_score[6];
//vector<stu>students;
//vector<vector<int>>submition;
//int cmpid(vector<int>a, vector<int>b) { return a[0] < b[0]; }
//int cmp(stu a, stu b)
//{
//	if (a.flag > b.flag)return 1;
//	if (a.flag < b.flag)return 0;
//	if (a.total_score > b.total_score)return 1;
//	else if (a.total_score == b.total_score)
//	{
//		if (a.perfect > b.perfect)return 1;
//		else if (a.perfect == b.perfect && a.id < b.id)return 1;
//	}
//	return 0;
//}
//int main()
//{
//	cin >> N >> K >> M;
//	submition.resize(M);
//	for (int i = 1; i <= K; i++)
//		cin >> full_score[i];
//	for (int i = 0; i < M; i++)
//	{
//		submition[i].resize(3);
//		cin >> submition[i][0] >> submition[i][1] >> submition[i][2];
//	}
//	sort(submition.begin(), submition.end(), cmpid);
//	for (int i = 0; i < M; i++)
//	{
//		if (students.empty()|| students.back().id != submition[i][0])
//		{
//			stu temp;
//			temp.ispush[submition[i][1]] = 1;
//			temp.id = submition[i][0];
//			if (submition[i][2] != -1)
//			{
//				temp.total_score += submition[i][2];
//				temp.s[submition[i][1]] = submition[i][2];
//				temp.flag = 1;
//				if (temp.s[submition[i][1]] == full_score[submition[i][1]])temp.perfect++;
//			}
//			students.push_back(temp);
//		}
//		else
//		{
//			stu& temp = students.back();
//			if (submition[i][2] != -1 && temp.s[submition[i][1]] < submition[i][2])
//			{
//				temp.total_score -= temp.s[submition[i][1]];
//				temp.s[submition[i][1]] = submition[i][2];
//				temp.total_score += temp.s[submition[i][1]];
//				temp.flag = 1;
//				if (temp.s[submition[i][1]] == full_score[submition[i][1]])temp.perfect++;
//			}
//			temp.ispush[submition[i][1]] = 1;
//		}
//	}
//	sort(students.begin(), students.end(), cmp);
//	int q = 0, last = -1;
//	for (int i = 0; i < students.size() && students[i].flag; i++)
//	{
//		if (students[i].total_score != last) { q = i + 1; last = students[i].total_score; }
//		printf("%d %05d %d", q, students[i].id, students[i].total_score);
//		for (int j = 1; j <= K; j++)
//			if (students[i].ispush[j])
//				cout << " " << students[i].s[j];
//			else cout << " -";
//		cout << endl;
//	}
//}

/*1080*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class stu
//{
//public:
//	int id;
//	int GE, GI;
//	int choices[6];
//};
//int N, M, K;
//vector<stu>application;
//int quota[100], exceed[100];
//vector<int>school[100];
//int cmp(stu a, stu b)
//{
//	if (a.GE + a.GI > b.GE + b.GI)return 1;
//	else if (a.GE + a.GI == b.GE + b.GI && a.GE > b.GE)return 1;
//	return 0;
//}
//int main()
//{
//	cin >> N >> M >> K;
//	application.resize(N);
//	for (int i = 0; i < M; i++)
//		cin >> quota[i];
//	for (int i = 0; i < N; i++)
//	{
//		cin >> application[i].GE >> application[i].GI;
//		application[i].id = i;
//		for (int j = 0; j < K; j++)
//			cin >> application[i].choices[j];
//	}
//	sort(application.begin(), application.end(), cmp);
//	int index = 0;
//	for (int i = 0; i < N; i++)
//	{
//		if (i != 0 && cmp(application[i - 1], application[i]))
//		{
//			for (int j = index; j < i; j++)
//			{
//				int k, prefered;
//				for (k = 0; k < K; k++)
//					if (!exceed[application[j].choices[k]])
//						break;
//				if (k != K)
//				{
//					prefered = application[j].choices[k];
//					quota[prefered]--;
//					school[prefered].push_back(application[j].id);
//				}
//			}
//			for (int j = 0; j < M; j++)
//				if (quota[j] <= 0)
//					exceed[j] = 1;
//			index = i;
//		}
//	}
//	for (int j = index; j < N; j++)
//	{
//		int k, prefered;
//		for (k = 0; k < K; k++)
//			if (!exceed[application[j].choices[k]])
//				break;
//		if (k != K)
//		{
//			prefered = application[j].choices[k];
//			quota[prefered]--;
//			school[prefered].push_back(application[j].id);
//		}
//	}
//	for (int i = 0; i < M; i++)
//	{
//		sort(school[i].begin(), school[i].end());
//		for (int j = 0; j < school[i].size(); j++)
//			if (j != school[i].size() - 1)
//				cout << school[i][j] << " ";
//			else cout << school[i][j];
//		cout << endl;
//	}
//}

/*1083*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//int N;
//vector<int>ropes;
//int cmp(int a, int b) { return a > b; }
//int main()
//{
//	double length = 0;
//	cin >> N;
//	ropes.resize(N);
//	for (int i = 0; i < N; i++)
//		cin >> ropes[i];
//	sort(ropes.begin(), ropes.end(), cmp);
//	for (int i = 0; i < N; i++)
//		if (i <= 20)
//		{
//			if (i != N - 1)
//				length += (double)ropes[i] / pow(2, i);
//			else length += (double)ropes[i] / pow(2, i - 1);
//		}
//	cout << (int)length / 2;
//}

/*1141*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class test
//{
//public:
//	string id, school;
//	int Ns;
//	double TWS, grade;
//};
//vector<test>ranklist, res;
//int N;
//int cmpid(test a, test b) { return a.school < b.school; }
//int cmp(test a, test b)
//{
//	if ((int)a.TWS > (int)b.TWS)return 1;
//	else if (a.TWS == b.TWS)
//	{
//		if (a.Ns < b.Ns)return 1;
//		else if (a.Ns == b.Ns && a.school < b.school)return 1;
//	}
//	return 0;
//}
//int main()
//{
//	cin >> N;
//	ranklist.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> ranklist[i].id >> ranklist[i].grade >> ranklist[i].school;
//		ranklist[i].TWS = 0;
//		ranklist[i].Ns = 0;
//		for (int j = 0; j < ranklist[i].school.size(); j++)
//			if (ranklist[i].school[j] >= 'A' && ranklist[i].school[j] <= 'Z')
//				ranklist[i].school[j] += 'a' - 'A';
//	}
//	sort(ranklist.begin(), ranklist.end(), cmpid);
//	for (int i = 0; i < N; i++)
//	{
//		if (res.empty() || ranklist[i].school != res.back().school)
//		{
//			test t = ranklist[i];
//			if (t.id[0] == 'A')
//				t.TWS += t.grade;
//			else if (t.id[0] == 'B')
//				t.TWS += t.grade / 1.5;
//			else if (t.id[0] == 'T')
//				t.TWS += t.grade * 1.5;
//			t.Ns++;
//			res.push_back(t);
//		}
//		else
//		{
//			test t = ranklist[i];
//			if (t.id[0] == 'A')
//				res.back().TWS += t.grade;
//			else if (t.id[0] == 'B')
//				res.back().TWS += t.grade / 1.5;
//			else if (t.id[0] == 'T')
//				res.back().TWS += t.grade * 1.5;
//			res.back().Ns++;
//		}
//	}
//	sort(res.begin(), res.end(), cmp);
//	cout << res.size() << endl;
//	int q = 1;
//	for (int i = 0; i < res.size(); i++)
//	{
//		if (i != 0 && (int)res[i].TWS != (int)res[i - 1].TWS)q = i + 1;
//		cout << q << " " << res[i].school << " " << (int)res[i].TWS << " " << res[i].Ns << endl;
//	}
//	
//}