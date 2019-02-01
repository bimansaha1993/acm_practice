#include<iostream>
using namespace std;
int main()
{
	long int n, a[1002], b[1002], i, min=1001, cnt,l;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (n!=0)
	{
		for (i = 0; i < n; i++) 
		{
			if (i == 0)
				min = a[i];
			else
			{
				if (a[i] < min)
					min = a[i];
			}
		}
		l = 0, cnt = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] >= min)
			{
				cnt++;
				a[i] = a[i] - min;
				if (a[i] != 0)
				{
					b[l] = a[i];
					l++;
				}	
			}
		}
		cout << cnt << endl;
		n = l;
		for (i = 0; i<l; i++)
		{
			a[i] = b[i];
		}
	}
	return 0;
}