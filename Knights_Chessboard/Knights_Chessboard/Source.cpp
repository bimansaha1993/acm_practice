#include<iostream>
using namespace std;
int main()
{
	long long int t, m, n, c, i, kn, temp, q, r, min;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> m >> n;
		if (n==1||m==1)
		{
			if (m == 1)
			{
				kn = n;
			}
			else if (n==1)
			{
				kn = m;
			}
		}
		else if (m==2||n==2)
		{
			if (m == 2)
			{
				q = n / 4;
				r = n % 4;
				if (r > 2)
					r = 2;
				kn = (q * 4) + (r * 2);
			}
			else if (n == 2)
			{
				q = m / 4;
				r = m % 4;
				if (r > 2)
					r = 2;
				kn = (q * 4) + (r * 2);
			}
		}
		else
		{
			c = m*n;
			if (c % 2 == 0)
			{
				kn = c / 2;
			}
			else
			{
				kn = c / 2 + 1;
			}
		}
		cout << "Case " << i << ": " << kn << endl;
	}
	return 0;
}