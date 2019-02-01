#include<iostream>
using namespace std;
int main()
{
	int t, n, m, s, i, a;
	cin >> t;
	
	for (i = 1; i <= t; i++)
	{
		cin >> n >> m >> s;
		a = m + s - 1;
		if (a > n)
		{
			if (a%n == 0)
				cout << n << endl;
			else
				cout << a%n << endl;
		}
		else
			cout << a << endl;
	}
	return 0;
}