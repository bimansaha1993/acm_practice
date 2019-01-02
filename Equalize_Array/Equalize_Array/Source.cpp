#include<iostream>
using namespace std;
int main()
{
	int n, a[101], b[101], i, j, cnt, l=0, rmv, max=1;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		l++;
	}
	for (i = 1; i <= n; i++)
	{
		cnt = 1;
		for (j = i+1; j <= n; j++)
		{
			if (a[i] == a[j])
				cnt++;

		}
		if (cnt > max)
			max = cnt;
	}
	rmv = l - max;
	cout << rmv << endl;
	return 0;
}