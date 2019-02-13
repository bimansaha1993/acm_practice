#include<iostream>
using namespace std;
int main()
{
	int number[1000],cnt_d[1000],j=0;
	for (int k = 1; k <= 1000; k++)
	{
		int cnt = 0;
		for (int i = 1; i <= k; i++)
		{
			if (k%i == 0)
			{
				cnt++;
			}
		}
		cnt_d[j] = cnt;
		number[j] = k;
		j++;
	}
	for (int l = 0; l < j; l++)
	{
		cout << "The number of divisor of the number " << number[l] << " is: " << cnt_d[l] << endl;
	}
	return 0;
}