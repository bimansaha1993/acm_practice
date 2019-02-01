#include<iostream>
using namespace std;
int main()
{
	int y,day=243,m=9,result;
	cin >> y;
	if (y > 1918)
	{
		if (y % 4 == 0)
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0)
				{
					day = day + 1;
					result = 256 - day;
					cout << result << ".0" << m << "." << y << endl;
				}
				else
				{
					result = 256 - day;
					cout << result << ".0" << m << "." << y << endl;
				}
			}
			else
			{
				day = day + 1;
				result = 256 - day;
				cout << result << ".0" << m << "." << y << endl;
			}
				
		}
		else
		{
			result = 256 - day;
			cout << result << ".0" << m << "." << y << endl;
		}	
	}
	
	else if (y < 1918 && y >= 1700)
	{
		if (y % 4 == 0)
		{
			day = day + 1;
			result = 256 - day;
			cout << result << ".0" << m << "." << y << endl;
		}
		else
		{
			result = 256 - day;
			cout << result << ".0" << m << "." << y << endl;
		}
	}
	
	else if (y == 1918)
	{
		day = day - 13;
		result = 256 - day;
		cout << result << ".0" << m << "." << y << endl;
	}
	return 0;
}