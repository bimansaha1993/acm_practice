//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

char arr[35][85];
int row, row_len[35],r,c;
int dx[8] = { 0, 0, -1, +1, -1, -1, +1, +1 };
int dy[8] = { -1, +1, 0, 0, -1, +1, -1, +1 };

void solve(int i, int j)
{
	arr[i][j] = '#';
	for (int e = 0; e < 8; e++)
	{
		int new_i = i + dx[e];
		int new_j = j + dy[e];
		if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c) //row,row_len[i]
			continue;
		if (arr[new_i][new_j] == '#' || arr[new_i][new_j] == 'X')
			continue;
		solve(new_i, new_j);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int test_case, pos_i, pos_j;
	cin >> test_case;
	string line;
	getchar();
	getline(cin, line);
	for (int t = 1; t < test_case;t++)
	{
		row = 0;
		while (getline(cin, line) && line[0] != '_')
		{
			row_len[row] = line.size();
			for (int i = 0; i<line.size(); i++)
			{
				arr[row][i] = line[i];
				if (line[i] == '*')
				{
					pos_i = row;
					pos_j = i;
					arr[row][i] = ' ';
				}
			}
			row++;
		}
	/*for (int t = 0; t < test_case;t++)
	{ 
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '*')
				{
					pos_i = i;
					pos_j = j;
				}
			}
		}*/
		solve(pos_i, pos_j);
		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<row_len[i]; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}