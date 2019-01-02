#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	long long int a[100001], n, i, max = 0, count = 0;
	cin >> n;
	if (n >= 1 && n <= 100000){
		for (i = 1; i <= n; i++){
			cin >> a[i];
			if (a[i] > max)
				max = a[i];
		}
		for (i = 1; i <= n; i++){
			if (a[i] == max)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}