#include<iostream>
using namespace std;
int main()
{
	int n, a[101], cnt[100], i, pair=0;
	cin >> n;
	for (i = 1; i <= 100; i++){
		cnt[i] = 0;
	}
	for (i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] == 2)
		{
			cnt[a[i]] = 0;
			pair++;
		}
	}
	/*for (i = 1; i <= 100; i++)
	{
		pair = pair + cnt[i] / 2;
	}*/
	cout << pair << endl;
	return 0;
}