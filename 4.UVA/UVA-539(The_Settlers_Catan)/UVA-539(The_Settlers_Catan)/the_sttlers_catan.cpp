#include<iostream>
using namespace std;

int n, e, arr[30][30], visit[30][30];

int path_length(int i)
{
	int max_length = 0;
	for (int j = 0; j < n; j++)
	{
		if (arr[i][j] && visit[i][j] == 0)
		{
			visit[i][j] = 1;
			visit[j][i] = 1;
			int mx = path_length(j)+1;
			if (mx > max_length)
				max_length = mx;
			visit[i][j] = 0;
			visit[j][i] = 0;
		}
	}
	return max_length;
}

int main()
{
	while (cin >> n >> e)
	{
		if (n == 0 && e == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for (int i = 0; i < e; i++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			arr[n1][n2] = 1;
			arr[n2][n1] = 1;
		}
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			int length = path_length(i);
			if (length > mx)
				mx = length;
		}
		
		cout << mx << endl;
	}
	return 0;
}