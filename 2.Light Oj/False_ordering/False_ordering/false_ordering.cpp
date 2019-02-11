#include<iostream>
using namespace std;
int main()
{
	int test, n,a[1000],cnt_d[1000];
	//cin >> test;
	//for (int t = 1; t <= test; t++)
	//{
		
		//cin >> n;
		for (int k = 1; k <= 1000; k++)
		{
			int j = 1, cnt = 0;
			for (int i = 1; i <= k; i++)
			{
				if (k%i == 0)
				{
					//a[j] = i;
					cnt++;
				}
			}
			cnt_d[k] = cnt;
			a[j] = k;
			j++;
			cout << "for number " << k << ": ";
			for (int l = 0; l < j; l++)
			{
				cout << a[l] << " ";
			}
			cout << endl;
			cout << cnt << endl;
		}	
	//}
	return 0;
}