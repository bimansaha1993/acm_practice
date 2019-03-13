#include<iostream>
using namespace std;

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
int r, c,start_x,start_y,num_beep,x[11],y[11],min=999,cnt;


void beep_collection(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c)
			continue;

	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> r >> c;
		cin >> start_x >> start_y;
		cin >> num_beep;
		for (int i = 0; i < num_beep; i++)
		{
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == start_x && j == start_y)
				{

					beep_collection(i, j);
				}
			}
		}
		cout << "The shortest path has length" << min << endl;
	}
	return 0;
}