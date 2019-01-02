#include<iostream>
using namespace std;

int weight[100], cost[100],cap,n,a[100][100];

int knapsack(int i, int w)
{
	int profit1=0, profit2=0;
	if (i >=n)
		return 0;
	if (a[i][w] != -1)
		return a[i][w];
	if (w + weight[i] <= cap)
		profit1 = cost[i] + knapsack(i + 1, w + weight[i]);
	profit2 = knapsack(i + 1, w);
	if (profit1 > profit2)
		return a[i][w]=profit1;        ///profit1;
	else
		return a[i][w]=profit2;        ///profit2;

}
int main()
{
	cin >> n >> cap;
	int w=0,i,result,j;
	for (i = 0; i < n; i++)
	{
		cin >> weight[i] >> cost[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= cap; j++)
		{
			a[i][j] = -1;
		}
	}
	result = knapsack(0, w);
	cout << result;
	return 0;
}