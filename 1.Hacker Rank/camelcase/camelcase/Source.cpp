#include<iostream>
using namespace std;
int main()
{
	char a[10000];
	cin >> a;
	int i, word = 1;
	for (i = 0; a[i]; i++)
	{
		if ((int)a[i] >= 65 && (int)a[i] <= 90)
		{
			word++;
		}
	}
	cout << word << endl;


	/////// ascii value  ///////
	/*char a[100];
	cin >> a;
	for (int i = 0; a[i]; i++)
	{
		int b = a[i];
		cout << b << endl;
		//cout<<(int)a[i]<<endl;
	}*/

	return 0;
}