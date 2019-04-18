#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char from_road, char to_road, char temp_road)
{
	if (n == 1)
	{
		cout << "Disk 1 move from road " << from_road << " to " << to_road << endl;
		return;
	}
	tower_of_hanoi(n - 1, from_road, temp_road, to_road);
	cout << "Disk " << n << " move from road " << from_road << " to " << to_road << endl;
	tower_of_hanoi(n - 1, temp_road, to_road, from_road);
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
	}
	tower_of_hanoi(n, 'A', 'B', 'C');
	return 0;
}