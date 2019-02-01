#include<iostream>
using namespace std;
int main()
{
	int t,n, i, j, height;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		height = 1;
		for (j = 1; j <= n; j++)
		{
			if (j % 2 != 0)
			{
				height = height * 2;
			}
			else if (j % 2 == 0)
			{
				height = height + 1;
			}
		}
		cout << height << endl;
	}
	return 0;
}