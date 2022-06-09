//PART1：字符串处理

//1001
/*#include<iostream>
using namespace std;
int main()
{
	int a, b, c, n = 0;
	int sum[8] = { 0 };
	cin >> a >> b;
	c = abs(a + b);
	while (c > 0)
	{
		sum[n] = c % 10;
		c /= 10;
		n++;
	}
	if (!(a + b))
	{
		cout << 0;
		return 0;
	}
	else
	{
		if (a + b < 0)
			cout << "-";
		for (int i = n - 1; i >= 0; i--)
		{
			if ((i + 1) % 3 == 0 && i != n - 1)
				cout << ",";
			cout << sum[i];
		}
	}
}*/

//1002
/*
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b;
	cin >> a;
	pair<int, double>* A = new pair<int, double>[a];
	for (int i = 0; i < a; i++)
		cin >> A[i].first >> A[i].second;
	cin >> b;
	pair<int, double>* B = new pair<int, double>[b];
	for (int i = 0; i < b; i++)
		cin >> B[i].first >> B[i].second;
	int i = 0, j = 0, k = 0, K = 0;
	pair<int, double>* sum = new pair<int, double>[max(A[0].first, B[0].first) + 1];
	while (i < a || j < b)
	{
		if (A[i].first < B[j].first)
		{
			sum[k].first = B[j].first;
			sum[k].second = B[j].second;
			if (sum[k].second != 0)K++;
			k++;
			j++;
		}
		else if (A[i].first > B[j].first)
		{
			sum[k].first = A[i].first;
			sum[k].second = A[i].second;
			if (sum[k].second != 0)K++;
			k++;
			i++;
		}
		else if (A[i].first == B[j].first)
		{
			sum[k].first = A[i].first;
			sum[k].second = A[i].second + B[j].second;
			if (sum[k].second != 0)K++;
			k++;
			i++;
			j++;
		}
		if (i == a)
		{
			while (j < b)
			{
				sum[k].first = B[j].first;
				sum[k].second = B[j].second;
				if (sum[k].second != 0)K++;
				j++;
				k++;
			}
		}
		if (j == b)
		{
			while (i < a)
			{
				sum[k].first = A[i].first;
				sum[k].second = A[i].second;
				if (sum[k].second != 0)K++;
				i++;
				k++;
			}
		}
	}
	cout << K;
	for (i = 0; i < k; i++)
	{
		if (sum[i].second != 0)
			cout << " " << sum[i].first << " " << setiosflags(ios::fixed) << setprecision(1) << sum[i].second;
	}
}*/

/*1005*/
//#include<iostream>
//#include<map>
//using namespace std;
//map<int, string>letter;
//void init()
//{
//	letter[0] = "zero";
//	letter[1] = "one";
//	letter[2] = "two";
//	letter[3] = "three";
//	letter[4] = "four";
//	letter[5] = "five";
//	letter[6] = "six";
//	letter[7] = "seven";
//	letter[8] = "eight";
//	letter[9] = "nine";
//}
//int main()
//{
//	init();
//	string str;
//	int digit[5];
//	cin >> str;
//	int sum = 0, size = 0;
//	for (int i = 0; i < str.size(); i++)
//		sum += str[i] - '0';
//	while (1)
//	{
//		digit[size] = sum % 10;
//		sum = sum / 10;
//		size++;
//		if (sum == 0)break;
//	}
//	for (int i = size - 1; i >= 0; i--)
//		if (i != 0)cout << letter[digit[i]] << " ";
//		else cout << letter[digit[i]];
//}

