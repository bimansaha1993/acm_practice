#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int r, c, num_beep, x[11], y[11], visited[11], min_cost;

void beep_collection(int i, int depth, int cost)
{
	if (depth == num_beep)
	{
		cost = cost + abs(x[i] - x[0]) + abs(y[i] - y[0]);
		if (cost < min_cost)
		{
			min_cost = cost;
		}
		return;
	}
	for (int j = 1; j <= num_beep; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			beep_collection(j, depth + 1, (cost + abs(x[i] - x[j]) + abs(y[i] - y[j])));
			visited[j] = 0;
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		min_cost = 999;
		cin >> r >> c;
		cin >> x[0] >> y[0];
		cin >> num_beep;
		for (int i = 1; i <= num_beep; i++)
		{
			cin >> x[i] >> y[i];
			visited[i] = 0;
		}
		beep_collection(0, 0, 0);
		cout << "The shortest path has length " << min_cost << endl;
	}
	return 0;
}