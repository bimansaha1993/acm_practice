#include<iostream>
using namespace std;
int main()
{
	int n, a[101], i, cnt = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n-1; i++)
	{
		if (a[i+2] == 0)
		{
			cnt++;
			i++;
		}
		else
		{
			if (a[i + 1] == 0)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}