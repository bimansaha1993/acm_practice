#include<iostream>
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
			if (arr[i][j] == laser[j])
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

void solve(int i, int l)
{
	if (i >= m)
	{
		if (l % 2 == 0)
		{
			calculate();
		}
		return;
	}
	laser[i] = 1;
	if (l > 0)
		solve(i + 1, l - 1);
	laser[i] = 0;
	solve(i + 1, l);
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
		cout << "# " << t << ": " << mx << endl;
	}
}