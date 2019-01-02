#include<iostream>
using namespace std;
int main()
{
	int n, t, i, j, a[100000], k, l, min;
	cin >> n >> t;
	for (k = 0; k < n; k++)
	{
		cin >> a[k];
	}
	for (k = 1; k <= t; k++)
	{
		cin >> i >> j;
		min = 3;
		for (l = i; l <= j; l++)
		{
			if (a[l] < min)
				min = a[l];
			
		}
		cout << min << endl;
	}
	return 0;
}