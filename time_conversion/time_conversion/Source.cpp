#include<iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int hr = (str[0] - '0') * 10 + (str[1] - '0');
	if (str[8] == 'P' && hr != 12)
	{
		hr += 12;
	}	
	else if (str[8] == 'A' && hr == 12){
		hr = 0;
	}	
	str[1] = (hr % 10 + '0');
	hr /= 10;
	str[0] = hr + '0';
	str.pop_back();
	str.pop_back();
	cout << str << endl;
	return 0;
}
