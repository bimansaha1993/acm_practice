#include<iostream>
using namespace std;

int n, arr[100], visit[100], score, mx, cpy_arr[100];

void calculate_score(int i)
{
	if (i == 0)
	{
		score = score+arr[i + 1];
	}
	if (i == n-1)
	{
		score = score+arr[n - 2];
	}
	if (i == n)
	{
		score = score+arr[i];
	}
	score = score+(arr[i - 1] * arr[i + 1]);
	calculate_score(i + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		visit[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		calculate_score(i);
	}
	cout << mx << endl;
	return 0;
}