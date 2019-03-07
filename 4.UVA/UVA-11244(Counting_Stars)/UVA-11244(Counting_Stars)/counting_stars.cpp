#include<iostream>
using namespace std;

int r, c,cnt;
int dx[8] = { 0, 0, +1, -1, -1, -1, +1, +1 };
int dy[8] = { +1, -1, 0, 0, -1, +1, -1, +1 };
char sky[102][102];

void find_star(int i, int j)
{
	sky[i][j] = 'c';
	cnt++;
	for (int k = 0; k < 8; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c)
			continue;
		if (sky[new_i][new_j] == 'c' || sky[new_i][new_j] == '.')
			continue;
		find_star(new_i, new_j);
	}
}

int main()
{
	while (true)
	{
		cin >> r >> c;
		if (r == 0 && c == 0)
			break;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> sky[i][j];
			}
		}
		int star = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (sky[i][j] == '*')
				{
					cnt = 0;
					find_star(i, j);
					if (cnt == 1)
						star++;
				}
			}
		}
		cout << star << endl;
	}
	return 0;
}