#include<iostream>
using namespace std;
int main()
{
	long long int t, x1, y1, x2, y2, c, x[10001], y[10001], i, j;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> c;
		for (j = 1; j <= c; j++)
		{
			cin >> x[j] >> y[j];
		}
		cout << "Case " << i << ":" << endl;
		for (j = 1; j <= c; j++)
		{
			if ((x[j] > x1) && (x[j] < x2) && (y[j] > y1) && (y[j] < y2))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}