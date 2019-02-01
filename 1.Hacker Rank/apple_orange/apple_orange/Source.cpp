#include <iostream>
using namespace std;
int main()
{
	long long int s, t, a, b, m, n, app[10001], orn[10001], i, ac = 0, oc = 0, d, e;
	cin >> s >> t;
	cin >> a >> b;
	cin >> m >> n;
	for (i = 1; i <= m; i++)
	{
		cin >> app[i];
		d = a + app[i];
		if (d >= s&&d <= t)
			ac++;
	}
	for (i = 1; i <= n;i++)
	{
		cin >> orn[i];
		e= b+ orn[i];
		if (e>= s&&e<= t)
			oc++;
	}
	cout << ac << endl;
	cout << oc << endl;
	return 0;
	
}