#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n, i, a, count;
	cin >> n;
	count = 1;
	cout << n << " ";
	while (n > 1){
		if (n % 2 == 1){
			n = (3 * n) + 1;
		}
		else{
			n = n / 2;
		}
		cout << n << " ";
		count++;
	}
	cout << endl << count;

	/*int n,i,a,count;
	count = 1;
	for (i = 1; i <= 2; i++){
	cin >> n;
	a = n;
	while (n > 1 && n < 10000){
	if (n % 2 == 1){
	n = (3 * n) + 1;
	}
	else{
	n = n / 2;
	}
	//cout << n << " ";
	count++;
	}
	}cout << "for " << a << ": " << count <<endl;*/
	return 0;
}