#include<iostream>
#include<stdio.h>
using namespace std;

int n,cnt1,cnt2;
char array[101][101];
int dx[6] = { -1,-1, 0, 0,+1,+1 };
int dy[6] = { -1, 0,-1,+1, 0,+1 };

void dfs(int i, int j)
{
	if (array[i][j] = 'w')
	{
		array[i][j] = 'c';
		for (int k = 1; k <= 6; k++)
		{
			int new_wi = i + dx[k];
			int new_wj = j + dy[k];
			if (new_wi < 1 || new_wi >= n || new_wj < 1 || new_wj >= n)
				continue;
			if (array[new_wi][new_wj] == 'c' || array[new_wi][new_wj] == 'b')
				continue;
			//cnt1++;
			dfs(new_wi, new_wj);
			cnt1++;
		}
	}
	if (array[i][j] = 'b')
	{
		array[i][j] = 'c';
		for (int k = 1; k <= 6; k++)
		{
			int new_bi = i + dx[k];
			int new_bj = j + dy[k];
			if (new_bi < 1 || new_bi >= n || new_bj < 1 || new_bj >= n)
				continue;
			if (array[new_bi][new_bj] == 'c' || array[new_bi][new_bj] == 'w')
				continue;
			//cnt2++;
			dfs(new_bi, new_bj);
			cnt2++;
		}
	}
}

int main()
{
	int x = 0;
	while (true)
	{
		cin >> n;
		if (n < 2)
			break;
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j <=n; j++)
			{
				cin >> array[i][j];
			}
		}
		cnt1 = 0;
		cnt2 = 0;
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j <=n; j++)
			{
				//if (array[i][j] == 'w')
				//{
					dfs(i, j);
					//cnt1++;
				//}
				//if (array[i][j] == 'b')
				//{
					//dfs(i, j);
					//cnt2++;
				//}
			}
		}
		cout << cnt1 << " " << cnt2 << endl;
		x++;
		if (cnt1 > cnt2)
			cout << x << " " << "W"<<endl;
		else
			cout << x << " " << "B"<<endl;
	}
	return 0;
}