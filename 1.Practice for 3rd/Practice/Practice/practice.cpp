#include <iostream>
using namespace std;

#define mx 9
int used[mx][mx],n,current[mx],ans[100][mx],a[mx];

int  leftdigonal(int i,int j)
{
	while (i >= 0 && j >= 0)
	{
		if (used[i][j] == 1)
		{
			return 0;
		}
		i--;
		j--;
	}
	return 1;
}

int rightdigonal(int i,int j)
{
	while (i >= 0 && j < 8)
	{
		if (used[i][j] == 1)
		{
			return 0;
		}
		i--;
		j++;
	}
	return 1;
}

int top(int i,int j)
{
	while (i >= 0)
	{
		if (used[i][j] == 1)
		{
			return 0;
		}
		i--;
	}
	return 1;
}

void find_sol(int i)
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
		if (leftdigonal(i,j) && rightdigonal(i,j) && top(i,j))
		{
			used[i][j] = 1;
			current[i] = j;
			find_sol(i + 1);
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
		find_sol(0);
		int mn = 8;
		for (int i = 0; i < 8; i++)
		{
			int cnt = 0;
			for (int j = 1; j <= 8; j++)
			{
				if (ans[i][j] != a[j] - 1)
					cnt++;
			}
			if (cnt < mn)
				mn = cnt;
		}
		cout << mn << endl;
	}
	return 0;
}