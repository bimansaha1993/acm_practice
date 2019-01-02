#include<iostream>
using namespace std;
int main()
{
	int n, k, q, m,i,j,a[100010],b[100010],l,x,z;
	cin >> n >> k >> q;
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		m = n - k%n;
		b[i]=a[(m+i)%n];
	}
	/*for (i = 0; i < k; i++) ///for time out {for(i=0;i<k%n;i++)}
	{
		l = 0;
		for (j = 0; j < n; j++)
		{
			m = (j + n - 1) % n;
			b[l] = a[m];
			l++;
			//cout << b[l] << " ";
		}
		for (z = 0; z < n; z++)
		{
			a[z] = b[z];
		}	
	}*/
	for (i = 0; i < q; i++)
	{
		cin >> x;
		cout << b[x]<<endl;
	}
	return 0;
}