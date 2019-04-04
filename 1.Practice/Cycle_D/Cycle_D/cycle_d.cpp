#include<iostream>
using namespace std;

#define mx 30
int node, edge, arr[mx][mx], parent[mx], visit[mx], p_cnt, path[mx];

void dfs(int u)
{
	visit[u] = 1;
	for (int v = 1; v <= node; v++)
	{
		if (arr[u][v] && visit[v] == 0)
		{
			parent[v] = u;
			dfs(v);
		}
	}
}

void print_path(int des)
{
	if (des == -1)
		return;
	print_path(parent[des]);
	path[p_cnt] = des;
	p_cnt++;
}

void path_sort(int p[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (p[i]>p[j])
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> node >> edge;
		for (int i = 1; i <= node; i++)
		{
			for (int j = 1; j <= node; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i <= edge; i++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			arr[n1][n2] = 1;
		}
		int cycle_found = 0;
		for (int i = 1; i <= node && cycle_found == 0; i++)
		{
			for (int j = 1; j <= node && cycle_found == 0; j++)
			{
				if (arr[i][j])
				{
					int start = j;
					int des = i;
					for (int l = 1; l <= node; l++)
					{
						visit[l] = 0;
						parent[l] = -1;
					}
					dfs(start);
					if (visit[des])
					{
						cycle_found = 1;
						p_cnt = 0;
						print_path(des);
					}
				}
			}
		}
		if (cycle_found == 1)
		{
			path_sort(path, p_cnt);
			for (int i = 0; i < p_cnt; i++)
			{
				cout << path[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "no cycle" << endl;
	}
	return 0;
}