#include<iostream>
using namespace std;

double plusMinus(double a, double b, double c,int d){
	a = a / d;
	b = b / d;
	c = c / d;
	cout << a << endl << b << endl << c << endl;
	return 0;
}
int main(){
	int n, a[100], i;
	double plus=0, neg=0, zero=0;
	cin >> n;
	if (n > 0 && n <= 100){
		for (i = 0; i < n; i++){
			cin >> a[i];
			if (a[i]>0)
				plus++;
			else if (a[i] < 0)
				neg++;
			else if (a[i] == 0)
				zero++;
		}
		//plus = plus / n;
		//neg = neg / n;
		//zero = zero / n;
		//cout << plus << " " << neg << " " << zero << endl;
		plusMinus(plus, neg, zero, n);
	}
}