#include<iostream>
using namespace std;

int n, a[100];

void solve(int i)
{
	if (i == n)
	{
		for (int l = 0; l < n; l++)
		{
			for (int m = l + 1; m < n; m++)
			{
				if (a[l] == a[m])
					return;
			}
		}
		for (int k = 0; k < n; k++)
		{
			cout << a[k];
		}
		cout << endl;
		return;
	}
	for (int j = 0; j < n; j++)
	{
		a[i] = j;
		solve(i + 1);
	}
	/*a[i] = 0;
	solve(i + 1);
	a[i] = 1;
	solve(i + 1);*/
}

int main()
{
	cin >> n;
	solve(0);
	return 0;
}