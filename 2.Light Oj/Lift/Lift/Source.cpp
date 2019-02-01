#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t, m, l, i,time;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> m >> l;
		time = (abs(l - m) * 4) + (3 * 3) + (2 * 5) + (m * 4);
		cout <<"Case " << i << ": " << time << endl;
	}
	return 0;
}