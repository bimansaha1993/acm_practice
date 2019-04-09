#include<iostream>
using namespace std;

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
int n, a[5], b[5], c[5], d[5], w[5], end_x, end_y;
int cost[1005][1005];
int queue_x[1005], queue_y[1005], queue_front_x, queue_front_y, queue_rear_x, queue_rear_y, queue_size_x, queue_size_y, queue_capacity = 1005;

void reset()
{
	queue_front_x = 0;
	queue_rear_x = 0;
	queue_size_x = 0;

	queue_front_y = 0;
	queue_rear_y = 0;
	queue_size_y = 0;
}

bool isempty_x()
{
	if (queue_size_x == 0)
		return true;
	else
		return false;
}

bool isempty_y()
{
	if (queue_size_y == 0)
		return true;
	else
		return false;
}

void enqueue_x(int i)
{
	if (queue_size_x == queue_capacity)
		return;
	queue_x[queue_rear_x] = i;
	queue_rear_x = (queue_rear_x + 1) % queue_capacity;
	queue_size_x++;
}

void enqueue_y(int j)
{
	if (queue_size_y == queue_capacity)
		return;
	queue_y[queue_rear_y] = j;
	queue_rear_y = (queue_rear_y + 1) % queue_capacity;
	queue_size_y++;
}

int dequeue_x()
{
	if (isempty_x())
		return 0;
	int temp = queue_x[queue_front_x];
	queue_front_x = (queue_front_x + 1) % queue_capacity;
	queue_size_x--;
	return temp;
}

int dequeue_y()
{
	if (isempty_y())
		return 0;
	int temp = queue_y[queue_front_y];
	queue_front_y = (queue_front_y + 1) % queue_capacity;
	queue_size_y--;
	return temp;
}

void bfs_reset()
{
	reset();
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
	enqueue_x(start_x);
	enqueue_y(start_y);
	cost[start_x][start_y] = 0;
	while (!isempty_x() && !isempty_y())
	{
		int u = dequeue_x();
		int v = dequeue_y();
		for (int k = 0; k < 4; k++)
		{
			int new_i = u + dx[k];
			int new_j = v + dy[k];
			if (new_i < 0 || new_i >= end_x + 1 || new_j < 0 || new_j >= end_x + 1)
				continue;
			if (cost[new_i][new_j] <= cost[u][v] + 1)
				continue;
			cost[new_i][new_j] = cost[u][v] + 1;
			enqueue_x(new_i);
			enqueue_y(new_j);
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
			enqueue_x(new_i);
			enqueue_y(new_j);
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
		cout<<"#"<<t<<" " << cost[end_x][end_y] << endl;
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