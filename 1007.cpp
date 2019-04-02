#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>

using namespace std;

void work(int *a)
{
	a[0] = 2;
}

void qsort(int l, int r, int *c, string *s)
{
	int i, j, mid, t;
	string st;
	i = l; j = r; mid = c[(i + j) / 2];
	do
	{
		while (c[i] < mid) i++;
		while (c[j] > mid) j--;
		if (i <= j)
		{
			t = c[i]; c[i] = c[j]; c[j] = t; 
			st = s[i]; s[i] = s[j]; s[j] = st;
			i++; j--;
		}
	} while (i < j);
	if (i < r) qsort(i, r, c, s);
	if (l < j) qsort(l, j, c, s);
}

void bubblesort(int *c, string *s, int m)
{
	int i, j, t;
	string st;
	for (i = 1; i <= m; i++)
	for (j = 1; j <= m - i; j++)
	if (c[j] > c[j + 1])
	{
		t = c[j]; c[j] = c[j + 1]; c[j + 1] = t;
		st = s[j]; s[j] = s[j + 1]; s[j + 1] = st;
	}
}

int main()
{
	int c[105] = {0};
	string s[105];
	int i, j, n, m, k, count;
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		count = 0;
		cin >> s[i];
		for (j = 0; j < n; j++)
		for (k = j + 1; k < n; k++)
		{
			if (s[i][k] < s[i][j])
				count++;
		}
		c[i] = count;
	}
	//qsort(1, m, c, s);   not steady !
	bubblesort(c, s, m);
	for (i = 1; i <= m; i++)
		cout << s[i] << endl;
 	system("pause");
	return 0;
}