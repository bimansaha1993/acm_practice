#include<iostream>
#include<stdio.h>
using namespace std;

int n=9,m=9,cnt;
char array[100][100];
int dx[8] = { 0, 0, -1, +1, -1, -1, +1, +1 };
int dy[8] = { -1, +1, 0, 0, -1, +1, -1, +1 };

void dfs(int i, int j)
{
	array[i][j] = 'c';
	cnt++;
	for (int e = 0; e < 8; e++)
	{
		int new_i = i + dx[e];
		int new_j = j + dy[e];
		if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n)
			continue;
		if (array[new_i][new_j] == 'c' || array[new_i][new_j] == 'L')
			continue;
		
		dfs(new_i, new_j);
		
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test;t++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> array[i][j];
			}
		}
		for (int k = 1; k <=2; k++)
		{
			cnt = 0;
			int i, j;
			cin >> i >> j;
			if (array[i][j] == 'W')
			{
				dfs(i, j);
			}
			cout << cnt << endl;
		}
	}
	return 0;
}