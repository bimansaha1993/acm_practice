#include<iostream>
using namespace std;

int binsearch(int a[], int low, int high, int x)
{
	//int mid;
	if (high < low)
		return -1;
	//if (high >= low)
	//{
		int mid = (low + high) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binsearch(a, low, mid - 1, x);
		
		return binsearch(a, mid + 1, high, x);
	//}
	//return -1;
}

int main()
{
	int a[50], n, i, x, low=0, high, result;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	high = n - 1;
	result = binsearch(a, low, high, x);
	/*while (low < high)
	{
		mid = (low + high) / 2;
		if (a[mid] == x)
		{
			cout << mid << endl;
			break;
		}
		else if (a[mid] > x)
			high = mid-1;
		else
			low = mid+1;
	}*/
	if (result != -1)
		cout << result;
	return 0;
}