/*1023*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	string str;
//	int num1[21], num2[21] = { 0 }, size, flag = 1, upper = 0;
//	int obtain1[10] = { 0 }, obtain2[10] = { 0 };
//	cin >> str;
//	size = str.size();
//	for (int i = 0; i < size; i++)
//	{
//		num1[i] = str[i] - '0';
//		obtain1[num1[i]]++;
//	}
//	for (int i = size - 1; i >= 0; i--)
//	{
//		num2[i] += (num1[i] * 2) % 10;
//		obtain2[num2[i]]++;
//		if (num1[i] * 2 >= 10)
//		{
//			if (i != 0)num2[i - 1]++;
//			else
//			{
//				upper = 1;
//				obtain2[1]++;
//			}
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if (obtain1[i] != obtain2[i])
//		{
//			flag = 0;
//			break;
//		}
//	}
//	if (flag)cout << "Yes" << endl;
//	else cout << "No" << endl;
//	if (upper)cout << upper;
//	for (int i = 0; i < size; i++)
//		cout << num2[i];
//}

/*1024*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//int num[1021], start;
//int Palindromic()
//{
//	int origin[1021];
//	memcpy(origin, num, sizeof(origin));
//	int flag = 0;
//	for (int i = 1020; i >= start; i--)
//	{
//		num[i] += origin[1020 - i + start];
//		if (flag)num[i] += 1;
//		if (num[i] >= 10)flag = 1;
//		else flag = 0;
//		num[i] %= 10;
//	}
//	if (flag)
//	{
//		start--;
//		num[start] = 1;
//	}
//	flag = 1;
//	for (int i = start; i < 1021; i++)
//	{
//		if (num[i] != num[1020 - i + start])
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
//	string N;
//	int K, step = 0;
//	cin >> N >> K;
//	start = 1021 - N.size();
//	for (int i = 0; i < N.size(); i++)
//		num[start + i] = N[i] - '0';
//	int flag = 1;
//	for (int i = start; i < 1021; i++)
//	{
//		if (num[i] != num[1020 - i + start])
//		{
//			flag = 0;
//			break;
//		}
//	}
//	while (step < K && !flag)
//	{
//		step++;
//		if (Palindromic())break;
//	}
//	for (int i = start; i < 1021; i++)
//		cout << num[i];
//	cout << endl << step;
//}

/*1035*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int N;
//class account
//{
//public:
//	string id, password;
//};
//account users[1001];
//vector<account>modified;
//int change(char& a)
//{
//	switch (a)
//	{
//	case '1':
//		a = '@';
//		return 1;
//	case '0':
//		a = '%';
//		return 1;
//	case 'l':
//		a = 'L';		
//		return 1;
//	case 'O':
//		a = 'o';
//		return 1;
//	default:
//		return 0;
//	}
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> users[i].id >> users[i].password;
//	for (int i = 0; i < N; i++)
//	{
//		string& password = users[i].password;
//		int flag = 0;
//		for (int j = 0; j < password.size(); j++)
//			if (change(password[j]))flag = 1;
//		if (flag)modified.push_back(users[i]);
//	}
//	if (modified.empty())
//	{
//		if (N == 1)
//			cout << "There is 1 account and no account is modified";
//		else printf("There are %d accounts and no account is modified", N);
//	}
//	else
//	{
//		cout << modified.size() << endl;
//		for (int i = 0; i < modified.size(); i++)
//			cout << modified[i].id << " " << modified[i].password << endl;
//	}
//}

/*1060: 科学计数法，重要*/
//#include<iostream>
//#include<string.h>
//using namespace std;
//int N;
//class number
//{
//public:
//	char sig_num[101];
//	int exp, dot;
//	number(string x)
//	{
//		memset(sig_num, '0', sizeof(sig_num));
//		exp = 0, dot = x.size();
//		for(int i=0;i<x.size();i++)
//			if (x[i] == '.')
//			{
//				dot = i;
//				break;
//			}
//		int start = dot;
//		for (int i = 0; i < x.size(); i++)
//		{
//			if (x[i] != '0' && x[i] != '.')
//			{
//				start = i;
//				break;
//			}
//		}
//		if (dot >= start)exp = dot - start;
//		else exp = dot - start + 1;
//		int after = 0;
//		for (int i = start; i + after < x.size(); i++)
//		{
//			if (x[i] == '.')after = 1;
//			sig_num[i - start] = x[i + after];
//		}
//	}
//	bool operator ==(number n)
//	{
//		if (n.exp != exp)return 0;
//		for (int i = 0; i < N; i++)
//			if (n.sig_num[i] != sig_num[i])
//				return 0;
//		return 1;
//	}
//};
//int main()
//{
//	string a, b;
//	cin >> N >> a >> b;
//	number A(a), B(b);
//	if (A == B)
//	{
//		cout << "YES 0.";
//		for (int i = 0; i < N; i++)
//			cout << A.sig_num[i];
//		cout << "*10^" << A.exp;
//	}
//	else
//	{
//		cout << "NO 0.";
//		for (int i = 0; i < N; i++)
//			cout << A.sig_num[i];
//		cout << "*10^" << A.exp << " 0.";
//		for (int i = 0; i < N; i++)
//			cout << B.sig_num[i];
//		cout << "*10^" << B.exp;
//	}
//}

