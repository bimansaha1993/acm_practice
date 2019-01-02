#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int n, a[10001], b[10001], i, j, k, maxa = 0, mina = 0, maxb = 0, minb = 0, counta = 0, countb = 0;
	cin >> n;
	if (n >= 1 && n <= 100){
	for (i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 1)
			mina = a[i];
		else if (a[i] > maxa)
			maxa = a[i];
		else if (a[i] < mina)
			mina = a[i];
	}
	for (i = 1; i <= n; i++){
		cin >> b[i];
		if (i == 1)
			minb = b[i];
		else if (b[i] > maxb)
			maxb = b[i];
		else if (b[i] < minb)
			minb = b[i];
	}
	for (j = mina; j <= maxa; j++){
		int x = sqrt(j);
		if (x*x == j)
			counta++;
		/*for (i = 1; i <= j / 2; i++){
			if (i*i == j)
				counta++;
		}*/
	}
	cout << counta << endl;
	for (k = minb; k <= maxb; k++){
		int y = sqrt(k);
		if (y*y == k)
			countb++;
		/*for (i = 1; i <= k / 2; i++){
			if (i*i == k)
				countb++;
		}*/
	}
	cout << countb << endl;
}
	return 0;
}