#include<iostream>
#include<stdio.h>
using namespace std;

int m, n, cnt,x,y;
int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
char arr[21][21];

void region(int i, int j)
{
	arr[i][j] = 'c';
	cnt++;
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i == x && new_j == y)
		{
			cnt = 0;
			break;
		}
		if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
			continue;
		if (arr[new_i][new_j] == 'c' || arr[new_i][new_j] == 'w')
			continue;
		region(new_i, new_j);
	}

}

int main()
{
	while (scanf_s("%d %d",&m,&n)!=EOF)
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
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == x && j == y)
					continue;
				if (arr[i][j] == 'l')
				{
					cnt = 0;
					region(i,j);
					if (cnt > large)
						large = cnt;
				}
			}
		}
		cout << large << endl;
		cout << endl;
	}
	return 0;
}