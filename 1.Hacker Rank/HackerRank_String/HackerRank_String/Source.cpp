#include<iostream>
using namespace std;
int main()
{
	int q, i, k, l=0, j;
	char h[11] = "hackerrank";
	char s[10000];
	cin >> q;
	for (i = 0; h[i]; i++)
	{
		l++;
	}
	//cout << l << endl;
	for (i = 0; i < q;i++)
	{
		cin >> s;
		j = 0;
		for (k = 0; s[k]; k++)
		{
			if (h[j] == s[k])
			{
				j++;
			}
		}
		if (j == l)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}