#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main()
{
	double x, y, radius = 0, area = 0;
	int n, i, year;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		radius = 0;
		cin >> x >> y;
		radius = sqrt(x * x + y * y);
		area = 3.1415927 * radius * radius / 2;
		year = ceil(area / 50);
		cout << "Property " << i << ": This property will begin eroding in year " << year << '.' << endl;
	}
	cout << "END OF OUTPUT." << endl;
	system("pause");
	return 0;
}