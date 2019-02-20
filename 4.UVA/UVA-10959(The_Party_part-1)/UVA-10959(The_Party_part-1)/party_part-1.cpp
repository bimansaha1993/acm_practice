#include<iostream>
#include<stdio.h>
using namespace std;

#define max_node 1005

int person, dancing_couple, adj_mat[max_node][max_node], queue_rear, queue_front, queue_size, queue[max_node], queue_capacity = max_node, giovani_number[max_node],inf=999;
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

void enqueue(int start)
{
	if (queue_size == queue_capacity)
		return;
	queue[queue_rear] = start;
	queue_size++;
	queue_rear = (queue_rear + 1) % queue_capacity;
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
	for (int i = 1; i <= person; i++)
	{
		giovani_number[i] = inf;
	}
}

void bfs(int source)
{
	bfs_reset();
	enqueue(source);
	giovani_number[source] = 0;
	while (!isempty())
	{
		int u = dequeue();
		for (int v = 0; v < person; v++)
		{
			if (adj_mat[u][v] && giovani_number[v]==inf)
			{
				giovani_number[v] = giovani_number[u] + 1;
				enqueue(v);
			}
		}
	}
	for (int l = 1; l < person; l++)
	{
		cout << giovani_number[l] << endl;
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		if (t != 1)
			cout << endl;
		///// blank line /////
		gets("\n");
		cin >> person >> dancing_couple;
		for (int i = 0; i < person; i++)
		{
			for (int j = 0; j < person; j++)
			{
				adj_mat[i][j] = 0;
			}
		}
		for (int i = 0; i < dancing_couple; i++)
		{
			int partner1, partner2, cost = 1;
			cin >> partner1 >> partner2;
			adj_mat[partner1][partner2] = cost;
			adj_mat[partner2][partner1] = cost;
		}
		bfs(0);
		/////// blankline input ///////
	}
	return 0;
}