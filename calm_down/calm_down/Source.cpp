#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
#define eps 1e-7
int main()
{
	double r, R, N, l, m, x, y, pi=2*acos(0.0);
	int t, i;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> R >> N;
		l = 0.0; r = R;
		while (fabs(l-r)>eps)
		{
			m = (l + r) / 2;
			x = m / (R - m);
			y = sin(pi / N);
			if (x > y)
				r = m;
			else 
				l = m;
		}
		cout << "Case " << i << ": " << setprecision(11) << l << endl;
	}
	return 0;
}