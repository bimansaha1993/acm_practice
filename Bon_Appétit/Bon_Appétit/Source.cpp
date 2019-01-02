#include<iostream>
using namespace std;
int main()
{
	long int n, k, a[100000], b, i, sum1 = 0, sum2 = 0, charge;
	cin >> n >> k;
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> b;
	for (i = 0; i < n; i++)
	{
		if (i != k)
			sum2 = sum2 + a[i];
		else
			sum1 = sum1 + a[i];
	}
	sum1 = (sum1+sum2) / 2;
	sum2 = sum2 / 2;
	cout << sum1 << " " << sum2<<endl;
	if (b!=sum2)
	{
		charge = sum1 - sum2;
		cout << charge << endl;
	}
	else
		cout << "Bon Appetit" << endl;
	return 0;
}