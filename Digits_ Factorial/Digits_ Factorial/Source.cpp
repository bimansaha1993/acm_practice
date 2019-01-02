#include<iostream>
#include<cmath>
using namespace std;
#define  MAX_N (int)1e5+5 ////////for ignore time limit
int main()
{
	int t, n, k, i, j,result;
	double digit[MAX_N];
	digit[0] = 0;
	for (i = 1; i < MAX_N; i++)
	{
		digit[i] = digit[i - 1] + log(i);
	}
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n >> k;

		result = (digit[n] / log(k)) + 1;

		cout << "Case " << i << ": " << result << endl;
	}
	/*for (i = 1; i <= t; i++)
	{
		cin >> n >> k;
		digit = 0;
		for (j = 1; j <=n; j++)
		{
			digit =digit+(log(j)/log(k));
		}
		cout << "Case " << i << ": " << ((int)digit+1) << endl;
	}*/
	return 0;
}