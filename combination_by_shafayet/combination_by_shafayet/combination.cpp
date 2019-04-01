#include<iostream>
using namespace std;

int n, r, arr[4], s[4],visit[4];

void combination(int i, int st)
{
	if (i == r)
	{
		for (int j = 0; j < r; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
		return;
	}
	for (int j = st; j < n; j++)
	{
		if (visit[j] == 0)
		{
			visit[j] = 1;
			arr[i] = s[j];
			combination(i + 1, j + 1);
			visit[j] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		visit[i] = 0;
	}
	cin >> r;
	combination(0, 0);
	return 0;
}