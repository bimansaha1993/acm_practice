#include <iostream>
#include<stdio.h>

using namespace std;

#define max_n 20

int n, e, head[max_n], p[max_n], p_count, time_left[max_n], tme;
double a[max_n][max_n], cost[max_n];
bool visit[max_n];

void dfs(int u)
{
	for (int v = 1; v <= n; v++)
	{
		if (a[u][v] && (time_left[u] - 10) >= 0)
		{
			//head[v] = u;
			time_left[v] = time_left[u] - 10;
			cost[v] = cost[v] + (cost[u] * a[u][v]);
			dfs(v);
		}
	}
}

int main()
{
	cin >> n >> e;
	cin >> tme;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= e; i++)
	{
		int n1, n2;
		double weight;
		cin >> n1 >> n2 >> weight;
		a[n1][n2] = weight;
	}

	for (int i = 1; i <= n; i++)
	{
		cost[i] = 0;
	}
	time_left[1] = tme;
	cost[1] = 1;
	dfs(1);
	cost[1] = 0;
	int max_index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cost[i]>cost[max_index])
			max_index = i;
	}
	cout << max_index << " " << cost[max_index];
	return 0;
}
