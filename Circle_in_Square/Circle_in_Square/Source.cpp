#include<iostream>
#include <iomanip>
#include<cmath>

using namespace std;
int main()
{
	double t, r, ac, pi=2*acos(0), as, a, result;
	cin >> t;
	for (int i = 1; i <=t; i++)
	{
		cin >> r;
		ac = pi*(r*r);
		a = 2 * r;
		as = a*a;
		result = as - ac;
		//cout << result << endl;
		cout << "Case " << i << ": " << setprecision(2) << fixed << result << endl;
		//printf("%.2f\n", result);
	}
	return 0;
}