#define _CRT_SECURE_NO_WARNNINGS
#include<iostream>
using namespace std;
int main()
{
	long int a[20], b[20], c, i;
	cin >> c;
	for (i = 1; i <= c; i++)
	{
		cin >> a[i] >> b[i];
	//}
	//for (i = 1; i <= c; i++)
	//{
		if (a[i] < b[i])
			cout <<"<"<< endl;
		else if (a[i] > b[i])
			cout <<">"<< endl;
		else
			cout <<"="<<endl;
	}
	//cout << "hello world";
	return 0;
}
