#include<iostream>
using namespace std;

#define mx 20
int n, e, tme,tme_left[mx];
double arr[mx][mx], cost[mx];

void dfs(int u)
{
	for (int v = 1; v < n; v++)
	{
		if (arr[u][v] == 1 && tme_left[u] - 10 >= 0)
		{
			tme_left[v] = tme_left[u] - 10;
			cost[v] = cost[v] + (cost[u] * arr[u][v]);
			dfs(v);
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n >> e;
		cin >> tme;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i < e; i++)
		{
			int n1, n2;
			double weight;
			cin >> n1 >> n2 >> weight;
			arr[n1][n2] = weight;
		}
		for (int i = 1; i < n; i++)
		{
			cost[i] = 0;
		}

		tme_left[1] = tme;
		cost[1] = 1;
		dfs(1);
		cost[1] = 0;
		int max_idx = 0;
		for (int i = 1; i < n; i++)
		{
			if (cost[i]>cost[max_idx])
			{
				max_idx = i;
			}
		}
		cout << max_idx << " " << cost[max_idx] << endl;
	}
	return 0;
}