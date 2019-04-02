#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

char mapping(char ss)
{
	if (ss >= 'A' && ss <= 'C') return '2';
	if (ss >= 'D' && ss <= 'F') return '3';
	if (ss >= 'G' && ss <= 'I') return '4';
	if (ss >= 'J' && ss <= 'L') return '5';
	if (ss >= 'M' && ss <= 'O') return '6';
	if (ss >= 'P' && ss <= 'S') return '7';
	if (ss >= 'T' && ss <= 'V') return '8';
	if (ss >= 'W' && ss <= 'Y') return '9';
}

void qsort(int l, int r, vector<string> pn, vector<int> num)
{
	int i, j, t;
	string mid, st;
	i = l; j = r; mid = pn[(i + j) / 2];
	do
	{
		while (pn[i] < mid) i++;
		while (pn[j] > mid) j--;
		if (i <= j)
		{
			st = pn[i]; pn[i] = pn[j]; pn[j] = st;
			t = num[i]; num[i] = num[j]; num[j] = t;
			i++; j--;
		}
	} while (i < j);
	if (l < j) qsort(l, j, pn, num);
	if (i < r) qsort(i, r, pn, num);
}

int main()
{
	map<string, int> phonenumber;
	int n, i, j, m, flag = 0;
	vector<int> num;
	vector<string> pn;
	map<string, int> ::iterator iter;
	string s, st;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> s;
		st = "";
		for (j = 0; j < s.length(); j++)
		{
			if (s[j] >= 'A' && s[j] <= 'Z')
			{
				st += mapping(s[j]);
			}
			if (s[j] >= '0' && s[j] <= '9')
				st += s[j];
		}
		iter = phonenumber.find(st);
		if (iter == phonenumber.end())
			phonenumber[st] = 1;
		else
		{
			phonenumber[st] += 1;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "No duplicates." << endl;
	}
	else
	{
		for (i = 0,  iter = phonenumber.begin(); iter != phonenumber.end(); iter++, i++)
		{
			if (iter->second > 1)
			{
				cout << iter->first[0] << iter->first[1] << iter->first[2] << '-' << iter->first[3] << iter->first[4] << iter->first[5] << iter->first[6] << ' ' << iter->second << endl;
			}
			//num.push_back(iter->second);
			//pn.push_back(iter->first);
		}
	}
	//m = i;
	//qsort(0, m - 1, pn, num);
	//for (i = 0; i < m; i++)
	//if (num[i] > 1)
	//{
	//	cout << pn[i][0] << pn[i][1] << pn[i][2] << '-' << pn[i][3] << pn[i][4] << pn[i][5] << pn[i][6] << ' ' << num[i] << endl;
		
	//}
 	system("pause");
	return 0;
}