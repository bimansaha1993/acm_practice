#include<iostream>
using namespace std;

int n, a[5], b[5], c[5], d[5], w[5],cost[20][20],parent_x[20][20],parent_y[20][20];
int dx[4] = { 0, 0, -1, +1 };
int dy[4] = { -1, +1, 0, 0 };

void find_cost(int i, int j)
{
	int new_i, new_j;
	for (int k = 0; k < 4; k++)
	{
		new_i = i + dx[k];
		new_j = j + dy[k];
		if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n)
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + 1)
			continue;
		cost[new_i][new_j] = cost[i][j] + 1;
		parent_x[new_i][new_j] = i;
		parent_y[new_i][new_j] = j;
		find_cost(new_i, new_j);
	}
	for (int k = 0; k < 5; k++)
	{
		//int new_i, new_j;
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
		find_cost(new_i, new_j);
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
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n;
		for (int i = 0; i < 5; i++)
		{
			cin >> a[i] >> b[i] >> c[i] >> d[i] >> w[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				parent_x[i][j] = -1;
				parent_y[i][j] = -1;
				cost[i][j] = 999;
			}
		}
		cost[0][0] = 0;
		find_cost(0, 0);
		print_path(n - 1, n - 1);
		cout << cost[n - 1][n - 1] << endl;
	}
}