#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int n=0, r, visit[35];
char a[35],s[35];

void rec(int i,int st)
{
	if (i == r)
	{
		for (int j = 0; j < r; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		return;
	}
	for (int j = st; j < n; j++)
	{
		if (visit[j] == 0)
		{
			visit[j] = 1;
			a[i] = s[j];
			rec(i + 1, j + 1);
			visit[j] = 0;
		}
	}
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
		for (int i = 0; i < 35; i++)
		{
			visit[i] = 0;
		}
		rec(0,0);
	}
	return 0;
}