#include<iostream>
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

#define m_size 35
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
int size, n, cost[m_size][m_size], total_cost[m_size][m_size], queue_rear, queue_front, queue_size, queue_capacity = 1000;
char arr[m_size][m_size];
Point coordinate[5], queue[1000];

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

void enqueue(Point a)
{
	if (queue_size == queue_capacity)
		return;
	queue[queue_rear] = a;
	queue_rear = (queue_rear + 1) % queue_capacity;
	queue_size++;
}

Point dequeue()
{
	if (isempty())
		return Point(-1,-1);
	Point temp = queue[queue_front];
	queue_front = (queue_front + 1) % queue_capacity;
	queue_size--;
	return temp;
}

void bfs_reset()
{
	queue_clear();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cost[i][j] = 1000;
		}
	}
}

void bfs(int i, int j)
{
	bfs_reset();
	enqueue(Point(i, j));
	cost[i][j] = 0;
	while (!isempty())
	{
		Point p = dequeue();
		int u = p.x;
		int v = p.y;
		for (int k = 0; k < 4; k++)
		{
			int new_i = u + dx[k];
			int new_j = v + dy[k];
			if (new_i < 0 || new_i >= size || new_j < 0 || new_j >= size)
				continue;
			if (arr[new_i][new_j] == '0')
				continue;
			if (arr[new_i][new_j] == '1')
			{
				if (cost[new_i][new_j]>cost[u][v] + 1)
				{
					enqueue(Point(new_i, new_j));
					cost[new_i][new_j] = cost[u][v] + 1;
				}	
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
		cin >> size >> n;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> arr[i][j];
				total_cost[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cin >> coordinate[i].x >> coordinate[i].y;
		}
		int mx = 0, mn = 1000;
		for (int l = 0; l < n; l++)
		{
			bfs(coordinate[l].x, coordinate[l].y);

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					total_cost[i][j] = total_cost[i][j] + cost[i][j];
				}
			}
		}
		int ans=1000, ans_i, ans_j;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (total_cost[i][j]<ans)
				{
					ans = total_cost[i][j];
					ans_i = i;
					ans_j = j;
				}
				//cout << cost[i][j] << " ";
				cout << total_cost[i][j] << " ";
			}
			cout << endl;
		}
		cout << ans << " " << ans_i << " " << ans_j;
	}
	return 0;
}