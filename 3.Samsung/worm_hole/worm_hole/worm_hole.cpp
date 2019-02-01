#include <iostream>
#include<stdio.h>

using namespace std;

int dx[4] = { -1, +1, 0, 0 };  //+1,-1,-2,+2   horse
int dy[4] = { 0, 0, -1, +1 };  //-2,+2,+1,-1
int cost[100][100];
int n, a[5], b[5], c[5], d[5], w[5];
int parent_x[100][100], parent_y[100][100];


void dfs(int i, int j)
{
	for (int k = 0; k<4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i<0 || new_i >= n || new_j<0 || new_j >= n)
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + 1)
			continue;
		cost[new_i][new_j] = cost[i][j] + 1;
		parent_x[new_i][new_j] = i;
		parent_y[new_i][new_j] = j;
		dfs(new_i, new_j);

	}
	for (int k = 0; k<5; k++)
	{
		int new_i, new_j;
		if (a[k] == i && b[k] == j)
		{
			new_i = c[k];
			new_j = d[k];
		}
		else if (c[k] == i && d[k] == j)
		{
			new_i = a[k];
			new_j = b[k];
		}
		else
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + w[k])
			continue;
		cost[new_i][new_j] = cost[i][j] + w[k];
		parent_x[new_i][new_j] = i;
		parent_y[new_i][new_j] = j;
		dfs(new_i, new_j);
	}
}

void print_path(int i, int j)
{
	if (i == -1 || j == -1)
		return;
	print_path(parent_x[i][j], parent_y[i][j]);
	cout << i << " " << j << " " << cost[i][j] << endl;
}

int main()
{

	cin >> n;
	int inf = 1000000;
	for (int i = 0; i<5; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> w[i];
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cost[i][j] = inf;
			parent_x[0][0] = -1;
			parent_y[0][0] = -1;
		}
	}
	cost[0][0] = 0;
	dfs(0, 0);
	print_path(n - 1, n - 1);
	cout << cost[n - 1][n - 1];
}
