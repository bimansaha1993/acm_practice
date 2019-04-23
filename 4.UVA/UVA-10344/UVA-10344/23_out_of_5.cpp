#include<iostream>
using namespace std;

#define size 5
int num[size], used[size];

int solve(int idx, int sum)
{
	if (idx == size && sum == 23)
		return 1;
	for (int j = 0; j < size; j++)
	{
		if (used[j] == 0)
		{
			used[j] = 1;
			if (solve(idx + 1, sum + num[j]))
				return 1;
			if (solve(idx + 1, sum - num[j]))
				return 1;
			if (solve(idx + 1, sum*num[j]))
				return 1;
			used[j] = 0;
		}
	}
	return 0;
}

int main()
{
	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			cin >> num[i];
			used[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			if (num[i] == 0)
				break;
		}
		for (int i = 0; i < size; i++)
		{
			used[i] = 1;
			if (solve(1, num[i]))
			{
				cout << "Possible" << endl;
				return 1;
			}
			used[i] = 0;
		}
		cout << "Impossible" << endl;
	}
	return 0;
}