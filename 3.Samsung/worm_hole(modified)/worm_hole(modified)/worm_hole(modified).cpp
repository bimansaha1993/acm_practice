#include<iostream>
#include<stdio.h>
using namespace std;

struct Point{
	int x, y;
	Point(){

	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

#define mx 15
int n, w[5], mat[mx][mx], cost[mx], queue[mx], queue_front, queue_rear, queue_size, queue_capacity = mx;
Point wh_start[5], wh_end[5];

int fabs(int a) {
	if (a < 0)
		return -a;
	return a;
}

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
	queue_reset();
	for (int i = 0; i < 2 * n + 2; i++)
	{
		cost[i] = 3000;
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
		for (int v = 0; v < 2 * n + 2; v++)
		{
			if (cost[v]>cost[u] + mat[u][v])
			{
				enqueue(v);
				cost[v] = cost[u] + mat[u][v];
			}
		}
	}
}

void calculate_cost(int i, int j, Point a, Point b)
{
	int cost = fabs(a.x - b.x) + fabs(a.y - b.y);
	mat[i][j] = cost;
	mat[j][i] = cost;
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
			cin >> wh_start[i].x >> wh_start[i].y >> wh_end[i].x >> wh_end[i].y>>w[i];
		}
		//1st node of reduced graph
		int first_node = 0;
		//last node of reduced graph
		int last_node = 2 * n + 1;
		for (int i = 0; i < n; i++)
		{
			// start node of ith warmhole
			int start_node_i = 2 * i + 1;
			//end node of ith warmhole
			int end_node_i = 2 * i + 2;

			calculate_cost(first_node, start_node_i, start_point, wh_start[i]);
			calculate_cost(first_node, end_node_i, start_point, wh_end[i]);
			calculate_cost(last_node, start_node_i, end_point, wh_start[i]);
			calculate_cost(last_node, end_node_i, end_point, wh_end[i]);

			for (int j = 0; j < n; j++)
			{
				int start_node_j = 2 * j + 1;
				int end_node_j = 2 * j + 2;

				calculate_cost(start_node_i, start_node_j, wh_start[i], wh_start[j]);
				calculate_cost(start_node_i, end_node_j, wh_start[i], wh_end[j]);
				calculate_cost(end_node_i, start_node_j, wh_end[i], wh_start[j]);
				calculate_cost(end_node_i, end_node_j, wh_end[i], wh_end[j]);
			}

			mat[start_node_i][end_node_i] = w[i];
			mat[end_node_i][start_node_i] = w[i];
		}
		calculate_cost(first_node, last_node, start_point, end_point);
		mat[first_node][first_node] = 0;
		mat[last_node][last_node] = 0;
		bfs(first_node);
		cout << "#" << t << " " << cost[last_node] << endl;
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
9 9 0 0
1 1 4 4 2
2 1 3 2 4
4 5 7 8 5
5 6 8 7 6
8 8 9 9 5
*/