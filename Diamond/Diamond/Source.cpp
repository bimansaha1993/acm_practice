#include<iostream>
using namespace std;
int main()
{
	int n, i, j, k,l=1,m=1;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (k = l; k <(n/2+1); k++)
		{
			cout << "  ";
		}
		for (j = 1; j <= m; j++)
		{
			cout << "* ";
		}
		if (i < (n/2+1))
		{
			l++;
			m=m+2;
		}
		else if (i >= (n / 2 + 1))
		{
			l--;
			m=m-2;
		}
		cout << endl;
	}
	return 0;
}