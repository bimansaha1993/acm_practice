#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

int m, n, cnt,x,y;
int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
char arr[21][21], location;

void region(int i, int j)
{
	arr[i][j] = '*';
	cnt++;
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = (j + dy[k]+n)%n;
		if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
			continue;
		if (arr[new_i][new_j] == '*' || arr[new_i][new_j] != location)
			continue;
		region(new_i, new_j);
	}
}

int main()
{
	while (cin>>m>>n)
	{
		for (int i = 0; i <m; i++)
		{
			for (int j = 0; j <n ; j++)
			{
				cin >> arr[i][j];
			}
		}
		int large=0;
		cin >> x >> y;
		location = arr[x][y];
		region(x, y);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == location)
				{
					cnt = 0;
					region(i,j);
					if (cnt > large)
						large = cnt;
				}
			}
		}
		cout << large << endl;
	}
	return 0;
}