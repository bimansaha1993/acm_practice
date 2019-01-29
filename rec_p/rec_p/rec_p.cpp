#include<iostream>
using namespace std;
int n,a[100];
void rec(int i)
{
	if (i == n)
	{  
		for (int j = 0; j < n; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		return;
	}
	a[i] = 0;
	rec(i + 1);
	a[i] = 1;
	rec(i + 1);
}

int main()
{
	cin >> n;
	rec(0);
	return 0;
}