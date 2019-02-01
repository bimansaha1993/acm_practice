#define _CRT_SECURE_NO_WARNNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n, b, h, w, p, bed, i, j, cost,a_bed,bud;
	//cin >> n >> b >> h >> w;
	while ((scanf("%d %d %d %d", &n, &b, &h, &w)) != EOF){
		bud = b + 1;
		for (i = 1; i <= h; i++){
			cin >> p;
			a_bed = 0;
			for (j = 1; j <= w; j++){
				cin >> bed;
				if (bed > a_bed)
				{
					a_bed = bed;
				}
			}
			if (a_bed >= n){
				cost = p*n;
				if (cost < bud){
					bud = cost;
				}
			}
		}
		if (bud <= b)
			cout << bud << endl;
		else
			cout << "stay home" << endl;
	}
	return 0;
}