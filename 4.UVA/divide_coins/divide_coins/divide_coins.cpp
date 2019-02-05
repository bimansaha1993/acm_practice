#include<iostream>
#include<cmath>
using namespace std;
#define size_sum 50001
int n, m, a[101], coins[101], total, ans, dp[101][size_sum];
int rec(int i,int sum1)
{
	int sum2, left, right;
	if (i == m)
	{
		int sum2 = total-sum1;
		return dp[i][sum1]=abs(sum1 - sum2);
	}
	if (dp[i][sum1] != -1)
		return dp[i][sum1];
	a[i] = 0;
	left=rec(i + 1,sum1);
	a[i] = 1;
	right=rec(i + 1,sum1+coins[i]);
	if (left < right)
		return dp[i][sum1]=left;
	else
		return dp[i][sum1]=right;
}

void reccase()
{
	total = 0;
	for (int i = 0; i < m; i++)
	{
		total = total + coins[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < size_sum; j++)
		{
			dp[i][j] = -1;
		}
	}
	ans = rec(0, 0);
	cout << ans << endl;
}

int main()
{
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> coins[i];
		}
		reccase();
	}
	return 0;
}