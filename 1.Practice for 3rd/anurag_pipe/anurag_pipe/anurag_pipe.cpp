#include<iostream>
using namespace std;

struct Point{
	int x, y;
	Point(){

	}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

#define mx 1005

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int height, width, vertical_l, horizontal_l, length, visit[mx][mx], len_arr[mx][mx], arr[mx][mx];
int queue_front, queue_rear, queue_size, queue_capacity = 1000005;
Point queue[1000005];

void queue_clear()
{
	queue_front = 0;
	queue_rear = 0;
	queue_size = 0;
}

bool isempty()
{
	if (queue_size == 0)
		return true;
	else
		return false;
}

void enqueue(Point p)
{
	if (queue_size == queue_capacity)
		return;
	queue[queue_rear] = p;
	queue_rear = (queue_rear + 1) % queue_capacity;
	queue_size++;
}

Point dequeue()
{
	if (isempty())
		return Point(-1, -1);
	Point temp = queue[queue_front];
	queue_front = (queue_front + 1) % queue_capacity;
	queue_size--;
	return temp;
}

void bfs_reset()
{
	queue_clear();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			len_arr[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

bool cango(int a, int b, int c, int d)
{
	int type = arr[a][b];
	int d1 = c - a;
	int d2 = d - b;
	if (type == 1)
	{
		if (d1 == -1 && d2 == 0)
			return true;
		if (d1 == 0 && d2 == -1)
			return true;
		if (d1 == 1 && d2 == 0)
			return true;
		if (d1 == 0 && d2 == 1)
			return true;
	}
	if (type == 2)
	{
		if (d1 == -1 && d2 == 0)
			return true;
		if (d1 == 1 && d2 == 0)
			return true;
	}
	if (type == 3)
	{
		if (d1 == 0 && d2 == -1)
			return true;
		if (d1 == 0 && d2 == 1)
			return true;
	}
	if (type == 4)
	{
		if (d1 == -1 && d2 == 0)
			return true;
		if (d1 == 0 && d2 == 1)
			return true;
	}
	if (type == 5)
	{
		if (d1 == 1 && d2 == 0)
			return true;
		if (d1 == 0 && d2 == 1)
			return true;
	}
	if (type == 6)
	{
		if (d1 == 0 && d2 == -1)
			return true;
		if (d1 == 1 && d2 == 0)
			return true;
	}
	if (type == 7)
	{
		if (d1 == -1 && d2 == 0)
			return true;
		if (d1 == 0 && d2 == -1)
			return true;
	}
	return false;
}

int bfs(int i, int j, int len)
{
	if (arr[i][j] == 0)
		return 0;
	bfs_reset();
	enqueue(Point(i, j));
	visit[i][j] = 1;
	len_arr[i][j] = len;
	int cnt = 1;
	while (!isempty())
	{
		Point p = dequeue();
		int u = p.x;
		int v = p.y;
		for (int k = 0; k < 4; k++)
		{
			int new_i = u + dx[k];
			int new_j = v + dy[k];
			if (new_i < 0 || new_i >= height || new_j < 0 || new_j >= width)
				continue;
			if (len_arr[u][v] <= 0)
				continue;
			if (cango(u, v, new_i, new_j) == false)
				continue;
			if (cango(new_i, new_j, u, v) == false)
				continue;
			if (len_arr[u][v] - 1 > len_arr[new_i][new_j])
			{
				if (visit[new_i][new_j] == 0)
					cnt++;
				enqueue(Point(new_i,new_j));
				visit[new_i][new_j] = 1;
				len_arr[new_i][new_j] = len_arr[u][v] - 1;
			}
		}
	}
	return cnt;
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> height >> width >> vertical_l >> horizontal_l >> length;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> arr[i][j];
			}
		}
		int ans =bfs(vertical_l, horizontal_l, length);
		cout << "# " << t << ": " << ans << endl;
	}
}