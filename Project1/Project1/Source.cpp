#include<iostream>
using namespace std;
int main()
{
	long long int a[10000], i, j,sum,max=0,min=0;
	for (i = 1; i <= 5; i++){
		cin >> a[i];
	}
	for (i = 1; i <= 5; i++){
		sum = 0;
		for (j = 1; j <= 5; j++){
			if (i != j){
				sum = sum + a[j];
			}
		}
		if (i == 1){
			max = sum;
			min = sum;
		}
		else{
			if (sum > max)
				max = sum;
			else if (sum < min)
				min = sum;
		}
	}
	cout << min <<" "<<max << endl;
	return 0;
}