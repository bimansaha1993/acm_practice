#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, pl, i, j, length = 6, cnt = 0, nu = 0,l = 0,u = 0,s=0;
	cin >> n;
	char a[102],sc[13];
	string spe_chr = "!@#$%^&*()-+";
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	a[i] = '\0';
	for (i = 0; i < spe_chr.length(); i++){
		sc[i] = spe_chr[i];
	}
	sc[i] = '\n';
	if( n < length){
		pl = length - n;
	}
	for (i = 0; a[i]; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')	
			l++;
		else if (a[i] >= 'A' && a[i] <= 'Z')
			u++;
		else if (a[i] >= '0' && a[i] <= '9')
			nu++;
		else
			for (j = 0; sc[j]; j++){
				if (a[i] == sc[j])
				s++;
			}
	}
	if (l == 0)
		cnt++;
	if (u == 0)
		cnt++;
	if (nu == 0)
		cnt++;
	if (s == 0)
		cnt++;
	if (cnt >= pl)
		cout << cnt << endl;
	else
		cout << pl;
	
	return 0;
}