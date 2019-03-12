#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

void calculate_length(int i)
{
	if (i == 2)
	{

	}
}

int main()
{
	int computer, coordinate_x[9], coordinate_y[9];
	double length[9],total_len=0;
	while (true)
	{
		cin >> computer;
		if (computer == 0)
			break;
		for (int i = 0; i < computer; i++)
		{
			cin >> coordinate_x[i] >> coordinate_y[i];
		}
		for (int i = 0; i < computer-1; i++)
		{
				length[i] =sqrt(((coordinate_x[i] - coordinate_x[i+1])*(coordinate_x[i] - coordinate_x[i+1])) + ((coordinate_y[i] - coordinate_y[i+1])*(coordinate_y[i] - coordinate_y[i+1]))) + 16;
				cout << length[i] << endl;
		}
		for (int i = 0; i < computer-1; i++)
		{
			total_len = total_len + length[i];
		}
		cout << total_len << endl;
	}
	return 0;
}