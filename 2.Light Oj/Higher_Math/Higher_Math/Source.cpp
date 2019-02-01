#include<iostream>
using namespace std;
int main()
{
	long long int t, a, b, c, i, d, e,f;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> a >> b >> c;
		d = a * a;
		e = b * b;
		f = c * c;
		if ((d+e) == f || (e+f)==d || (d+f)==e)
			cout << "Case " << i << ": " << "yes" << endl;
		else
			cout << "Case " << i << ": " << "no" << endl;
	}
	return 0;
}