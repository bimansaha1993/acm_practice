#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int computer, x[9], y[9], visited[9], data[9], path[9];
double length[9][9], min_cost = 9999.0;

void calculate_length(int i,double cost)
{
	if (i == computer)
	{
		if (cost < min_cost)
		{
			min_cost = cost;
			for (int j = 0; j < computer; j++)
			{
				path[j] = data[j];
			}
		}
		return;
	}
	for (int j = 0; j < computer; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			data[i] = j;
			calculate_length(i + 1, cost + length[data[i-1]][j]);
			visited[j] = 0;
		}
	}
}

int main()
{
	int test = 1;
	while (true)
	{
		cin >> computer;
		if (computer == 0)
			break;
		for (int i = 0; i < computer; i++)
		{
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < computer; i++)
		{
			for (int j = 0; j < computer; j++)
			{
				length[i][j] = sqrt(((x[i] - x[j])*(x[i] - x[j])) + ((y[i] - y[j])*(y[i] - y[j]))) + 16;
			}
			visited[i] = 0;
		}
		for (int i = 0; i < computer; i++)
		{
			visited[i] = 1;
			data[0] = i;
			calculate_length(1, 0);
			visited[i] = 0;
		}
		cout << "**********************************************************" << endl;
		cout << "Network #" << test << endl;
		for (int i = 1; i < computer; i++)
		{
			cout << "Cable requirement to connect (" << x[path[i-1]] <<"," << y[path[i-1]] << ") to (" << x[path[i]] <<"," << y[path[i]] << ") is " << length[path[i-1]][path[i]] << " feet."<< endl;
		}
		cout << "Number of feet of cable required is " << min_cost << endl;
		test++;
	}
	return 0;
}