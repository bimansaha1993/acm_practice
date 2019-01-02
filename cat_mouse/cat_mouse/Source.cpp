#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int q, a, b, c, i;
	cin >> q;
	for (i = 0; i < q; i++)
	{
		cin >> a >> b >> c;
		if (abs(a - c) < abs(b - c))
			cout << "Cat A" << endl;
		else if (abs(b - c) < abs(a - c))
			cout << "Cat B" << endl;
		else if (abs(a-c)==abs(b-c))
			cout << "Mouse C" << endl;
	}
	return 0;
}