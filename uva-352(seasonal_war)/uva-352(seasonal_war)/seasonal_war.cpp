#include<iostream>
#include<stdio.h>
using namespace std;

int n;
char array[100][100];
int dx[8] = {0,0,-1,+1,-1,-1,+1,+1};
int dy[8] = {-1,+1,0,0,-1,+1,-1,+1};

void dfs(int i, int j)
{
	array[i][j] = 'c';
	for (int k = 0; k < 8; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n)
			continue;
		if (array[new_i][new_j] == 'c' || array[new_i][new_j] == '0')
			continue;
		dfs(new_i, new_j);
	}
}

int main()
{
	int x = 0;
	while (cin >> n)
	{
		x++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> array[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (array[i][j] == '1')
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		//cout <<"Image number " << x << " contains " << cnt << " war eagles." << endl;
		printf("Image number %d contains %d war eagles.\n",x,cnt);
	}
	return 0;
}