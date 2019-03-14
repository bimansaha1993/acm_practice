#include<iostream>
using namespace std;

int num_shop, num_road, num_dvd;
double arr[52][52];

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		cin >> num_shop >> num_road;
		for (int i = 0; i < num_shop; i++)
		{
			for (int j = 0; j < num_shop; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < num_road; i++)
		{
			int n1, n2;
			double cost;
			cin >> n1 >> n2 >> cost;
			arr[n1][n2] = cost;
			arr[n2][n1] = cost;
		}
		cin >> num_dvd;
		for(int i = 0; i < num_shop; i++)
		{
			for (int j = 0; j < num_shop; j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout << endl;
		}
	}
	return 0;
}