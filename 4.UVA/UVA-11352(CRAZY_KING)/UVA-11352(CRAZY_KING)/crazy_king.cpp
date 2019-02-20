#include<iostream>
using namespace std;

int dx[8] = { 0, 0, -1, +1, -1, +1, -1, +1};
int dy[8] = { -1, +1, 0, 0, -1, -1, +1, +1};
int dhx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dhy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };
char arr[101][101];
int cnt,m,n,dist[101][101],inf=50;

int dfs(int i, int j)
{
	dist[i][j] = 0;
	if (arr[i][j] == 'B')
		return dist[i][j]=dist[i][j]+1;
	arr[i][j] = 'c';
	for (int k = 0; k < 8; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
			continue;
		if (arr[new_i][new_j] == 'c' || arr[new_i][new_j] == '.')
			continue;
		if (arr[new_i][new_j] == 'Z' && dist[new_i][new_j] == -1)
		{
			dist[new_i][new_j] = dist[i][j] + 1;
			dfs(new_i, new_j);
			//cnt++;
		}
		/*if (arr[i][j] == 'B')
		{
			return;
		}*/
	}
	return -1;
}

int main()
{
	int test,ans,x,y;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				dist[i][j] = -1;

			}
		}
		for (int i = m-1; i >= 0; i--)
		{
			for (int j = n-1; j >= 0; j--)
			{
				if (arr[i][j] == 'Z')
				{
					for (int l = 0; l < 8; l++)
					{
						int new_hi = i + dhx[l];
						int new_hj = j + dhy[l];
						if (new_hi < 0 || new_hi >= m || new_hj < 0 || new_hj >= n)
							continue;
						dist[new_hi][new_hj] = inf;

					}
				}
				if (arr[i][j] == 'A')
				{
					//cnt = 0;
					x = i;
					y = j;
					//ans=dfs(i, j);
				}
			}
		}
		ans = dfs(x, y);
		if (ans == -1)
			cout << "King Peter, you can’t go now!" << endl;
		cout<<"Minimal possible length of a trip is " << ans << endl;
	}
	return 0;
}