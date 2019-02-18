#include<iostream>
using namespace std;
int n,a[101],s[101];
void rec(int i)
{
	if (i == n)
	{  
		int isfirst = 1,sum=0,cnt=0;
		//cout << "{";
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 1)
			{
				cnt++;
				//sum = sum + s[j];
				/*if (isfirst)
					isfirst = 0;
				else
					cout << ",";*/
				//cout << s[j];
			}
		}
		if (cnt == 3)
		{
			for (int l = 0; l < n; l++)
			{
				if (a[l] == 1)
				{
					cout << s[l] << " ";
				}
			}
			cout << endl;
		}
		//cout<<sum <<endl;
		return;
	}
	a[i] = 0;
	rec(i + 1);
	a[i] = 1;
	rec(i + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	rec(0);
	return 0;
}