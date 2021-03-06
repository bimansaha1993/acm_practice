#include<iostream>
#include<stdio.h>
using namespace std;

struct Point{
	int x, y;
};

#define mx 15
int n, w[5], mat[mx][mx], cost[mx], node_cnt;
Point wh_start[5], wh_end[5], nodes[mx];

void dfs(int u)
{
	for (int v = 0; v < node_cnt; v++)
	{
		if (cost[v]>cost[u] + mat[u][v])
		{
			cost[v] = cost[u] + mat[u][v];
			dfs(v);
		}
	}
}

int fabs(int a) {
	if (a < 0)
		return -a;
	return a;
}

void calculate_cost(int i, int j)
{
	Point a = nodes[i];
	Point b = nodes[j];
	int cost = fabs(a.x - b.x) + fabs(a.y - b.y);
	mat[i][j] = cost;
	mat[j][i] = cost;
}

void add_node(Point p)
{
	nodes[node_cnt] = p;
	node_cnt++;
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
			cin >> wh_start[i].x >> wh_start[i].y >> wh_end[i].x >> wh_end[i].y >> w[i];
		}
		// insert every important node
		node_cnt = 0;
		add_node(start_point);
		add_node(end_point);
		for (int i = 0; i < n; i++)
		{
			add_node(wh_start[i]);
			add_node(wh_end[i]);
		}

		//calculate mahaton cost
		for (int i = 0; i < node_cnt; i++)
		{
			for (int j = 0; j < node_cnt; j++)
			{
				calculate_cost(i, j);
			}
		}

		//set cost for warmholes
		for (int i = 0; i < n; i++)
		{
			int start_node_i = 2 * i + 2;
			int end_node_i = 2 * i + 3;
			mat[start_node_i][end_node_i] = w[i];
			mat[end_node_i][start_node_i] = w[i];
		}

		for (int i = 0; i < node_cnt; i++)
		{
			cost[i] = 3000;
		}
		cost[0] = 0;
		dfs(0);
		cout << "#" << t << " " << cost[1] << endl;
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