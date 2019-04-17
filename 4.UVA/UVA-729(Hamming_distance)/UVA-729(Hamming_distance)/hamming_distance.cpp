#include<iostream>
using namespace std;

#define mx 20
int n, h, a[mx];

void hamming_dist(int i)
{
	if (i == n)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 1)
				cnt++;
		}
		if (cnt == h)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[j];
			}
			cout << endl;
		}
		return;
	}
	a[i] = 0;
	hamming_dist(i + 1);
	a[i] = 1;
	hamming_dist(i + 1);
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		if (t > 0)
			cout << endl;
		cin >> n >> h;
		for (int i = 0; i < n; i++)
		{
			a[i] = 0;
		}
		hamming_dist(0);
	}
}