/*1061*/
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	string s1, s2, s3, s4;
//	cin >> s1 >> s2 >> s3 >> s4;
//	vector<char>common;
//	char day, hour;
//	int minute, h;
//	for (int i = 0; i < s1.size() && i < s2.size(); i++)
//	{
//		if (s1[i] == s2[i])common.push_back(s1[i]);
//	}
//	int p;
//	for (p = 0; p < common.size(); p++)
//	{
//		if (common[p] >= 'A' && common[p] <= 'G')
//		{
//			day = common[p];
//			break;
//		}
//	}
//	for (int i = p + 1; i < common.size(); i++)
//	{
//		if ((common[i] >= '0' && common[i] <= '9') || (common[i] >= 'A' && common[i] <= 'N'))
//		{
//			hour = common[i];
//			break;
//		}
//	}
//	for (int i = 0; i < s3.size() && i < s4.size(); i++)
//	{
//		if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')))
//		{
//			minute = i;
//			break;
//		}
//	}
//	switch (day)
//	{
//	case 'A':
//		cout << "MON ";
//		break;
//	case 'B':
//		cout << "TUE ";
//		break;
//	case 'C':
//		cout << "WED ";
//		break;
//	case 'D':
//		cout << "THU ";
//		break;
//	case 'E':
//		cout << "FRI ";
//		break;
//	case 'F':
//		cout << "SAT ";
//		break;
//	case 'G':
//		cout << "SUN ";
//		break;
//	}
//	if (hour >= '0' && hour <= '9')h = hour - '0';
//	else h = 10 + hour - 'A';
//	printf("%02d:%02d", h, minute);
//}

/*1073：科学计数法*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	string A;
//	cin >> A;
//	int e;
//	for (e = 0; A[e] != 'E'; e++);
//	string t = A.substr(1, e - 1);
//	int exp = atoi(A.substr(e + 1).c_str());
//	if (A[0] == '-')cout << '-';
//	if (exp < 0)
//	{
//		cout << "0.";
//		for (int i = 0; i < abs(exp) - 1; i++)cout << 0;
//		for (int i = 0; i < t.size(); i++)
//			if (t[i] != '.')cout << t[i];
//	}
//	else
//	{
//		cout << t[0];
//		if (exp >= t.size() - 2)
//		{
//			for (int i = 0; i < t.size() - 2; i++)
//				cout << t[i + 2];
//			for (int i = 0; i < exp + 2 - t.size(); i++)cout << 0;
//		}
//		else
//		{
//			for (int i = 0; i < exp; i++)
//				cout << t[i + 2];
//			cout << ".";
//			for (int i = exp; i + 2 < t.size(); i++)
//				cout << t[i + 2];
//		}
//	}
//}

/*1077: cin getline*/
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str[100];
//	int N, length = 0;
//	cin >> N;
//	cin.get();
//	for (int i = 0; i < N; i++)
//		getline(cin, str[i]);
//	for (int i = 1; i < N; i++)
//	{
//		if (i == 1)
//		{
//			for (int j = 0; j < min(str[i].size(), str[i - 1].size()); j++)
//			{
//				if (str[i][str[i].size() - 1 - j] == str[i - 1][str[i - 1].size() - 1 - j])
//					length++;
//				else break;
//			}
//		}
//		else
//		{
//			for (int j = 0; j < length; j++)
//			{
//				if (str[i][str[i].size() - 1 - j] != str[i - 1][str[i - 1].size() - 1 - j])
//				{
//					length = j;
//					break;
//				}
//			}
//		}
//		if (length == 0)
//		{
//			cout << "nai";
//			return 0;
//		}
//	}
//	for (int i = str[0].size() - length; i < str[0].size(); i++)
//		cout << str[0][i];
//}

