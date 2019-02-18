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

int find_set()
{
	int set_cnt=0;
	for (int i = 0; i < j; i++)
	{
		int sum = 0,n_cnt=0;
		for (int l = i+1; l < j; l++)
		{
			for (int m = l + 1; m < j; m++)
			{
				sum = sum + number[l];
				n_cnt++;
				if (n_cnt == k || sum > n)
					break;
			}
		}
		if (sum == n)
		{
			set_cnt++;
		}
	}
	return set_cnt;
}

int main()
{
	while (true)
	{
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;
		prime_number();
		int ans = find_set();
		/*for (int l = 0; l < j; l++)
		{
			cout << number[l] << " ";
		}
		cout << endl;*/
	}
	return 0;
}