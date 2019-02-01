#include<iostream>
using namespace std;
int main()
{
	long int n, a[1000], i, max = 0, min = 0, cmax = 0, cmin = 0;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 1){
			max = a[i];
			min = a[i];
		}
		else if (a[i] > max){
			max = a[i];
			cmax++;
		}
		else if (a[i] < min){
			min = a[i];
			cmin++;
		}
	}
	cout << cmax <<" " << cmin;
	return 0;
}