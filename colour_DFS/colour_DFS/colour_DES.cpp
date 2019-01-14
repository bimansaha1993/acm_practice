#include<iostream>
using namespace std;

#define max_node 20

int node_cnt, edge_cnt, adj_mat[max_node][max_node], colour[max_node];

void dfs(int u,int clr)
{
	if (colour[u] != 0)
		return;
	colour[u] = clr;
	for (int v = 1; v <= node_cnt; v++)
	{
		if (adj_mat[u][v])
		{
			int c1;
			if (clr == 1)
				c1 = 2;
			else
				c1 = 1;
			dfs(v, c1);
		}
	}
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int k = 1; k <= test_case; k++)
	{

		cin >> node_cnt >> edge_cnt;
		for (int i = 1; i <= node_cnt; i++)
		{
			for (int j = 1; j <= node_cnt; j++)
			{
				adj_mat[i][j] = 0;
			}
		}
		for (int i = 1; i <= edge_cnt; i++)
		{
			int n1, n2, cost = 1;
			cin >> n1 >> n2;
			adj_mat[n1][n2] = cost;
			adj_mat[n2][n1] = cost;
		}
		for (int i = 1; i <= node_cnt; i++)
		{
			colour[i] = 0;
		}
		for (int i = 1; i <= node_cnt; i++)
		{
			if (colour[i] == 0)
			{
				dfs(i,1);
			}
		}
		int is_possible = 1;
		for (int i = 1; i <= node_cnt && is_possible == 1; i++)
		{
			for (int j = 1; j <= node_cnt && is_possible == 1; j++)
			{
				if (adj_mat[i][j])
				{
					if (colour[i] == colour[j])
					{
						is_possible = 0;

					}
				}
			}
		}
		if (is_possible == 1)
		{
			cout << "Case " << k << " Black Colour :";
			for (int i = 1; i <= node_cnt; i++)
			{
				if (colour[i] == 1)
					cout << i << " ";
			}
			cout << endl;
			cout << "Case " << k << " Red Colour :";
			for (int i = 1; i <= node_cnt; i++)
			{
				if (colour[i] == 2)
					cout << i << " ";
			}
			cout << endl;
		}
		else
			cout << "Case " << k << ": " << "Colour is not possible" << endl;
	}
	return 0;
}