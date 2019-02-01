#define _CRT_SECURE_NO_WARNNINGS
#include<iostream>
using namespace std;
long long int array[10001], a, b, c, d, e, f;
long long int fn(int n)
{
	if (n == 0) return array[n] = a;
	if (n == 1) return array[n] = b;
	if (n == 2) return array[n] = c;
	if (n == 3) return array[n] = d;
	if (n == 4) return array[n] = e;
	if (n == 5) return array[n] = f;
	if (array[n] != -1)
		return array[n];
	array[n] = (fn(n - 1) + fn(n - 2)  + fn(n - 3)  + fn(n - 4)  + fn(n - 5)  + fn(n - 6) ) % 10000007;
	return array[n];
}
int main() 
{
	long long int n, t, i, j, ar[10001];
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> a >> b >> c >> d >> e >> f >> n;
		//cin >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4] >> ar[5] >> n;
		for (j = 0; j <= n; j++)
		{
			array[j] = -1;
		}
		cout << "Case " << i << ": " << fn(n) % 10000007 << endl;   //https://ideone.com/otuGLl    //https://ideone.com/SpMKCU  //https://ideone.com/MhnfTf
		/*for (j = 0; j <= n; j++)
		{
			if (j == 0)
				ar[j] = a;
			else if (j == 1)
				ar[j] = b;
			else if (j == 2)
				ar[j] = c;
			else if (j == 3)
				ar[j] = d;
			else if (j == 4)
				ar[j] = e;
			else if (j == 5)
				ar[j] = f;
			else
				ar[j] = (ar[j - 1] + ar[j - 2] + ar[j - 3] + ar[j - 4] + ar[j - 5] + ar[j - 6]) % 10000007;
		}
		cout << "Case " << i << ": " << ar[n] % 10000007 << endl;*/
	}
	return 0;
}
