#include<iostream>
using namespace std;
int main()
{
	int n, i, s = 5, l = 0, cu = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		l = s / 2;
		s = l * 3;
		cu = cu + l;
	}
	cout << cu << endl;
	return 0;
}