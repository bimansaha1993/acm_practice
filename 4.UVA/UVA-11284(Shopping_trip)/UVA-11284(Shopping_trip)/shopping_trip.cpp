#include<iostream>
using namespace std;

int num_shop, num_road, num_dvd,x[1001],y[1001],found[15],visit[1001];
double cost[1001], save[15], min_cost, amazon_save;

void max_save(int i,int cnt,double costing)
{
	if (cnt == num_road)
	{
		if (costing < min_cost)
		{
			min_cost = costing;
		}
		return;
	}
	for (int j = 1; j < num_road; j++)
	{
		if (visit[j] == 0)
		{
			visit[j] = 1;
			max_save(j, cnt++, costing + cost[j]);
			visit[j] = 0;
		}
	}
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		min_cost = 999,amazon_save=0;
		cin >> num_shop >> num_road;
		for (int i = 0; i < num_road; i++)
		{
			cin >> x[i] >> y[i] >> cost[i];
		}
		cin >> num_dvd;
		for (int i = 0; i < num_dvd; i++)
		{
			cin >> found[i] >> save[i];
			amazon_save = amazon_save + save[i];
		}
		max_save(0, 0, 0);
		cout << amazon_save << " " << min_cost << endl;
	}
	return 0;
}