#include<iostream>
using namespace std;
int main()
{
	int m1, d1, y1, m2, d2, y2,fine;
	cin >> d1 >> m1 >> y1;
	cin >> d2 >> m2 >> y2;
	if (d2 < d1 && m2 == m1 && y2 == y1)
	{
		fine = 15 * (d1 - d2);
		cout << fine << endl;
	}
	else if (m2 < m1 && y2 == y1)
	{
		fine = 500 * (m1 - m2);
		cout << fine << endl;
	}
	else if (y2 < y1)
	{
		fine = 10000;
		cout << fine << endl;
	}
	else //if (y1 <= y2)
	{
		fine = 0;
		cout << fine << endl;
	}
	return 0;
}