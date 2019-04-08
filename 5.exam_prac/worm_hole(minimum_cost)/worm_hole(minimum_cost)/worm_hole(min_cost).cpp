#include<iostream>
using namespace std;

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
int n, a[5], b[5], c[5], d[5], w[5],end_x,end_y;
int cost[1005][1005];

void dfs(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= end_x+1 || new_j < 0 || new_j >= end_x+1)
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + 1)
			continue;
		cost[new_i][new_j] = cost[i][j] + 1;
		dfs(new_i, new_j);
	}
	for (int k = 0; k < n; k++)
	{
		int new_i, new_j;
		if (i == a[k] && j == b[k])
		{
			new_i = c[k];
			new_j = d[k];
		}
		else if (i == c[k] && j == d[k])
		{
			new_i = a[k];
			new_j = b[k];
		}
		else
			continue;
		if (cost[new_i][new_j] <= cost[i][j] + w[k])
			continue;
		cost[new_i][new_j] = cost[i][j] + w[k];
		dfs(new_i, new_j);
	}
}

int main()
{
	int test,start_x,start_y;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n;
		cin >> start_x >> start_y >> end_x >> end_y;
		if (start_x > end_x)
		{
			int temp1 = start_x;
			start_x = end_x;
			end_x = temp1;

			int temp2 = start_y;
			start_y = end_y;
			end_y = temp2;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i] >> d[i] >> w[i];
		}
		for (int i = 0; i < end_x + 1; i++)
		{
			for (int j = 0; j < end_x + 1; j++)
			{
				cost[i][j] = 3000;
			}
		}
		cost[start_x][start_y] = 0;
		dfs(start_x, start_y);
		cout<<"#"<<t<<" " << cost[end_x][end_y] << endl;
	}
	return 0;
}

/*
3
0
0 0 60 60
1
0 0 2 0
1 0 1 2 5
5
9 9 0 0  // 0 0 9 9
1 1 4 4 2
2 1 3 2 4
4 5 7 8 5
5 6 8 7 6
8 8 9 9 5

output
#120
#2
#13
*/