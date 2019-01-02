#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int temp = 0;

int pali(string a, int i, int j)
{
	if (i >= j)
		return 1;
	//if (i < j)
	//{
		if (a[i] != a[j])
			return 0;
		return pali(a, i + 1, j - 1);
	//}
	return 1;
}

int main()
{
	char a[100], b[100];
	int i, j, l = 0, m = 0, flag;
	cin >> a;
	for (i = 0; a[i]; i++)
	{
		l++;
	}
	j = l - 1;
	flag = pali(a,m,j);
	/*for (i = 0; i < l; i++)   ///////another process
	{
		if (i >= j)
			break;
		else if (a[i] != a[j])
			flag = 0;
		j--;
	}
	/*for (i = l-1; i >= 0; --i)   //////// different process
	{
		b[m] = a[i];
		m++;
	}
	b[m] = '\0';
	for (i = 0; i < l; i++)
	{
		if (a[i] != b[i])
			flag = 0;
	}*/
	if (flag == 1)
		cout << "palindrome" << endl;
	else
		cout << "not palindrome" << endl;
	return 0;
}
//////// recursive palindrome number ////////
/*int rev(int num)
{
	if (num == 0)
		return temp;
	else
		temp = temp * 10 + (num % 10);
	return rev(num / 10);
}
int main()
{
	int num, orginal, reverse = 0, reminder;
	cin >> num;
	orginal = num;
	/*while (num != 0)
	{
		reminder = num % 10;
		num = num / 10;
		reverse = reverse * 10 + reminder;
	}//
	reverse = rev(num);
	if (orginal == reverse)
		cout << "Palindrome" << endl;
	else
		cout << "not palindrome" << endl;
	return 0;
}*/