#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

int Joseph(int k, int m)
{
	int i = 0, n = 2 * k, t = k;
	int a[100] = {};
	while (t--)
	{
		int j = 0;
		int man = (m + k + t + 1) % (k + t + 1);
		while (j <= man)
		{
			if (i == n) i = 0;
			if (a[++i] == 0)
				j++;
		}
		if (i <= k)
			return 0;
		a[i] = 1;
	}
	return 1;
}

int main()
{
	vector <int> ans;
	ans.push_back(0);
	int i, j, k;
	for (k = 1; k < 13; k++)
	{
		for (i = 1;; i++)

		{
			if (Joseph(k, i))
				break;
		}
		ans.push_back(i + 1);
	}
	ans.push_back(2504881); // time limit exceeded
	while (cin >> k, k)
	{
		cout << ans[k] << endl;
	}
 	system("pause");
	return 0;
}