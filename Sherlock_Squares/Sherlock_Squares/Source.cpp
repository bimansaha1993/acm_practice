#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t, a, b, i, j, x, k, temp, cnt;
	cin >> t;
	for (i = 1; i <=t; i++)
	{
		cin >> a >> b;
		if (a > b)
		{
			temp = a;
			a = b;
			b = temp;
		}
		cnt = 0;
		for (j = 1; ; j++)   ////// optimize solve ///////
		{
			if (j*j > b)
				break;
			else if (j*j >= a && j*j <= b)
				cnt++;
		}           /////////// end ///////////
		/*for (j = a; j <= b; j++)
		{
			x = sqrt(j);    ////// solve 2//////
			if (x*x == j)
			{
				cnt++;
			}      ////// sole 2 end ///////
			/*for (k = 1; k <= j / 2; k++) ////// solve 1 ///////
			{
				if (k*k == j)
				{
					cnt++;
				}
			}*/ //////// solve 1 //////
		//}
		cout << cnt << endl;
	}
	return 0;
}