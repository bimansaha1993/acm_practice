#include<iostream>
using namespace std;

///////// Insertion Sort ///////////////
/*int main()
{
	int n, a[100], i, j, temp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i <= n - 1; i++)
	{
		j = i;
		while (j > 0 && a[j] < a[j - 1])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
		
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}*/

//////////// Bubble Sort ////////////
/*int main()
{
	int n, a[100], i, j, temp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}*/

//////////// Selection Sort /////////////////
/*int main()
{
	int n, a[5], i, j, min_idx,temp;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			if (a[j] < a[min_idx])
			{
				min_idx = j;
			}
		}
		if (a[min_idx] < a[i])
		{
			temp = a[min_idx];
			a[min_idx] = a[i];
			a[i] = temp;
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}*/