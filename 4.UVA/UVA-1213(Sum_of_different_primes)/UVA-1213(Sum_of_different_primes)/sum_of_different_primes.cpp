#include<iostream>
using namespace std;

int n, k, number[200],j;

void prime_number()
{
	int first = 2; 
	j = 0;
	while (first <= n)
	{
		int flag = 0;
		for (int i = 2; i <= first / 2; i++)
		{
			if (first%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			number[j] = first;
			j++;
		}
		first++;
	}
}

void find_set()
{
	int sum = 0,n_cnt=0,set_cnt=0;
	for (int i = 0; i < j; i++)
	{
		sum = sum + number[i];
		n_cnt++;
		if (sum == n && n_cnt == k)
		{
			set_cnt++;
			break;
		}
	}
}

int main()
{
	while (true)
	{
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;
		prime_number();
		find_set();
		for (int l = 0; l < j; l++)
		{
			cout << number[l] << " ";
		}
		cout << endl;
	}
	return 0;
}