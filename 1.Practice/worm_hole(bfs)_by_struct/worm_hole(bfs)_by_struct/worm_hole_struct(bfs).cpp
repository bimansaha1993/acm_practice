#include<iostream>
using namespace std;

struct Point{
	int x, y;
	Point(int x, int y)
	{
		this->x=x;
		this->y=y;
	}
};

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
int n, a[5], b[5], c[5], d[5], w[5], end_x, end_y;
int cost[1005][1005];
Point queue[1005]; 
int queue_front, queue_rear, queue_size, queue_capacity = 1005;

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
		return 0;
	Point temp = queue[queue_front];
	queue_front = (queue_front + 1) % queue_capacity;
	queue_size--;
	return temp;
}

void bfs_reset()
{
	queue_reset();
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			cost[i][j] = 3000;
		}
	}
}

void bfs(int start_x, int start_y)
{
	bfs_reset();
	enqueue(Point(start_x,start_y));
	cost[start_x][start_y] = 0;
	while (!isempty())
	{
		Point p = dequeue();
		int u = p.x;
		int v = p.y;
		for (int k = 0; k < 4; k++)
		{
			int new_i = u + dx[k];
			int new_j = v + dy[k];
			if (new_i < 0 || new_i >= end_x + 1 || new_j < 0 || new_j >= end_x + 1)
				continue;
			if (cost[new_i][new_j] <= cost[u][v] + 1)
				continue;
			cost[new_i][new_j] = cost[u][v] + 1;
			enqueue(Point(new_i,new_j));
		}

		for (int k = 0; k < n; k++)
		{
			int new_i, new_j;
			if (u == a[k] && v == b[k])
			{
				new_i = c[k];
				new_j = d[k];
			}
			else if (u == c[k] && v == d[k])
			{
				new_i = a[k];
				new_j = b[k];
			}
			else
				continue;
			if (cost[new_i][new_j] <= cost[u][v] + w[k])
				continue;
			cost[new_i][new_j] = cost[u][v] + w[k];
			enqueue(Point(new_i,new_j));
		}
	}
}

int main()
{
	int test, start_x, start_y;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n;
		cin >> start_x >> start_y >> end_x >> end_y;
		if (start_x > end_x)
		{
			int temp1 = start_x;
			start_x = end_x;
			end_x = temp1;

			int temp2 = start_y;
			start_y = end_y;
			end_y = temp2;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i] >> c[i] >> d[i] >> w[i];
		}
		bfs(start_x, start_y);
		cout << "#" << t << " " << cost[end_x][end_y] << endl;
	}
	return 0;
}

/*
3
0
0 0 60 60
1
0 0 2 0
1 0 1 2 5
5
0 0 9 9
1 1 4 4 2
2 1 3 2 4
4 5 7 8 5
5 6 8 7 6
8 8 9 9 5
*/