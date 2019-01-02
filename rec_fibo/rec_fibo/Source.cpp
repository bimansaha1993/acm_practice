#include<iostream>
using namespace std;

int fibo(int n)
{
	if (n < 2)
		return n;
	else
		return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
	int n, n1=0, n2=1, next, i;
	cin >> n;
	//cout << n1 << " " << n2 <<" ";
	//next = n1 + n2;
	//while (nexr<=n)
	for (i = 0; i < n;i++)
	{
		/*cout << n1 << " ";
		next = n1 + n2;
		n1 = n2;
		n2 = next;*/
		next = fibo(i);
		//if (next <= n)
		cout << next<<" ";
	}
	return 0;
}