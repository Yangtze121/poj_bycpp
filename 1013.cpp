#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

string results[3], lefts[3], rights[3];

int IsCounterfeit(char coin, int t)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (results[i][0] == 'e')
		{
			if ((lefts[i].find(coin) != -1) || (rights[i].find(coin) != -1)) return 0;
		}

		if (results[i][0] == 'u')
		{
			if (t) // consider the coin is the lighter one.
			{
				if (rights[i].find(coin) == -1)
					return 0;
			}
			else // consider the coin is the more heavey one.
			if (lefts[i].find(coin) == -1) 
				return 0;
		}

   		if (results[i][0] == 'd')
		{
			if (t) // consider the coin is the lighter one.
			{
				if (lefts[i].find(coin) == -1)
					return 0;
			}
			else // consider the coin is the more heavey one.
			if (rights[i].find(coin) == -1)
				return 0;
		}
	}
	return 1;
}

int main()
{
	int n, i, j;
	char coin;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < 3; j++)
			cin >> lefts[j] >> rights[j] >> results[j];
		for (coin = 'A'; coin <= 'L'; coin++)
		{
			if (IsCounterfeit(coin, 1))
			{
				cout << coin << " is the counterfeit coin and it is light." << endl;
				break;
			}
			if (IsCounterfeit(coin, 0))
			{
				cout << coin << " is the counterfeit coin and it is heavy." << endl;
				break;
			}
		}
	}

 	system("pause");
	return 0;
}