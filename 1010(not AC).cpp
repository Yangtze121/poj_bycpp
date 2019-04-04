#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
#include<map>
#include<vector>

using namespace std;

int maxkind = 0, maxnum = 0, maxvalue = 0;
int ans[5];

void printans(int customer, int kind)
{
	int i;
	cout << customer << '(' << kind << "):";
	for (i = 1; i <= 4; i++)
	{
		if (ans[i] != 0)
			cout << ans[i] << ' ';
	}
	cout << endl;
}

void workforcustomer(int customer, vector <int> stamps)
{
	ans[1] = 0; ans[2] = 0; ans[3] = 0; ans[4] = 0;
	int i, j, k, l, kind, num, value;
	for (i = 0; i < stamps.size(); i++)
	for (j = 0; j < stamps.size(); j++)
	for (k = 0; k < stamps.size(); k++)
	for (l = 0; l < stamps.size(); l++)
	{
		if (stamps[i] + stamps[j] + stamps[k] + stamps[l] == customer)
		{
			kind = 4; num = 4;
			value = customer;
			if (i == 0) 
			{
				num--; kind--;
			}
			if (j == 0) 
			{
				num--; kind--;
			}
			if (k == 0) 
			{
				num--; kind--;
			}
			if (l == 0) 
			{
				num--; kind--;
			}
			if ((i == j || i == k || i == l) && ( i != 0))
			{
				kind--; value -= stamps[i];
			}
			if ((j == k || j == l) && (j != 0))
			{
				kind--; value -= stamps[j];
			}
			if ((k == l) && (k != 0))
			{
				kind--; value -= stamps[k];
			}
			cout << stamps[i] << stamps[j] << stamps[k] << stamps[l] << kind << endl;
			if (kind > maxkind)
			{
				maxkind = kind; maxnum = num; maxvalue = value; ans[1] = i; ans[2] = j; ans[3] = k; ans[4] = l;
 			}
			else
			if (kind == maxkind)
			{
				if (num > maxnum)
				{
					maxnum = num; maxvalue = value; ans[1] = i; ans[2] = j; ans[3] = k; ans[4] = l;
				}
				else
				if (num == maxnum)
				{
					if (value > maxvalue)
					{
						maxvalue = value; ans[1] = i; ans[2] = j; ans[3] = k; ans[4] = l;
					}
					if (value == maxvalue)
					{
						cout << 'tie' << endl; exit;
					}
				}
			}
		}
	}
	printans(customer, maxkind);
}

int main()
{
	vector <int> stamps;
	int i, j, k, l, num, stamp, customer;
	while (1)
	{
		cin >> stamp;
		stamps.clear();
		stamps.push_back(0);
		while (stamp != 0)
		{
			stamps.push_back(stamp);
			cin >> stamp;
		}
		cin >> customer;
		while (customer != 0)
		{
			workforcustomer(customer, stamps);
			cin >> customer;
		}
		cout << stamps.size();
		
		
	}
 	system("pause");
	return 0;
}