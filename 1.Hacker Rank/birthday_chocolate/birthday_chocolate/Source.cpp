#include <iostream>
using namespace std;
int main()
{
	int n, a[101], d, m, i, count = 0, s, l;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> d >> m;
	for (i = 1; i <= n;i++)
	{
		s = 0;
		for (l = 0; l < m;l++)
		{
			s = s + a[l + i];
		}
		if (s == d)
			count++;
	}
	cout << count;
	return 0;
}