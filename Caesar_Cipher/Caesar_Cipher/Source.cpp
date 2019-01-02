#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, k, i;
	char s[103];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	s[i] = '\0';
	cin >> k;
	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = 'a'+(s[i]-'a'+k)%26;
		}	
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = 'A' + (s[i] - 'A' + k) % 26;
		}	
		else
		{
			s[i] = s[i];
		}	
	}
	s[i] = '\0';
	cout << s << endl;
	return 0;
}