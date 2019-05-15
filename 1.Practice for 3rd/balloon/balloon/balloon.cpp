#include<iostream>
using namespace std;

int n, arr[12], taken[12];

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
	for (int j = idx + 1; j < n; j++)
	{
		if (taken[j] == 0)
		{
			has_right = true;
			right_val = arr[j];
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

int calculate_score(int i)
{
	if (i >= n)
	{
		return 0;
	}
	int sum = 0, score = 0;
	for (int j = 0; j < n; j++)
	{
		if (taken[j] == 0)
		{
			int val = getval(j);
			taken[j] = 1;
			sum = calculate_score(i + 1) + val;
			if (sum > score)
				score = sum;
			taken[j] = 0;
		}
	}
	return score;
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			taken[i] = 0;
		}
		int ans = calculate_score(0);
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}