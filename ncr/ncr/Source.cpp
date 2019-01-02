#include<iostream>
using namespace std;

long long int a[100][100];

long long c(int n, int r)
{
	if (n == r|| r==0)
		return a[n][r]=1;
	//if (r == 1)
		//return a[n][r]=n;
	if (a[n][r] != -1)
		return a[n][r];
	return a[n][r]=c(n - 1, r) + c(n - 1, r - 1);
}

int main()
{
	int n, r,i,j;
	cin >> n >> r;
	for (i = 0; i <=100; i++)
	{
		for (j = 0; j <=100; j++)
		{
			a[i][j] = -1;
		}
	}
	long long result = c(n,r);
	cout << result << endl;
	return 0;
}