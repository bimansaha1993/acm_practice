#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define eps 1e-10
int main()
{
	int c, time;
	cin >> c >> time;
	double low = 0, high = 2000000000, mid;
	while (abs(low - high)>eps)
	{
		mid = (low + high) / 2;
		double a = c*mid*log(mid);
		if (abs(a-time) <= eps)
		{
			low = mid;
			break;
		}
		else if (a < time)
			low = mid ;
		else
			high = mid ;
	}
	cout << setprecision(15) << mid << endl;
	return 0;
}
