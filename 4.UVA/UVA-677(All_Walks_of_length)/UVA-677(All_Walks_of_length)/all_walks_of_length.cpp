#include<iostream>
using namespace std;

int n, m, e, a[15][15], out[15], fg, taken[15];

void rec(int node, int l)
{
	int i;
	if (l == e + 1)
	{
		cout << "(1";
		for (i = 1; i < l; i++)
		{
			cout << "," << out[i];
		}
		cout << ")" << endl;
		fg = 1;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (a[node][i] == 1 && taken[i] == 0)
		{
			taken[i] = 1;
			out[l] = i;
			rec(i, l + 1);
			taken[i] = 0;
		}
	}
}

int main()
{
	int i, j;
	while (cin>>n)
	{
		if (n == -9999)
		{
			cout << endl;
			continue;
		}
		cin >> e;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				cin >> a[i][j];
			}	
			taken[i] = 0;
		}
		fg = 0;
		taken[1] = 1;
		rec(1, 1);
		if (!fg)
			cout << "no walk of length" << e << endl;
	}
	return 0;
}