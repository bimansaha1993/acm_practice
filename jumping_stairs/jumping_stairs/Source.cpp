#include<iostream>
using namespace std;

int n, jumps[100], m, a[100];

int f(int i)
{
	if (i == n)
		return 0;
	if (a[i] != -1)
		return a[i];
	int min = 20, r;
	for (int j = 0; j < m; j++)
	{
		if (i + jumps[j] <= n)
		{
			r = f(i + jumps[j]) + 1;
			if (min > r){
				min = r;
			}
		}
	}
	return a[i]=min;
}

int main()
{
	cin >> n>> m;
	for (int i = 0; i < m; i++)
	{
		cin >> jumps[i];
	}
	for (int i = 0; i <= n; i++)
	{
		a[i] = -1;
	}
	int result = f(0);
	cout << result << endl;
	return 0;
}