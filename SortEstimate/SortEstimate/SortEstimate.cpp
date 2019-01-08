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
		double a = c*mid*log2(mid);
		if (abs(a-time)<=eps )
		{
			low = mid;
<<<<<<< HEAD
			//cout << setprecision(15) << mid << endl;
=======
>>>>>>> f02d47311698ff074e24d8f597b0aeb1a8f0da6c
			break;
		}
		else if (a < time)
			low = mid ;
		else
			high = mid ;
	}
<<<<<<< HEAD
	
	cout << setprecision(15) << low << endl;
=======
	cout << setprecision(15) << mid << endl;
>>>>>>> f02d47311698ff074e24d8f597b0aeb1a8f0da6c
	return 0;
}
