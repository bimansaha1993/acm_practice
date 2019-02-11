#include<iostream>
using namespace std;

long long int a[35], cnt=0;

long long int binary(int n)
{
	long long int next_orginal, j = 0;
	next_orginal = n;
	int next_cnt = 0;
	while (n > 0)
	{
		a[j] = n % 2;
		n = n / 2;
		j++;
	}
	for (int l = j - 1; l >= 0; l--)
	{
		if (a[l] == 1)
			next_cnt++;
	}
	if (next_cnt == cnt)
		return next_orginal;
	binary(next_orginal + 1);
}

int main()
{
	long long int t, n,orginal,ans;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		cin >> n;
		orginal = n;
		int j = 0;
		for (int x = 0; x <= 35; x++)
		{
			a[x] = 0;
		}
		while (n > 0)
		{
			a[j] = n % 2;
			n = n / 2;
			j++;
		}
		for (int l = j - 1; l >= 0; l--)
		{
			if (a[l] == 1)
				cnt++;
		}
		ans=binary(orginal+1);
		cout << "Case " << k << ": " << ans << endl;
	}
	return 0;
}