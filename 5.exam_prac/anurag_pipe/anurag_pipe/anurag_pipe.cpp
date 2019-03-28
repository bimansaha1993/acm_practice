#include<iostream>
using namespace std;

int dx[4] = { 0, 0, +1, -1 }; //r,l,d,u
int dy[4] = { +1, -1, 0, 0 };
int height, width, verticale_l, horizontal_l, length, cnt, type;
int visit[100][100], arr[100][100];

bool cango(int a, int b, int c, int d)
{
	type = arr[a][b];
	int d1 = c - a;
	int d2 = d - b;
	if (type == 1)
	{
		if (d1 == 0 && d2 == 1) //right
			return true;
		if (d1 == 0 && d2 == -1) //left
			return true;
		if (d1 == 1 && d2 == 0) //down
			return true;
		if (d1 == -1 && d2 == 0) //up
			return true;
	}
	if (type == 2)
	{
		if (d1 == 1 && d2 == 0) //down
			return true;
		if (d1 == -1 && d2 == 0) //up
			return true;
	}
	if (type == 3)
	{
		if (d1 == 0 && d2 == 1) //right
			return true;
		if (d1 == 0 && d2 == -1) //left
			return true;
	}
	if (type == 4)
	{
		if (d1 == -1 && d2 == 0) //up
			return true;
		if (d1 == 0 && d2 == 1) //right
			return true;
	}
	if (type == 5)
	{
		if (d1 == 1 && d2 == 0) //down
			return true;
		if (d1 == 0 && d2 == 1) //right
			return true;
	}
	if (type == 6)
	{
		if (d1 == 1 && d2 == 0) //down
			return true;
		if (d1 == 0 && d2 == -1) //left
			return true;
	}
	if (type == 7)
	{
		if (d1 == -1 && d2 == 0)  //up
			return true;
		if (d1 == 0 && d2 == -1) //left
			return true;
	}
	return false;
}

void pipe(int i, int j, int length)
{
	if (!visit[i][j])
		cnt++;
	visit[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= height || new_j < 0 || new_j >= width)
			continue;
		if (length <= 0)
			continue;
		if (cango(i, j, new_i, new_j) == false)
			continue;
		if (cango(new_i, new_j, i, j) == false)
			continue;
		pipe(new_i, new_j, length - 1);
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> height >> width >> verticale_l >> horizontal_l >> length;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> arr[i][j];
				visit[i][j] = 0;
			}
		}
		cnt = 0;
		pipe(verticale_l, horizontal_l, length - 1);
		cout << cnt << endl;
	}
	return 0;
}