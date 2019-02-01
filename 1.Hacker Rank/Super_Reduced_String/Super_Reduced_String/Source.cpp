#include<iostream>
#include<string>
using namespace std;
int main()
{
	char a[100], b[100];
	cin >> a;
	int i, len=0, j ,cnt,len1=0;
	for (i = 0; a[i]; i++)
	{
		len++;
	}
	while (len!=0)
	{
		j = 0;
		cnt = 0;
		for (i = 0; a[i]; i++)
		{
			if (a[i] == a[i + 1])
			{
				i++;
				cnt++;			
			}
			else
			{
				b[j] = a[i];
				j++;
			}
		}
		b[j] = '\0';
		len = 0;
		for (j = 0; b[j]; j++)
		{
			a[j] = b[j];
			len++;
		}
		a[j] = '\0';
		if (cnt == 0)
			break;
	}

	/*for (i = 0; a[i]; i++){

		if (a[i] == a[i + 1]){
			i++;
		}
		else{
			b[j] = a[i];
			j++;
		}
	}
	b[j] = '\0';
	for (j = 0; b[j]; j++)
		len++;*/

	if (len == 0)
		cout << "Empty String" << endl;
	else
		cout << a << endl;
	return 0;
}