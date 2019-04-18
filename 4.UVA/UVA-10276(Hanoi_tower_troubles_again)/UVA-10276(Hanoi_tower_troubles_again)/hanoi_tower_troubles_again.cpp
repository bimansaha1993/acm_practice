#include<iostream>
using namespace std;

int n, page[51], ans;

int issqrt(int a)
{
	for (int i = 0; i*i <= a; i++)
	{
		if (i*i == a)
			return 1;
	}
	return 0;
}

void solve(int v, int p)
{
	if (p == n)
		return;
	if (page[p]==0)
	{
		page[p] = v;
		ans++; 
		solve(v + 1, p);
		return;
	}
	for (int i = 0; i <= p; i++)
	{
		if (issqrt(v + page[i]))
		{
			page[i] = v;
			ans++;
			solve(v + 1, p);
			return;
		}
	}
	solve(v, p + 1);
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			page[i] = 0;
		}
		solve(1, 0);
		cout << ans << endl;
	}
	return 0;
}