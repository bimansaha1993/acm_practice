#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int t, n, i, sq, r,c,u,l,d1,d2;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n;
		sq =sqrt(n);
		if (sq*sq == n)
		{
			if (n % 2 == 0)
			{
				r = sq;
				c = 1;
			}
			else
			{
				r = 1;
				c = sq;
			}
		}
		else
		{
			u = (sq + 1)*(sq + 1);
			l = sq*sq;
			d1 = u - n;
			d2 = n - l;
			if (d1 < d2)
			{
				if (u % 2 == 0)
				{
					r = sq + 1;
					c = d1 + 1;
				}
				else
				{
					r = d1 + 1;
					c = sq + 1;
				}
				
			}
			else if (d2<d1)
			{
				if (l % 2 == 0)
				{
					r = sq + 1;
					c = d2;
				}
				else
				{
					r = d2;
					c = sq+1;
				}
				
			}
		}
		cout << "Case " << i << ": " << r << " " << c << endl;
	}
	return 0;
}