#include<iostream>
using namespace std;

int n = 6, arr[10], mat[6][6];

void draw_set(int i)
{
	if (i == 8)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	int u = arr[i - 1];
	for (int v = 2; v < n; v++)
	{
		if (!mat[u][v])
		{
			mat[u][v] = 1;
			mat[v][u] = 1;
			arr[i] = v;
			draw_set(u + 1);
			mat[u][v] = 0;
			mat[v][u] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}
		mat[i][i] = 1;
	}
	arr[0] = 1;
	draw_set(1);
	return 0;
}