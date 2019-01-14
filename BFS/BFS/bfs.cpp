#include<iostream>
using namespace std;

#define max_node 20

int node_cnt, edge_cnt, adj_mat[max_node][max_node], queue_rear, queue_front, queue_size, queue[max_node], queue_capacity = max_node, parent[max_node];
bool visit[max_node];
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
	queue_rear=(queue_rear+1)%queue_capacity;
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
	for (int i = 1; i <= node_cnt; i++)
	{
		visit[i] = 0;
		parent[i] = -1;
	}
}

bool bfs(int start,int des)
{
	bfs_reset();
	enqueue(start);
	visit[start] = true;
	while (!isempty())
	{
		int u = dequeue();
		for (int v = 1; v <= node_cnt; v++)
		{
			if (adj_mat[u][v] && !visit[v])
			{
				enqueue(v);
				parent[v] = u;
				visit[v] = true;
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
	cout << des << " ";
}

int main()
{
	cin >> node_cnt >> edge_cnt;
	for (int i = 1; i <= node_cnt; i++)
	{
		for (int j = 1; j <= node_cnt; j++)
		{
			adj_mat[i][j] = 0;
		}
	}
	for (int i = 1; i <= edge_cnt; i++)
	{
		int n1,n2,cost = 1;
		cin >> n1 >> n2;
		adj_mat[n1][n2] = cost;
		adj_mat[n2][n1] = cost;
	}
	int start, des;
	cin >> start>>des;
	bool d = bfs(start, des);
	if (d == true)
	{
		print_path(des);

	}
	else
		cout << "No Cycle" << endl;
	return 0;
}