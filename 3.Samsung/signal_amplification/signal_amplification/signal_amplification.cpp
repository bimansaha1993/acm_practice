#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, k, array[4][4], cpy_array[4][4];
int vec[4];

void apply_lasser(int c)
{
	for (int i = 0; i < n; i++)
	{
		cpy_array[i][c] ^= 1;
	}
}

void cpy()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cpy_array[i][j] = array[i][j];
		}
	}
}

int calculate()
{
	cpy();
	for (int c = 0; c < m; c++)
	{
		if (vec[c] == 1)
		{
			apply_lasser(c);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		bool has_zero = false;
		for (int j = 0; j < m; j++)
		{
			if (cpy_array[i][j] == 0)
			{
				has_zero = true;
				break;
			}
		}
		if (!has_zero)
			cnt++;
	}
	return cnt;
}

int solve(int i, int c)
{
	if (i >= m)
	{
		if (c == 0)
		{
			return calculate();
		}
		return 0;
	}
	if (c == 0)
	{
		return calculate();
	}
	int mx = 0;
	for (int j = 0; j < c; j++)
	{
		vec[i] ^= 1;                   //vec[i]^=j%2;
		int ret1 = solve(i, c - 1);    //int ret1=solve(i+1,c-1);
		vec[i] ^= 1;                   //vec[i]^=j%2;
		int ret2 = solve(i + 1, c);    //if(ret1>mx)
		if (ret1 > ret2)               //mx=ret1;
			mx = ret1;                 //else
		else                           // mx=mx;
			mx = ret2;
	}
	return mx;
}

int main()
{
	int test_case, case_no = 1;
	cin >> test_case;
	for (int t = 1; t <= test_case;t++)
	{ 
		cin >> n >> m >> k;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				cin >> array[i][j];
				vec[j] = 0;
			}
		}
		cout << "#" << t << " " << solve(0, k) << endl;
	}
	return 0;
}
