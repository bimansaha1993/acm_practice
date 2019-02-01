#include<iostream>
using namespace std;
int main()
{
	int n, k, c[26], i, energy = 100;
	cin >> n >> k;
	for (i = 0; i < n; i ++)
	{
		cin >> c[i];
	}
	for (i = 0; i < n; i = i + k)
	{
		if (c[(i + k) % n] == 1)
			energy = energy - 3;
		else if (c[(i + k) % n] == 0)
			energy = energy - 1;
		//if ((i + k) > n)
		//	break;
	}
	cout << energy << endl;
	return 0;
}