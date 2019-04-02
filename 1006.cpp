#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main()
{
	int days, p, e, i, d, j, case_num = 0;
	while(cin >> p >> e >> i >> d)
	{
		case_num++;
		if (p == -1)
			break;
		for (j = d + 1; j <= 21252 + d; j++)
		{
			if (((j - p) % 23 == 0) && ((j - e) % 28 == 0) && ((j - i) % 33 == 0))
				break;
		}
		cout << "Case " << case_num << ": the next triple peak occurs in " << (j - d) << " days." << endl;
	}
	system("pause");
	return 0;
}