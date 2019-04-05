#include<iostream>
using namespace std;

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
int n, a[5], b[5], c[5], d[5], w[5],end_x,end_y;
int cost[1005][1005];

void dfs(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= end_x+1 || new_j < 0 || new_j >= end_x+1)
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + 1)
			continue;
		cost[new_i][new_j] = cost[i][j] + 1;
		dfs(new_i, new_j);
	}
	for (int k = 0; k < 5; k++)
	{
		int new_i, new_j;
		if (i == a[k] && j == b[k])
		{
			new_i = c[k];
			new_j = d[k];
		}
		else if (i == c[k] && j == d[k])
		{
			new_i = a[k];
			new_j = b[k];
		}
		else
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + w[k])
			continue;
		cost[new_i][new_j] = cost[i][j] + w[k];
		dfs(new_i, new_j);
	}
}

int main()
{
	int test,start_x,start_y;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n;
		cin >> start_x >> start_y >> end_x >> end_y;
		if (end_x > start_x)
		{
			int temp1 = start_x;
			start_x = end_x;
			end_x = temp1;

			int temp2 = start_y;
			start_y = end_y;
			end_y = temp2;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i] >> d[i] >> w[i];
		}
		for (int i = 0; i < end_x + 1; i++)
		{
			for (int j = 0; j < end_x + 1; j++)
			{
				cost[i][j] = 3000;
			}
		}
		cost[0][0] = 0;
		dfs(0, 0);
		cout << cost[n - 1][n - 1] << endl;
	}
	return 0;
}