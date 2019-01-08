#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define eps 1e-10
int main()
{
	double price, payment, loan;
	cin >> price >> payment >> loan;
	double low = 0, high = 100, mid,mi,balance;
	while (abs(low - high)>eps)
	{
		balance = price;
		mid = (low + high) / 2;
		mi = mid / 12;
		for (int i = 0; i < loan; i++)
		{
			balance = balance + (balance*mi) / 100;
			balance = balance - payment;
		}
		if (abs(balance) <= eps)
		{
<<<<<<< HEAD
			low = mid;
=======
			low=mid;
>>>>>>> f02d47311698ff074e24d8f597b0aeb1a8f0da6c
			break;
		}
		else if (balance < 0)
			low = mid;
		else
			high = mid;
	}
<<<<<<< HEAD
	cout << setprecision(15) << low << endl;
=======
	cout << setprecision(15) << mid << endl;
>>>>>>> f02d47311698ff074e24d8f597b0aeb1a8f0da6c
	return 0;
}
