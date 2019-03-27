#include<iostream>
using namespace std;

#define max 20
int node, edge, adj_mat[max][max], visit[max], parent[max], path_cnt, path[max];

void dfs(int u)
{
	visit[u] = 1;
	for (int v = 1; v <= node; v++)
	{
		if (adj_mat[u][v] && !visit[v])
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
	path[path_cnt] = des;
	path_cnt++;
}

void sort(int p[], int length)
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
				adj_mat[i][j] = 0;
			}
		}
		for (int i = 1; i <= edge; i++)
		{
			int n1, n2, cost = 1;
			cin >> n1 >> n2;
			adj_mat[n1][n2] = cost;
		}
		int cycle_found = 0;
		for (int i = 1; i <= node && cycle_found == 0; i++)
		{
			for (int j = 1; j <= node && cycle_found == 0; j++)
			{
				if (adj_mat[i][j])
				{
					int start = j;
					int des = i;
					for (int k = 1; k <= node; k++)
					{
						visit[k] = 0; 
						parent[k] = -1;
					}
					dfs(start);
					if (visit[des])
					{
						cycle_found = 1;
						path_cnt = 0;
						print_path(des);
					}

				}
			}
		}
		if (cycle_found == 1)
		{
			sort(path, path_cnt);
			cout << "Case " << t << " :";
			for (int i = 0; i < path_cnt; i++)
			{
				cout << path[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Case " << t << " : " << "No Cycle Found" << endl;
	}
	return 0;
}