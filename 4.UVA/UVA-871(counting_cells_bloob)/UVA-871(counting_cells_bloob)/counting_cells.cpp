#include<iostream>
using namespace std;

int dx[8] = { 0, 0, -1, +1, -1, -1, +1, +1 };
int dy[8] = { -1, +1, 0, 0, -1, +1, -1, +1 };
char arr[30][30], cpy_arr[30][30];
int r, c,cnt;

void large_cell_count(int i,int j)
{
	arr[i][j] = 'X';
	cnt++;
	for (int e = 0; e < 8; e++)
	{
		int new_i = i + dx[e];
		int new_j = j + dy[e];
		if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c)
			continue;
		if (arr[new_i][new_j] == 'X' || arr[new_i][new_j] == '0')
			continue;
		large_cell_count(new_i, new_j);
	}
}

int main()
{
	int test,large=0;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == '1')
				{
					cnt = 0;
					large_cell_count(i, j);
					if (cnt > large)
						large = cnt;
				}
			}
		}
		cout << large << endl;
	}
	return 0;
}