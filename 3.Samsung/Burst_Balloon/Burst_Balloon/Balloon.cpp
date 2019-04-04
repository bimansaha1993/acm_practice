#include<iostream>
using namespace std;

int n, arr[20], visit[20], taken[20], id[20], mx;

int getval(int idx)
{
	bool has_left = false, has_right = false;
	int left_val, right_val;
	for (int i = idx - 1; i >= 0; i--)
	{
		if (taken[i] == 0)
		{
			has_left = true;
			left_val = arr[i];
			break;
		}
	}
	for (int i = idx + 1; i < n; i++)
	{
		if (taken[i] == 0)
		{
			has_right = true;
			right_val = arr[i];
			break;
		}
	}
	if (has_left && has_right)
		return left_val*right_val;
	if (has_left)
		return left_val;
	if (has_right)
		return right_val;
	return arr[idx];
}

void calculate_score(int i)
{
	if (i == n)
	{
		int sum = 0;
		for (int k = 0; k < n; k++)
		{
			taken[k] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			sum = sum + getval(id[j]);
			taken[id[j]] = 1;
		}
		if (sum > mx)
			mx = sum;
		return;

	}
	for (int j = 0; j < n; j++)
	{
		if (visit[j] == 0)
		{
			visit[j] = 1;
			id[i] = j;
			calculate_score(i + 1);
			visit[j] = 0;
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			visit[i]=0;
			id[i] = 0;
		}
		mx = 0;
		calculate_score(0);
		cout << mx << endl;
	}
	return 0;
}