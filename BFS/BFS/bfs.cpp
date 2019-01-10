#include<iostream>
using namespace std;

int n, e, a[1000][1000],rear,front,size,queue[100],capacity=100,visit[100],mat[100][100],u[11],x=0;

void clear()
{
	front = 0;
	rear = 0;
	size = 0;
}

bool isempty()
{
	if (size == 0)
		return true;
	else 
		return false;
}

void enqueue(int start)
{
	if (size == capacity)
		return;
	queue[rear] = start;
	size++;
	rear=(rear+1)%capacity;
}

int dequeue()
{
	if (isempty())
		return 0;
	int temp = queue[front];
	front = (front + 1) % capacity;
	size--;
	return temp;
}

bool bfs(int start,int des)
{
	clear();
	enqueue(start);
	visit[start] = true;
	while (!isempty())
	{
		 u[x] = dequeue();
		if (u[x] == des)
			return true;
		for (int v = 1; v <= n; v++)
		{
			if (a[u[x]][v] && !visit[v])
			{
				enqueue(v);
				visit[v] = true;
			}
		}
		x++;
	}
	return false;
}

int main()
{
	cin >> n >> e;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= e; i++)
	{
		int n1,n2,cost = 1;
		cin >> n1 >> n2;
		a[n1][n2] = cost;
		a[n2][n1] = cost;
	}
	int start, des;
	cin >> start >> des;
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	bool d = bfs(start, des);
	if (d == true)
	{
		for (int i = 0; i < x; i++)
			cout << u[i]<<endl;
	}
	//cout << bfs(start, des);
	return 0;
}