#include<iostream>
using namespace std;

int n, arr[20], visit[20], mx;

int getval(int idx)
{
	bool has_left = false, has_right = false;
	int left_val, right_val;
	for (int i = idx - 1; i >= 0; i--)
	{
		if (visit[i] == 0)
		{
			has_left = true;
			left_val = arr[i];
			break;
		}
	}
	for (int i = idx + 1; i < n; i++)
	{
		if (visit[i] == 0)
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

int score_cnt(int i)
{
	if (i == n)
	{
		return 0;
	}
	int sum = 0, score = 0;
	for (int j = 0; j < n; j++)
	{
		if (visit[j] == 0)
		{
			int val = getval(j);
			visit[j] = 1;
			sum = score_cnt(i + 1) + val;
			if (sum > score)
				score = sum;
			visit[j] = 0;
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
			visit[i] = 0;
		}
		mx=score_cnt(0);
		cout << mx << endl;
	}
	return 0;
}