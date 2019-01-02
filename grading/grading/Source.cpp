#include<iostream>
using namespace std;
int main()
{
	long int a[100], n, i, round, b, c;
	cin >> n;
	if (n >= 1 && n <= 100){
		for (i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (i = 1; i <= n; i++){
			if (a[i]>=38){
				if (a[i] % 5 != 0){
					b = a[i] % 5;
					c = a[i] + (5 - b);
					if (c - a[i] < 3)
						round = c;
					else if (c - a[i] == 3)
						round = a[i];
					else
						round = a[i];
				}
				else
					round = a[i];
			}
			else
				round = a[i];
			cout << round << " " << endl;
		}
	}
	return 0;
}