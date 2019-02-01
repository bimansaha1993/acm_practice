#include<iostream>
using namespace std;
int main()
{
	int i, j, k, n, rev=0, rem,num,cnt=0;
	cin >> i >> j >> k;
	for (n = i; n <= j; n++)
	{
		rev = 0, rem = 0, num = n;
		while (num != 0)
		{
			rem = num % 10;
			rev = (rev * 10) + rem;
			num = num / 10;
		}
		if (abs(n - rev) % k == 0)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}