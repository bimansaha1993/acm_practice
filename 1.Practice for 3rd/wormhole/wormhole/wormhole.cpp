#include<iostream>
using namespace std;

struct Point{
	int x, y;
};

#define mx 15

int n, w[5], mat[mx][mx], cost[mx], queue_rear, queue_front, queue_size, queue_capacity=mx, queue[mx],node_cnt;
Point node[mx], wh_start[5], wh_end[5];

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

void enqueue(int a)
{
	if (queue_size == queue_capacity)
		return;
	queue[queue_rear] = a;
	queue_rear = (queue_rear + 1) % queue_capacity;
	queue_size++;
}

int dequeue()
{
	if (isempty())
		return 0;
	int temp = queue[queue_front];
	queue_front = (queue_front + 1) % queue_capacity;
	queue_size--;
	return temp;
}

void bfs_reset()
{
	queue_clear();
	for (int i = 0; i < node_cnt; i++)
	{
		cost[i] = 3001;
	}
}

void bfs(int start)
{
	bfs_reset();
	enqueue(start);
	cost[start] = 0;
	while (!isempty())
	{
		int u = dequeue();
		for (int v = 0; v < node_cnt; v++)
		{
			if (cost[v]>cost[u] + mat[u][v])
			{
				enqueue(v);
				cost[v] = cost[u] + mat[u][v];
			}
		}
	}
}

int fabs(int a)
{
	if (a < 0)
		return -a;
	return a;
}

void calculate_cost(int i, int j)
{
	Point a = node[i];
	Point b = node[j];
	int costs = fabs(a.x - b.x) + fabs(a.y - b.y);
	mat[i][j] = costs;
	mat[j][i] = costs;
}

void add_node(Point p)
{
	node[node_cnt] = p;
	node_cnt++;
}

int main()
{
	int test;
	Point start_point, end_point;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n;
		cin >> start_point.x >> start_point.y >> end_point.x >> end_point.y;
		for (int i = 0; i < n; i++)
		{
			cin >> wh_start[i].x >> wh_start[i].y >> wh_end[i].x >> wh_end[i].y >> w[i];
		}
		node_cnt = 0;
		add_node(start_point);
		add_node(end_point);
		for (int i = 0; i < n; i++)
		{
			add_node(wh_start[i]);
			add_node(wh_end[i]);
		}
		for (int i = 0; i < node_cnt; i++)
		{
			for (int j = 0; j < node_cnt; j++)
			{
				calculate_cost(i, j);
			}
		}
		for (int i = 0; i < n; i++)
		{
			int start_node = 2 * i + 2;
			int end_node = 2 * i + 3;
			mat[start_node][end_node] = w[i];
			mat[end_node][start_node] = w[i];
		}
		bfs(0);
		cout << "# " << t << ": " << cost[1] << endl;
	}
	return 0;
}