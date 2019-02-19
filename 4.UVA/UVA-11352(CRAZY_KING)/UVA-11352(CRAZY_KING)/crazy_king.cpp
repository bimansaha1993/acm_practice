#include<iostream>
using namespace std;

int dx[8] = { 0, 0, -1, +1, -1, +1, -1, +1};
int dy[8] = { -1, +1, 0, 0, -1, -1, +1, +1};
char arr[101][101];
int cnt,m,n;

void dfs(int i, int j)
{
	arr[i][j] = 'c';
	for (int k = 0; k < 8; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
			continue;
		if (arr[new_i][new_j] == 'c' || arr[new_i][new_j] == '.')
			continue;
		if (arr[new_i][new_j] == 'Z' || arr[new_i][new_j] == 'B')
		{
			dfs(new_i, new_j);
			cnt++;
		}
		/*if (arr[i][j] == 'B')
		{
			return;
		}*/
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = m-1; i >= 0; i--)
		{
			for (int j = n-1; j >= 0; j--)
			{
				if (arr[i][j] == 'A')
				{
					cnt = 0;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}