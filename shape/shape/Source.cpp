#include<iostream>
using namespace std;
int main()
{
	int i, j, n, k, l = 1, m = 1;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << "*";
			if (i != j)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;


	for (i = 1; i <= n; i++)
	{
		for (j = n; j >=i; j--)
		{
			cout << "*";
			if (i != j)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;


	for (i = 1; i <= n; i++)
	{
		for (k = n-1; k > n - i; k--)
		{
			cout << "  ";
		}
		for (j = n; j >= i; j--)
		{
			cout << "*";
			if (i != k)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;


	for (i = 1; i <= n; i++)
	{
		for (k = n - 1; k >= i; k--)
		{
			cout << "  ";
		}
		for (j = 1; j <= i; j++)
		{
			cout << "*";
			if (i != k)
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	/////////////// pyramid /////////////
	for (i = 1; i <= n; i++)
	{
		for (k = 1; k <= n-i; k++)
		{
			cout << "  ";
		}
		for (j = 1; j <= (2 * i) - 1; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;


	for (i = n; i > 0  ; i--)
	{
		for (k = 1; k <=n - i; k++)
		{
			cout << "  ";
		}
		for (j = 1; j <= (2 * i) - 1; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;

	/////////////// Diamond /////////////
	for (i = 1; i <= n; i++)
	{
		for (k = l; k <(n / 2 + 1); k++)
		{
			cout << "  ";
		}
		for (j = 1; j <= m; j++)
		{
			cout << "* ";
		}
		if (i < (n / 2 + 1))
		{
			l++;
			m = m + 2;
		}
		else if (i >= (n / 2 + 1))
		{
			l--;
			m = m - 2;
		}
		cout << endl;
	}
	cout << endl;

////////////////// Rectrangular //////////////////
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "*";
			if (j<n)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;


	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == 1 || i == n || j == 1 || j == n)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			if (j<n)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}