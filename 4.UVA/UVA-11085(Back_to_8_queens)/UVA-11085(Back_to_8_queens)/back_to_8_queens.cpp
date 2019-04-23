#include<iostream>
#include<iomanip>
using namespace std;

int used[9][9], current[9], ans[100][9], n, a[9];

int checkleftdigonal(int i, int j)
{
	while (i >= 0 && j >= 0)
	{
		if (used[i][j])
		{
			return 0;
		}
		i--;
		j--;
	}
	return 1;
}

int checkrightdigonal(int i, int j)
{
	while (i >= 0 && j < 8)
	{
		if (used[i][j])
		{
			return 0;
		}
		i--;
		j++;
	}
	return 1;
}

int checkup(int i, int j)
{
	while (i >= 0)
	{
		if (used[i][j])
		{
			return 0;
		}
		i--;
	}
	return 1;
}

void min_move(int i)
{
	if (i == 8)
	{
		for (int j = 0; j < 8; j++)
		{
			ans[n][j] = current[j];
		}
		n++;
		return;
	}
	for (int j = 0; j < 8; j++)
	{
		if (checkleftdigonal(i, j) && checkrightdigonal(i, j) && checkup(i, j))
		{
			used[i][j] = 1;
			current[i] = j;
			min_move(i + 1);
			used[i][j] = 0;
		}
	}
}

int main()
{
	int test=1;
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				used[i][j] = 0;
			}
		}
		n = 0;
		min_move(0);
		int mn = 8;
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < 8; j++)
			{
				if (ans[i][j] != a[j] - 1)
				{
					cnt++;
				}
			}
			if (cnt < mn)
				mn = cnt;
		}
		cout << "Case " << test << ": " << mn <<endl;
		test++;
	}
	return 0;
}