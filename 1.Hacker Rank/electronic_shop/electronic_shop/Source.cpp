#include<iostream>
using namespace std;
int main()
{
	int b, n, m, k[1000], d[1000], i, j, sum, max=-1;
	cin >> b >> n >> m;
		for (i = 1; i <= n; i++)
		{
			cin >> k[i];
		}
		for (j = 1; j <= m; j++)
		{
			cin >> d[j];
		}
		for (i = 1; i <= n; i++)
		{
			sum = 0;
			for (j = 1; j <= m; j++)
			{
				sum = k[i] + d[j];
				if (sum <= b){
					if (sum > max)
					{
						max = sum;
					}
				}
			}
		}
		cout << max << endl;
	return 0;
}