#include<iostream>
using namespace std;
int n, m, a[101], coins[101];
void rec(int i)
{
	if (i == m)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[j] == 1)
			{
				sum = sum + coins[j];
			}
		}
		cout << sum << endl;
	}
	a[i] = 0;
	rec(i + 1);
	a[i] = 1;
	rec(i + 1);
}

int main()
{
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> coins[i];
		}
		rec(0);
	}
	return 0;
}