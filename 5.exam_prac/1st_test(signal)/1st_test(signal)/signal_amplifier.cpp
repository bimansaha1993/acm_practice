#include<iostream>
#include<stdio.h>
using namespace std;

int n, m, k, arr[105][25], laser[25], mx;

void calculate()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		bool has_zero = false;
		for (int j = 0; j < m; j++)
		{
			if ((arr[i][j] ^ laser[j]) == 0)
			{
				has_zero = true;
				break;
			}
		}
		if (!has_zero)
			cnt++;
	}
	if (cnt > mx)
		mx = cnt;
}

void solve(int i, int c)
{
	if (i >= m)
	{
		if (c == 0)
		{
			calculate();
		}
		return;
	}
	if (c == 0)
	{
		calculate();
		return;
	}
	for (int j = 0; j <= c; j++)
	{
		laser[i] ^= (j % 2);
		solve(i + 1, c - j);
		laser[i] ^= (j % 2);
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				laser[j] = 0;
			}
		}
		mx = 0;
		solve(0, k);
		cout << "#" << t << " " << mx << endl;
	}
	return 0;
}