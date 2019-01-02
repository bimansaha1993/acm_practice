#include<iostream>
using namespace std;
int main()
{
	int t, n, k, a[1001], i, j, cnt;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cnt = 0;
		cin >> n >> k;
		for (j = 0; j < n; j++)
		{
			cin >> a[j];
			if (a[j] <= 0)
			{
				cnt++;
			}
		}
		if (cnt >= k)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}