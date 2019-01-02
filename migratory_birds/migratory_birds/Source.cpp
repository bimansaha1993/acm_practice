#include<iostream>
using namespace std;
int main()
{
	long long int n, a[99999], cnt[6], i, max = 0,min;
	cin >> n;
	for (i = 1; i <=5; i++){
		cnt[i] = 0;
		min = i;
	}
	for (i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (i = 1; i <= 5; i++)
	{
		if (cnt[i] > max){
			max = cnt[i];
			min = i;
		}
	}
	cout << min << endl;
	return 0;
}