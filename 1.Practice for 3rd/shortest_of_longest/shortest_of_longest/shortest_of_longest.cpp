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

#define m_size 35
int dx[4] = { -1, 0, +1, 0 };
int dy[4] = { 0, -1, 0, +1 };
int size, n, cost[m_size][m_size], total_cost[6][m_size][m_size], mx_arr[m_size][m_size];
int queue_rear, queue_front, queue_size, queue_capacity = 1000;
char arr[m_size][m_size];
Point coordinate[6], queue[1000];

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
		return Point(-1, -1);
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
	//freopen("input.txt", "r", stdin);
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
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					total_cost[i][j][k] = 0;
					mx_arr[j][k] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cin >> coordinate[i].x >> coordinate[i].y;
		}

		int idx_cnt=0;

		for (int l = 0; l < n; l++)
		{
			bfs(coordinate[l].x, coordinate[l].y);

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					total_cost[idx_cnt][i][j] = cost[i][j];
				}	
			}
			idx_cnt++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (total_cost[i][j][k] > mx_arr[j][k])
					{
						mx_arr[j][k] = total_cost[i][j][k];
						
					}
				}
			}
		}

		int mn = 1000,ans_i=0,ans_j=0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (mx_arr[i][j] < mn)
				{
					mn = mx_arr[i][j];
					ans_i = i;
					ans_j = j;
				}
			}
		}
		cout<<"Case "<<t<<": "<<ans_i<<" "<<ans_j<<" " << mn << endl;
	}
	return 0;
}


///////////   input & output   //////////////
/*Shortest of the longest::

3
4 2
1 0 1 1
0 1 0 1
0 1 1 1
1 1 1 1
0 0
3 3

10 2
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 0
9 9

30 4
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0
0 29
29 0
29 29

output::
case 1: 0  0  1000
case 2: 0  9  9
case 3: 14 14 30
*/