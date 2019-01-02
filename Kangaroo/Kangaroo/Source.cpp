#include <iostream>
using namespace std;
int main()
{
	int x1, v1, x2, v2, result;
	cin >> x1 >> v1 >> x2 >> v2;
	if (x1 >= 0 && x1 <= 10000 && x2 >= 0 && x2 <= 10000 && v1 >= 1 && v1 <= 10000 && v2 >= 1 && v2 <= 10000){
		if (x2 > x1  &&  v2 > v1 || v2 == v1)
			cout << "NO" << endl;
		else
		{
			result = (x1 - x2) % (v2 - v1);
			if (result == 0)
				cout << "YES";
			else
				cout << "NO";
		}
	}
	return 0;
}