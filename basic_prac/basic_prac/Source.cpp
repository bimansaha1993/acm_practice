#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int a[100][100],i, j, n,sum1=0,sum2=0,dif;
	cin >> n;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i==j)
				sum1 += a[i][j];
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if ((i + j) == (n - 1))
				sum2 += a[i][j];
		}
	}
	dif = sum1 - sum2;
	if (dif < 0)
		dif = dif*(-1);
	cout << sum1 << " " << sum2 << endl;
	cout << dif;
	return 0;
}
////////////////  triplets  //////////////////////
/*int compareTriplets(int c[], int d[]){
	int ac=0, bc=0,j;
	for (j = 0; j < 3; j++){
		if (c[j] > d[j]){
			ac = ac + 1;
		}
		else if (c[j] < d[j]){
			bc = bc + 1;
		}
		else{
			ac = ac + 0;
			bc = bc + 0;
		}
	}
	return ac, ac;
}

int main(){
	int a[100], b[100], i,ac,bc;
	for (i = 0; i < 3; i++){
		cin >> a[i];
	}
	for (i = 0; i < 3; i++){
		cin >> b[i];
	}
	
	for (i = 0; i < 3; i++){
		int compareTriplets(int a,int b);
		/*if (a[i] > b[i]){
			ac = ac + 1;
		}
		else if (a[i] < b[i]){
			bc = bc + 1;
		}
		else{
			ac = ac + 0;
			bc = bc + 0;
		}//
	}
	cout << a << " " << b<< " ";
	return 0;
}*/

//////////////////////     sumarray     //////////////////
/*int simpleArraySum(int m,int b[]){
	int result = 0,j;
	for (j = 0; j < m; j++){
		result += b[j];

	}return result;
}

int main() {
	int a[1001],n,i,sum;
	cin >> n;
	int sum=0;
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	for (i = 0; i < n; i++){
		sum += a[i];
		//sum = simpleArraySum(n, a);
	}
	cout << sum;
	return 0;
}*/




