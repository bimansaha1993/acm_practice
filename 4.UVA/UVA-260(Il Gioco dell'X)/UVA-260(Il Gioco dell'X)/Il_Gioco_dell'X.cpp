#include<iostream>
#include<stdio.h>
using namespace std;

int n;
char array[201][201];
int dx[6] = { -1,-1, 0, 0,+1,+1 };
int dy[6] = { -1, 0,-1,+1, 0,+1 };

void dfs(int i, int j)
{
	array[i][j] = 'c';
	for (int k = 0; k < 6; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 1 || new_i > n || new_j < 1 || new_j > n)
				continue;
		if (array[new_i][new_j] == 'c' || array[new_i][new_j] == 'b')
			continue;
		dfs(new_i, new_j);
		}
}

int main()
{
	int x = 0;
	char winner;
	while (true)
	{
		cin >> n;
		if (n <= 0)
			break;
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j <=n; j++)
			{
				cin >> array[i][j];
			}
		}
		for (int i = 1; i <=n; i++)
		{
			if (array[i][1] == 'w')
			{
				dfs(i, 1);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (array[i][n] == 'c')
			{
				winner = 'W';
				break;
			}
			else
				winner = 'B';
		}
		x++;
		cout << x << " " << winner<<endl;
	}
	return 0;
}