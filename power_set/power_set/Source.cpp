#include<iostream>
using namespace std;

int n, a[100];

void read()
{
	cin >> n;
}

void print()
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void solve(int i)
{
	if (i == n)
	{
		print();
		return ;
	}
	a[i] = 0;
	solve(i + 1);
	a[i] = 1;
	solve(i + 1);
}

int main()
{
	read();
	solve(0);
	return 0;
}