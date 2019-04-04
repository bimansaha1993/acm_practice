#include<iostream>
using namespace std;

#define mx 30
int node, edge, arr[mx][mx], queue[mx], queue_rear, queue_front, queue_size, queue_capacity = mx, visit[mx], parent[mx], p_cnt, path[mx];

void clear()
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
	clear();
	for (int i = 1; i <= node; i++)
	{
		visit[i] = 0;
		parent[i] = -1;
	}
}

int bfs(int start, int des)
{
	bfs_reset();
	enqueue(start);
	visit[start] = 1;
	while (!isempty())
	{
		int u = dequeue();
		for (int v = 1; v <= node; v++)
		{
			if (arr[u][v] && visit[v] == 0)
			{
				enqueue(v);
				visit[v] = 1;
				parent[v] = u;
			}
		}
	}
	return visit[des];
}

void print_path(int des)
{
	if (des == -1)
		return;
	print_path(parent[des]);
	path[p_cnt] = des;
	p_cnt++;
}

void path_sort(int p[],int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (p[i]>p[j])
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> node >> edge;
		for (int i = 1; i <= node; i++)
		{
			for (int j = 1; j <= node; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i <= edge; i++)
		{
			int n1, n2;
			cin >> n1 >> n2;
			arr[n1][n2] = 1;
		}
		int cycle_found = 0;
		for (int i = 1; i <= node && cycle_found == 0; i++)
		{
			for (int j = 1; j <= node && cycle_found == 0; j++)
			{
				if (arr[i][j]==1)
				{
					int start = j;
					int des = i;
					int d = bfs(start, des);
					if (d == 1)
					{
						cycle_found = 1;
						p_cnt = 0;
						print_path(des);
					}
				}
			}
		}
		if (cycle_found == 1)
		{
			path_sort(path, p_cnt);
			for (int i = 0; i < p_cnt; i++)
			{
				cout << path[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "no cycle found" << endl;
	}
	return 0;
}