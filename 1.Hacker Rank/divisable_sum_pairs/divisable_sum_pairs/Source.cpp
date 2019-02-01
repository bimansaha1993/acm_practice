#include<iostream>
using namespace std;

int main()
{
	long int n, k, a[100], i, j, count=0;
	cin >> n >> k;
	for (i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (i = 1; i <= n; i++){
		for (j = i+1; j <= n; j++){
			if ((a[i] + a[j]) % k == 0)
				count++;
		}
	}
	cout << count;
	return 0;
}