#include <iostream>
#include<stdio.h>

using namespace std;

int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
int array[100][100], visit[100][100];
int height, width, vertical_l, horizental_l, length, cnt;

bool cango(int a, int b, int c, int d)
{
	int type = array[a][b];
	int d1 = c - a;
	int d2 = d - b;
	if (type == 1)
	{
		if (d1 == -1 && d2 == 0)
		{
			return true;
		}
		if (d1 == 0 && d2 == -1)
		{
			return true;
		}
		if (d1 == 1 && d2 == 0)
		{
			return true;
		}
		if (d1 == 0 && d2 == 1)
		{
			return true;
		}
	}
	if (type == 2)
	{
		if (d1 == -1 && d2 == 0)
		{
			return true;
		}
		if (d1 == 1 && d2 == 0)
		{
			return true;
		}
	}
	if (type == 3)
	{
		if (d1 == 0 && d2 == -1)
		{
			return true;
		}
		if (d1 == 0 && d2 == 1)
		{
			return true;
		}
	}
	if (type == 4)
	{
		if (d1 == -1 && d2 == 0)
		{
			return true;
		}
		if (d1 == 0 && d2 == 1)
		{
			return true;
		}
	}
	if (type == 5)
	{
		if (d1 == 1 && d2 == 0)
		{
			return true;
		}
		if (d1 == 0 && d2 == 1)
		{
			return true;
		}
	}
	if (type == 6)
	{
		if (d1 == 0 && d2 == -1)
		{
			return true;
		}
		if (d1 == 1 && d2 == 0)
		{
			return true;
		}
	}
	if (type == 7)
	{
		if (d1 == -1 && d2 == 0)
		{
			return true;
		}
		if (d1 == 0 && d2 == -1)
		{
			return true;
		}
	}
	return false;
}

void dfs(int i, int j, int length)
{
	if (!visit[i][j])
		cnt++;
	visit[i][j] = true;
	for (int k = 0; k<4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i<0 || new_i >= height || new_j<0 || new_j >= width)
			continue;
		if (length <= 0)
			continue;
		if (cango(i, j, new_i, new_j) == false)
			continue;
		if (cango(new_i, new_j, i, j) == false)
			continue;
		dfs(new_i, new_j, length - 1);

	}
}

int main()
{
	//freopen("Input.txt", "r", stdin);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> height >> width >> vertical_l >> horizental_l >> length;
		for (int i = 0; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				cin >> array[i][j];
				visit[i][j] = 0;
			}
		}
		cnt = 0;
		dfs(vertical_l, horizental_l, length - 1);
		cout << cnt << endl;
	}
	return 0;
}


