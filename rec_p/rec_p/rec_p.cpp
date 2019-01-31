#include<iostream>
using namespace std;
int n,a[100],s[100];
void rec(int i)
{
	if (i == n)
	{  
		cout << "{";
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 1){
				cout << s[j]<<",";
				//if (j < n - 1)
					//cout << ",";
			}
		}
		cout << "}"<<endl;
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