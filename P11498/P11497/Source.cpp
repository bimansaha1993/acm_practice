#define _CRT_SECURE_NO_WARNNINGS
#include<iostream>
using namespace std;
int main()
{
	int k, n, m, x[20000], y[20000], i;
	cin >> k;
	while (k != 0) {
		if (k > 0 && k <= 1000){
			cin >> n >> m;
			if (-10000 < n && m<10000){
				for (i = 1; i <= k; i++){
					cin >> x[i] >> y[i];
				}
				for (i = 1; i <= k; i++){
					if (-10000 <= x[i] && y[i] <= 10000){
						if (x[i] == n || y[i] == m)
							cout << "divisa";
						else if (x[i] < n && y[i] > m)
							cout << "NO";
						else if (x[i] > n && y[i] > m)
							cout << "NE";
						else if (x[i] > n && y[i] < m)
							cout << "SE";
						else if (x[i] < n && y[i] < m)
							cout << "SO";
						cout << endl;
						}
					}
				}
			}
		cin >> k;
		}
	return 0;
}