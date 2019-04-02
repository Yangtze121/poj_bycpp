#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>

using namespace std;

int main()
{
	string Haab[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
	string Tzolkin[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
	int n, i, j, k, year, month, day, total_days, ans_year, ans_month, ans_day;
	string s, st;
	cin >> n;
	cout << n << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> s;
		s = s.substr(0, s.length() - 1);
		day = atoi(s.c_str()); //string to int
		cin >> s;
		for (k = 0; k < 19; k++)
		{
			if (Haab[k] == s)
			{
				month = k; break;
			}
		}
		cin >> s;
		year = atoi(s.c_str());
		total_days = year * 365 + month * 20 + day + 1;
		ans_year = (total_days - 1) / 260;
		total_days = (total_days - 1)  % 260 + 1;
		ans_month = (total_days - 1) % 13 + 1;
		ans_day = (total_days - 1) % 20 + 1;
		cout << ans_month << ' ' << Tzolkin[ans_day - 1] << ' ' << ans_year << endl;
	}
 	system("pause");
	return 0;
}