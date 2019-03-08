#include<iostream>
using namespace std;

int n,arr[1001][1001],cnt,visit[1001],path[1001];

void dfs(int u)
{
	visit[u] = true;
	path[cnt] = u;
	cnt++;
	for (int v = 1; v <= n; v++)
	{
		if (arr[u][v] && !visit[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	int k, m, test,city[1000];
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> k >> n >> m;
		int ci = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> city[i];
			ci++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			arr[n1][n2] = 1;
		}
		for (int i = 0; i<ci; i++)
		{
			cnt = 1;
			for (int j = 1; j <= n; j++)
			{
				visit[j] = 0;
				path[j] = 0;
			}
			dfs(city[i]);
			for (int l = 1; l < cnt; l++)
			{
				cout << path[l] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}