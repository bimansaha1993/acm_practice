#include<iostream>
using namespace std;

long long int weight[1003], cost[1003], cap[101], n, a[1003][1003];

long long int knapsack(long long int i, long long int w, long long e)
{
	long long int profit1 = 0, profit2 = 0;
	if (i >= n)
		return 0;
	if (a[i][w] != -1)
		return a[i][w];
	if (w + weight[i] <= e)    ////// (w-weight[i]>=0) {beshi thake komale parameter o kombe ekta}
		profit1 = cost[i] + knapsack(i + 1, w + weight[i],e);   ///w-weight[i]  {beshi thake komale parameter o kombe ekta}
	profit2 = knapsack(i + 1, w,e);
	if (profit1 > profit2)
		return  a[i][w]=profit1;        ///profit1;
	else
		return  a[i][w]=profit2;        ///profit2;

}

int main()
{
	int t,m;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		long long int result = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> cost[i] >> weight[i];
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> cap[i];
			for (int l = 0; l < n; l++)
			{
				for (int j = 0; j <= cap[i]; j++)
				{
					a[l][j] = -1;
				}
			}
			result = result + knapsack(0, 0, cap[i]);
		}
		cout << result<<endl;
	}
	return 0;
}