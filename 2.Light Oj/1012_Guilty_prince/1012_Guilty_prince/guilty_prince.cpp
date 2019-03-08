#include<iostream>
using namespace std;

int h, w, cnt;
int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
char arr[25][25];

void place_count(int i, int j)
{
	arr[i][j] = 'c';
	cnt++;
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= h || new_j < 0 || new_j >= w)
			continue;
		if (arr[new_i][new_j] == 'c' || arr[new_i][new_j] == '#')
			continue;
		place_count(new_i, new_j);
	}
}

int main()
{
	int test, pos_i, pos_j;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
				{
					pos_i = i;
					pos_j = j;
				}
			}
		}
		cout<<pos_i<<" "<<pos_j<<" " << arr[pos_i][pos_j] << endl;
		cnt = 0;
		place_count(pos_i, pos_j);
		cout << "Case " << t << ": " << cnt << endl;
	}
	return 0;
}