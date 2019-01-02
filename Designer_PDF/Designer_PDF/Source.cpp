#include<iostream>
using namespace std;
int main()
{
	int h[27], i,l=0, max = 0,w=1,result;
	for (i = 'a'; i<='z'; i++)
	{
		cin >> h[i];
	}
	char s[11];
	cin >> s;
	for (i = 0; s[i]; i++)
	{
		if (h[s[i]] > max){
			max = h[s[i]];
		}
		l++;
	}
	result = l*max*w;
	cout << result << endl;
	return 0;
}