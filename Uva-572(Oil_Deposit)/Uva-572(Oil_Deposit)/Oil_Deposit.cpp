#include<iostream>
#include<stdio.h>
using namespace std;

int m,n;
char array[101][101];
int dx[8] = { 0, 0, -1, +1, -1, -1, +1, +1 };
int dy[8] = { -1, +1, 0, 0, -1, +1, -1, +1 };

void dfs(int i, int j)
{
	array[i][j] = 'c';
	for (int k = 0; k < 8; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
			continue;
		if (array[new_i][new_j] == 'c' || array[new_i][new_j] == '*')
			continue;
		dfs(new_i, new_j);
	}
}

int main()
{
	int x = 0;
	while (true)
	{
		cin >> m >> n;
		if (m == 0)
			break;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> array[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (array[i][j] == '@')
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}