#include<iostream>
using namespace std;

int n = 6, arr[10];
int mat[6][6];

void draw_set(int i)
{
	if (i == 9)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[j];
		}
		cout << endl;
		return;
	}

	int u = arr[i - 1];
	for (int v = 1; v < n; v++)
	{
		if (mat[u][v]==0)
		{
			mat[u][v] = 1;
			mat[v][u] = 1;
			arr[i] = v;
			draw_set(i + 1);
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
	mat[1][4] = 1;
	mat[4][1] = 1;
	mat[2][4] = 1;
	mat[4][2] = 1;
	arr[0] = 1;
	draw_set(1);
	return 0;
}