#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double length, now_len, i;
	length = 1;
	while (length != 0)
	{
		cin >> length;
		if (length == 0)
			break;
		now_len = 0;
		i = 2;
		while (now_len < length)
		{
			now_len += 1 / i;
			i++;
		}
		cout << i - 2 << " card(s)" << endl;
	}
	system("pause");
	return 0;
}