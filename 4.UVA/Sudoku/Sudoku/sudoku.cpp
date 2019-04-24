#include<iostream>
using namespace std;

#define n 9
int flag;
int arr[n][n];

int used_inrow(int row,int value)
{
	for (int c = 0; c < 9; c++)
	{
		if (arr[row][c] == value)
			return 1;
	}
	return 0;
}

int used_incolumn(int column,int value)
{
	for (int r = 0; r < 9; r++)
	{
		if (arr[r][column] == value)
			return 1;
	}
	return 0;
}

int used_inbox(int boxrow,int boxcolumn,int value)
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (arr[r + boxrow][c + boxcolumn] == value)
				return 1;
		}
	}
	return 0;
}

void solve_sudoku(int row,int column)
{
	if (row == 9 && column == 0)
	{
		flag = 1;
		return;
	}
	if (arr[row][column] != 0)
	{
		//move next
		if (column + 1 < 9)
			solve_sudoku(row, column + 1);
		else
			solve_sudoku(row + 1, 0);
	}
	else{
		for (int num = 1; num <= 9; num++)
		{
			if (!used_inrow(row, num) && !used_incolumn(column, num) && !used_inbox(row - row % 3, column - column % 3, num))
			{
				arr[row][column] = num;
				//move next
				if (column + 1 < 9)
					solve_sudoku(row, column + 1);
				else
					solve_sudoku(row + 1, 0);
				if (flag == 1)
					return;
				arr[row][column] = 0;
			}
		}
		return;
	}
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> arr[i][j];
			}
		}
		flag = 0;
		solve_sudoku(0, 0);
		cout << "Case " << t << ":" << endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}