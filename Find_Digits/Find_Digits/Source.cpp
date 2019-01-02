#include<iostream>
using namespace std;
int main()
{
	int t, n, digit, value, cnt, i;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		cnt = 0;
		value = n;
		while (value > 0)
		{
			digit = value % 10;
			value = value / 10;
			if (digit > 0 && n % digit == 0)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}