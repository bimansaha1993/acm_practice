#include<iostream>
using namespace std;

#define max 25 
int node, edge, adj_mat[max][max], queue_front, queue_rear, queue_size, queue_capacity=max, queue[max], color[max];

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

void enqueue(int value)
{
	if (queue_size == queue_capacity)
		return;
	queue[queue_rear] = value;
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
			if (adj_mat[u][v] && color[v] == 0)
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
				adj_mat[i][j] = 0;
			}
		}
		for (int i = 1; i <= edge; i++)
		{
			int n1, n2, cost = 1;
			cin >> n1 >> n2;
			adj_mat[n1][n2] = cost;
			adj_mat[n2][n1] = cost;
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
				if (adj_mat[i][j])
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
			cout << "Case " << t << ": "<<endl;
			cout << "Black Color :";
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 1)
					cout << i << " ";
			}
			cout << endl;
			cout << "red Color :";
			for (int i = 1; i <= node; i++)
			{
				if (color[i] == 2)
					cout << i << " ";
			}
			cout << endl;
		}
		else
			cout << "Case " << t << ": " << "Color is not possible" << endl;
	}
	return 0;
}