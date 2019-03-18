#include<iostream>
#include<iomanip>
using namespace std;

int k, board[9][9],used[9][9],ans;

int checkleftdigonal(int i, int j)
{
	while (i >= 0 && j >= 0)
	{
		if (used[i][j])
		{
			return 0;
		}
		i--; 
		j--;
	}
	return 1;
}

int checkrightdigonal(int i, int j)
{
	while (i >= 0 && j < 8)
	{
		if (used[i][j])
		{
			return 0;
		}	
		i--;
		j++;
	}
	return 1;
}

int checkup(int i, int j)
{
	while (i >= 0)
	{
		if (used[i][j])
		{
			return 0;
		}
		i--;
	}
	return 1;
}

void max_score(int i,int sum)
{
	if (i == 8)
	{
		if (sum > ans)
		{
			ans = sum;
		}
		return;
	}
	for (int j = 0; j < 8; j++)
	{
		if (checkleftdigonal(i,j) && checkrightdigonal(i,j) && checkup(i,j))
		{
			used[i][j] = 1;
			max_score(i + 1, sum + board[i][j]);
			used[i][j] = 0;
		}
	}
}

int main()
{
	cin >> k;
	for (int t = 0; t < k; t++)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> board[i][j];
				used[i][j] = 0;
			}
		}
		ans = 0;
		max_score(0,0);
		cout<<setw(5) << ans << endl;
	}
	return 0;
}