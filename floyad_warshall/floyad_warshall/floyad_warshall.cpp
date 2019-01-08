#include<iostream>
using namespace std;
int matrix[100][100], inf=9999;
int main()
{
	int n, e, n1, n2, cost, next[100][100], path[100];
	cin >> n >> e;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				matrix[i][j] = 0;
			else
				matrix[i][j] = inf;
			next[i][j] = j;
		}
	}
	for (int i = 0; i < e; i++)
	{
		cin >> n1 >> n2 >> cost;
		matrix[n1][n2] = cost;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ((matrix[i][k] + matrix[k][j]) < matrix[i][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
	cout << "route" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int s = i;
			int x = 0;
			bool flag = false;
			while (matrix[s][j] < inf && matrix[s][j] > 0)
			{
				flag = true;
				path[x] = next[s][j];
				if (path[x] == j)
					break;
				s = path[x];
				x++;
			}
			cout << i << " ";
			if (flag)
			{
				for (int k = 0; k <= x; k++)
				{
					cout << path[k]<<" ";
				}
				cout << endl;
			}
			else
				cout << "No route" << endl;
		}
	}
	cout << "shortest weight" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}