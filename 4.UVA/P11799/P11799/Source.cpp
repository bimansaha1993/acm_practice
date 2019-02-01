#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t, n, i, j, b, m;
	cin >> t;
	for (i = 1; i <= t; i++){
		cin >> n;
		m = 0;
		for (j = 1; j <= n; j++){
			cin >> b;
			if (b > m){
				m = b;
			}
		}
		cout << "Case " << i << ": ";
		cout << m << endl;
	}
	return 0;
}