#include<iostream>
using namespace std;

#define max 25 
int node, edge, adj_mat[max][max], color[max];


void dfs(int u,int c1)
{
	if (color[u] != 0)
		return;
	color[u] = c1;
	for (int v = 1; v <= node; v++)
	{
		if (adj_mat[u][v] && color[v] == 0)
		{
			int c2;
			if (c1 == 1)
				c2 = 2;
			else
				c2 = 1;
			dfs(v,c2);
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
			adj_mat[n2][n1] = cost;
		}
		for (int i = 1; i <= node; i++)
		{
			color[i] = 0;
		}
		for (int i = 1; i <= node; i++)
		{
			if (color[i] == 0)
			{
				dfs(i, 1);
			}
		}
		int is_possible = 1;
		for (int i = 1; i <= node && is_possible == 1; i++)
		{
			for (int j = 1; j <= node && is_possible == 1; j++)
			{
				if (adj_mat[i][j])
				{
					if (color[i] == color[j])
					{
						is_possible = 0;
					}
				}
			}
		}
		if (is_possible == 1)
		{
			cout << "Case " << t << ": " << endl;
			cout << "Black Color :";
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 1)
					cout << i << " ";
			}
			cout << endl;
			cout << "red Color :";
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 2)
					cout << i << " ";
			}
			cout << endl;
		}
		else
			cout << "Case " << t << ": " << "Color is not possible" << endl;
	}
	return 0;
}