#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int v, t, s;
	while (scanf_s("%d%d", &v, &t) != EOF)
	{
		if (-100 <= v && v <= 100 && 0 <= t && t <= 200){
			s = v*t * 2;
			cout << s << endl;
		}
		else
			cout << " " << endl;
	}
	return 0;
}

