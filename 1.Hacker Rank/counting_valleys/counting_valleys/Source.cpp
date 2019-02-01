#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, i, cnt = 0, v = 0;
	//char a[100000];
	string a;
	cin >> n;
	cin >> a;
	for (i = 0; i < n; i++)
	{
		//cin >> a[i];
		if (a[i] == 'U')
		{
			cnt += 1;
			if (cnt == 0)
				v += 1;
		}
		else if (a[i] == 'D')
			cnt -= 1;
	}
	cout << v;
	return 0;
}