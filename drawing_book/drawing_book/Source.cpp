#include<iostream>
using namespace std;
int main()
{
	long int n, p, min, total, right, left;
	cin >> n >> p;
	total = n / 2;
	right = p / 2;
	left = total - right;
	if (right < left){
		min= right;
	}
	else {
		min = left;
	}
	cout << min;
	return 0;
}