#include<iostream>
using namespace std;
int main()
{
	int n, m, a[101], b[101], i, j, count=0, max=0, min=0;
	cin >> n >> m;
	if (n >= 1 && n <= 10 && m >= 1 && m <= 10){
		for (i = 1; i <= n; i++){
			cin >> a[i];
			if (a[i] > max)
				max = a[i];
		}//cout << max << endl;
		for (i = 1; i <= m; i++){
			cin >> b[i];
			if (i == 1)
				min = b[i];
			else if (b[i] < min)
				min = b[i];
		}//cout << min << endl;
	}
	for (j = max; j <= min; j++)
	{
		int flag = 1;
		for (i = 1; i <= n; i++)
		{
			if (j % a[i] != 0)
				flag = 0;
			//cout << flag << endl;
		}//cout << " " << endl;
		for (i = 1; i <= m; i++)
		{
			if (b[i] % j != 0)
				flag = 0;
			//cout << flag << endl;
		}//cout << " " << endl;
		if (flag == 1)
			count++;
	}
	cout<<count<<endl;
	return 0;
}