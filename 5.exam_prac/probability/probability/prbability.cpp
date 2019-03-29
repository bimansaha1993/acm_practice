#include<iostream>
using namespace std;

int n, e, tme, time_left[20];
double arr[20][20], cost[20];

void dfs(int u)
{
	for (int v = 1; v <= n; v++)
	{
		if (arr[u][v] && (time_left[u] - 10) > 0)
		{
			time_left[v] = time_left[u] - 10;
			cost[v] = cost[v] + (cost[u] * arr[u][v]);
			dfs(v);
		}
	}
}

int main()
{
	cin >> n >> e >> tme;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = 0;
		}
		cost[i] = 0;
	}
	for (int i = 1; i <= e; i++)
	{
		int n1, n2;
		double weight;
		cin >> n1 >> n2 >> weight;
		arr[n1][n2] = weight;
	}
	time_left[1] = tme;
	cost[1] = 1;
	dfs(1);
	cost[1] = 0;
	int max_index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cost[i] > cost[max_index])
		{
			max_index = i;
		}
	}
	cout << max_index << " " << cost[max_index] << endl;
	return 0;
}
