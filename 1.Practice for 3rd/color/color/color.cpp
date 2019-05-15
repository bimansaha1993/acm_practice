#include<iostream>
using namespace std;

#define mx 100
int node, edge, arr[mx][mx], color[mx];
int queue_front, queue_rear, queue_size, queue_capacity = mx, queue[mx];

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
}

void bfs(int start)
{
	bfs_reset();
	enqueue(start);
	color[start] = 1;
	while (!isempty())
	{
		int u = dequeue();
		for (int v = 1; v <= node; v++)
		{
			if (arr[u][v] == 1 && color[v] == 0)
			{
				enqueue(v);
				if (color[u] == 1)
					color[v] = 2;
				else
					color[v] = 1;
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
			arr[n2][n1] = 1;
		}
		for (int i = 1; i <= node; i++)
		{
			color[i] = 0;
		}
		for (int i = 1; i <= node; i++)
		{
			if (color[i] == 0)
			{
				bfs(i);
			}
		}
		int is_possible = 1;
		for (int i = 1; i <= node && is_possible == 1; i++)
		{
			for (int j = 1; j <= node && is_possible == 1; j++)
			{
				if (arr[i][j] == 1)
				{
					if (color[i] == color[j])
					{
						is_possible = 0;
					}
				}
			}
		}
		if (is_possible == 1)
		{
			cout << "Case " << t << ": " << endl;
			cout << "Black Colour :";
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 1)
				{
					cout << i << " ";
				}
			}
			cout << endl;
			cout << "White Colour :";
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 2)
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
		else
			cout << "Case " << t << ": " << "Color is not possible" << endl;
	}
	return 0;
}