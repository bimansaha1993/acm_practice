//#define _CRT
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int n=0, r, a[35];
char s[35];

void rec(int i)
{
	if (i == n)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 1)
			{
				cnt++;
			}
		}
		if (cnt == r)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[j] == 1)
				{
					cout << s[j];
				}
			}
			cout << endl;
		}
		return;
	}
	a[i] = 1;
	rec(i + 1);
	a[i] = 0;
	rec(i + 1);
}

int main()
{
	while (cin >> s >> r)
	{
		n = 0;
		for (int i = 0; s[i]; i++)
		{
			n++;
		}
		rec(0);
	}
	return 0;
}