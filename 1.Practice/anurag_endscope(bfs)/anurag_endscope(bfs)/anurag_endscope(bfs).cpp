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

int dx[4] = { -1, 0, +1, 0 };  //u,l,d,r
int dy[4] = { 0, -1, 0, +1 };
int height, width, vertical_l, horizental_l, length, cnt, array[100][100], visit[100][100];
Point queue[100];
int queue_front, queue_rear, queue_size, queue_capacity = 100;

void queue_reset()
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
	queue_reset();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			visit[i][j] = 0;
		}
	}
}

bool cango(int a, int b, int c, int d)
{
	int type = array[a][b];
	int d1 = c - a;
	int d2 = d - b;
	if (type == 1)
	{
		if (d1 == -1 && d2 == 0) //up
			return true;
		if (d1 == 0 && d2 == -1) //left
			return true;
		if (d1 == 1 && d2 == 0) //down
			return true;
		if (d1 == 0 && d2 == 1) //right
			return true;
	}
	if (type == 2)
	{
		if (d1 == -1 && d2 == 0) //up
			return true;
		if (d1 == 1 && d2 == 0)  //down
			return true;
	}
	if (type == 3)
	{
		if (d1 == 0 && d2 == -1)  //left
			return true;
		if (d1 == 0 && d2 == 1)  //right
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
		if (d1 == 0 && d2 == -1) //left 
			return true;
		if (d1 == 1 && d2 == 0) //down
			return true;
	}
	if (type == 7)
	{
		if (d1 == -1 && d2 == 0) //up
			return true;
		if (d1 == 0 && d2 == -1) //left
			return true;
	}
	return false;
}

void bfs(int i, int j, int len)
{
	bfs_reset();
	if (!visit[i][j])
		cnt++;
	enqueue(Point(i, j));
	visit[i][j] = true;
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
			if (len <= 0)
				continue;
			if (cango(u, v, new_i, new_j) == false)
				continue;
			if (cango(new_i, new_j, u, v) == false)
				continue;
			if (!visit[new_i][new_j])
			{
				cnt++;
				enqueue(Point(new_i, new_j));
				visit[new_i][new_j] = true;
			}
		}
		len--;
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> height >> width >> vertical_l >> horizental_l >> length;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> array[i][j];
			}
		}
		cnt = 0;
		bfs(vertical_l, horizental_l, length);
		cout << cnt << endl;
	}
	return 0;
}
