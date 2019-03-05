#include<iostream>
using namespace std;

int dx[4] = { 0, 0, +1, -1 };
int dy[4] = { +1, -1, 0, 0 };
int r, c,l=0;
char arr[101][101],cha[27];

void rank_language(int i,int j)
{
	arr[i][j] = '0';
	for (int k = 0; k < 4; k++)
	{
		int new_i = i + dx[k];
		int new_j = j + dy[k];
		if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= 0)
			continue;
		if (arr[new_i][new_j] = '0' || arr[new_i][new_j] != cha[l])
			continue;
		rank_language(new_i, new_j);
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> arr[i][j];
			}
		}
	}
	int cnt = 0, cnt_c[26];
	for (int i = 0; i < 26; i++)
	{
		cha[i] = '0';
		cnt_c[i] = 0;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j]!=0)
			{
				cha[l] = arr[i][j];
				rank_language(i, j);
				cnt_c[l]=cnt++;
			}
		}
	}
	return 0;
}