#include<iostream>
using namespace std;

#define max_node 20

int node_cnt, edge_cnt, adj_mat[max_node][max_node], queue_rear, queue_front, queue_size, queue[max_node], queue_capacity = max_node, colour[max_node];
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
}

void bfs(int start)
{
	bfs_reset();
	enqueue(start);
	colour[start] = 1;
	while (!isempty())
	{
		int u = dequeue();
		for (int v = 1; v <= node_cnt; v++)
		{
			if (adj_mat[u][v] && colour[v]==0)
			{
				enqueue(v);
				if (colour[u] == 1)
					colour[v] = 2;
				else
					colour[v] = 1;
			}
		}
	}
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int k = 1; k <= test_case; k++)
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
			int n1, n2, cost = 1;
			cin >> n1 >> n2;
			adj_mat[n1][n2] = cost;
			adj_mat[n2][n1] = cost;
		}
		for (int i = 1; i <= node_cnt; i++)
		{
			colour[i] = 0;
		}
		for (int i = 1; i <= node_cnt; i++)
		{
			if (colour[i] == 0)
			{
				bfs(i);
			}
		}
		int is_possible = 1;
		for (int i = 1; i <= node_cnt && is_possible == 1; i++)
		{
			for (int j = 1; j <= node_cnt && is_possible == 1; j++)
			{
				if (adj_mat[i][j])
				{
					if (colour[i] == colour[j])
					{
						is_possible = 0;
					}
				}
			}
		}
		if (is_possible == 1)
		{
			//cout << "BICOLORAABLE." << endl;
			cout << "Case " << k << " Black Colour :";
			for (int i = 1; i <= node_cnt; i++)
			{
			if (colour[i] == 1)
			cout << i << " ";
			}
			cout << endl;
			cout << "Case " << k << " Red Colour :";
			for (int i = 1; i <= node_cnt; i++)
			{
			if (colour[i] == 2)
			cout << i << " ";
			}
			cout << endl;
		}
		else
			//cout << "NOT BICOLORABLE" << endl;
			cout << "Case " << k << ": " << "Colour is not possible" << endl;
	}
	return 0;
}