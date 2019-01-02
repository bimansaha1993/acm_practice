#include<iostream>
using namespace std;

/*int main()
{
	/*int n, a, b,i,c;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a >> b;
		c = a + b;
		cout <<"Case "<<i<<": "<< c<<endl;
	}*/
	/*int t, n, a, b, i,j;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		if (n > 10)
		{
			a = n - 10;
			b = n - a;
			cout << a << " " << b << endl;
		}
		else
		{
			b = n;
			a = 0;
			cout << a << " " << b << endl;
			/*for (j = 0; j < n; j++)
			{
				a = j;
				b = n-a;
				cout << a << " " << b << endl;
				//b--;
			}*/
		//}
	//}
	//return 0;
//}*/
int fact(int n)
{
	if (n>1)
		n = n*fact(n - 1);
	return n;
}
int main()
{
	int n, m,factorial=1,i;
	cin >> m;
	for (i = 1; i <= m; i++)
	{
		factorial = factorial*i;
	}
	cout << factorial << endl;
	while (1)
	{
		//printf("Enter a integer: ");
		cin >> n;
		//printf("Factorial of %d is: %d\n\n", n, fact(n));
		cout << fact(n);
	}
	return 0;
}