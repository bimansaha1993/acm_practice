#include<bits/stdc++.h>

using namespace std;

int n, arr[13];

int getval(int mask, int pos)
{
	int lft = -1, rgt = -1;
	for (int i = pos - 1; i >= 0; i--)
	{
		if (mask&(1 << i)){}
		else {
			lft = i;
			break;
		}
	}

	for (int i = pos + 1; i<n; i++)
	{
		if (mask&(1 << i)){

		}
		else{
			rgt = i;
			break;
		}
	}

	if (lft != -1 && rgt != -1)
	{
		return arr[lft] * arr[rgt];
	}
	else if (lft == -1 && rgt != -1)
	{
		return arr[rgt];
	}
	else if (lft != -1 && rgt == -1)
	{
		return arr[lft];
	}
	else return arr[pos];

}

int dp[2000000];

int go(int mask)
{
	if (mask == (1 << n))return 0;

	if (dp[mask] != -1)return dp[mask];

	int ret = 0;
	int score = 0;
	for (int i = 0; i<n; i++)
	{
		if (mask&(1 << i)){}
		else{
			ret = getval(mask, i) + go(mask | (1 << i));
		}

		if (ret>score)score = ret;
	}
	return dp[mask] = score;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		memset(dp, -1, sizeof dp);
		cout << go(0) << endl;
	}
	return 0;
}
