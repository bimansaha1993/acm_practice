#include<iostream>
using namespace std;
int main()
{
	long long int t, n, a[1001], i, j, d;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n;
		d = 0;
		for (j = 1; j <= n; j++)
		{
			cin >> a[j];
			if (a[j]>0)
				d = d + a[j];
		}
		cout <<"Case "<<i<<": " << d << endl;
	}
	
	return 0;
}