/*1082: 读数字*/
//#include<iostream>
//#include<vector>
//using namespace std;
//string getUnit(int i)
//{
//	switch (i)
//	{
//	case 2:
//		return "Shi";
//	case 3:
//		return "Bai";
//	case 4:
//		return "Qian";
//	case 5:
//		return "Wan";
//	case 6:
//		return "Shi";
//	case 7:
//		return "Bai";
//	case 8:
//		return "Qian";
//	case 9:
//		return "Yi";
//	}
//}
//string getNum(char i)
//{
//	switch (i)
//	{
//	case '1':
//		return "yi";
//	case '2':
//		return "er";
//	case '3':
//		return "san";
//	case '4':
//		return "si";
//	case '5':
//		return "wu";
//	case '6':
//		return "liu";
//	case '7':
//		return "qi";
//	case '8':
//		return "ba";
//	case '9':
//		return "jiu";
//	}
//}
//int main()
//{
//	string str;
//	vector<string>res;
//	cin >> str;
//	int i = 0;
//	if (str[0] == '-')
//	{
//		res.push_back("Fu");
//		i++;
//	}
//	while (i < str.size() && str[i] == '0')i++;
//	if (i == str.size())
//	{
//		cout << "ling";
//		return 0;
//	}
//	for (; i < str.size(); i++)
//	{
//		if (str[i] != '0')
//		{
//			res.push_back(getNum(str[i]));
//			if (str.size() - i != 1)res.push_back(getUnit(str.size() - i));
//		}
//		else
//		{
//			int j = i;
//			while (j < str.size() && str[j] == '0')j++;
//			if (j != str.size())
//			{
//				if (str.size() - i + 1 >= 5)res.push_back("Wan");
//				res.push_back("ling");
//			}
//			i = j - 1;
//		}
//	}
//	for (int i = 0; i < res.size(); i++)
//		if (i != res.size() - 1)
//			cout << res[i] << " ";
//		else cout << res[i];
//}

/*1108*/
//#include<iostream>
//#include<string>
//using namespace std;
//int N, no = 1001;
//double isLegal(string s)
//{
//	double num;
//	int dot = s.size(), start = 0;
//	if (s[0] == '-' || s[0] == '+')start++;
//	for (int i = start; i < s.size(); i++)
//	{
//		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))return no;
//		if (s[i] == '.')
//		{
//			if (i == start)return no;
//			if (dot == s.size())dot = i;
//			else return no;
//		}
//	}
//	if (dot != s.size() && s.size() - start - dot - 1 > 2)return no;
//	num = stof(s.c_str());
//	if (num >= -1000 && num <= 1000)return num;
//	else return no;
//}
//int main()
//{
//	cin >> N;
//	string numbers[100];
//	for (int i = 0; i < N; i++)
//		cin >> numbers[i];
//	double sum = 0;
//	int total = 0;
//	for (int i = 0; i < N; i++)
//	{
//		double temp = isLegal(numbers[i]);
//		if (temp != no)
//		{
//			sum += temp;
//			total++;
//		}
//		else
//			printf("ERROR: %s is not a legal number\n", numbers[i].c_str());
//	}
//	if (total == 0)
//		cout << "The average of 0 numbers is Undefined";
//	else if (total == 1)
//		printf("The average of 1 number is %.2f", sum);
//	else printf("The average of %d numbers is %.2f", total, (double)sum / total);
//}

