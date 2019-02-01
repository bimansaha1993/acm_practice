#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	char ms[4] = "SOS";
	int cnt = 0, i;
	for (i = 0; s[i]; i++){
		if (s[i] != ms[i%3])
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}