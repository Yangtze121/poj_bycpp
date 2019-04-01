#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double sum = 0, money;
	int i;
	for (i = 1; i <= 12; i++)
	{
		cin >> money;
		sum += money;
	}
	cout << "$" << sum / 12 << endl;
	system("pause");
	return 0;
}