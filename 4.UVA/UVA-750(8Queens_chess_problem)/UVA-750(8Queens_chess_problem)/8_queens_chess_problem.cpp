#include<iostream>
#include<iomanip>
using namespace std;

int used[9][9], current[9], ans[100][9], n, row, column;

int checkleftdigonal(int i, int j)
{
	while (i > 0 && j > 0)
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
	while (i > 0 && j <= 8)
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
	while (i > 0)
	{
		if (used[i][j])
		{
			return 0;
		}
		i--;
	}
	return 1;
}

void max_score(int i)
{
	if (i > 8)
	{
		for (int j = 1; j <= 8; j++)
		{
			ans[n][j] = current[j];
		}
		n++;
		return;
	}
	for (int j = 1; j <= 8; j++)
	{
		if (checkleftdigonal(i, j) && checkrightdigonal(i, j) && checkup(i, j))
		{
			used[i][j] = 1;
			current[i] = j;
			max_score(i + 1);
			used[i][j] = 0;
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		if (t > 0)
			cout << endl;
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)
			{
				used[i][j] = 0;
			}
		}
		n = 1;
		max_score(1);
		int sol = 0;
		cin >> row >> column;
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
		for (int i = 1; i <= n; i++)
		{
			if (ans[i][column] == row)
			{
				cout << " " << ++sol<<"      ";
				for (int j = 1; j <= 8; j++)
				{
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}