#include<iostream>
using namespace std;

#define mx 30
int node, edge, arr[mx][mx], color[mx];

void dfs(int u,int clr)
{
	if (color[u] != 0)
		return;
	color[u] = clr;
	for (int v = 1; v <= node; v++)
	{
		if (arr[u][v])
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
			arr[n2][n1] = 1;
		}
		for (int i = 1; i <= node; i++)
		{
			color[i] = 0;
		}
		for (int i = 1; i <= node; i++)
		{
			if (color[i] == 0)
			{
				dfs(i,1);
			}
		}
		int is_possible = 1;
		for (int i = 1; i <= node && is_possible == 1; i++)
		{
			for (int j = 1; j <= node && is_possible == 1; j++)
			{
				if (arr[i][j])
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
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 1)
					cout << i << " ";
			}
			cout << endl;
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 2)
					cout << i << " ";
			}
			cout << endl;
		}
		else
			cout << "no color" << endl;
	}
	return 0;
}