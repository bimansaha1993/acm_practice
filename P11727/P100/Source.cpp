#define _CRT_SECURE_NO_WARNNINGS
#include<iostream>
using namespace std;
int main()
{
	long int a[10000], b[10000], c[10000], d, i;
	cin >> d;
	if (d < 20){
		for (i = 1; i <= d; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		for (i = 1; i <= d; i++){
			cout << "Case " << i << ": ";
			if ((a[i] > b[i] && a[i] < c[i]) || (a[i] > c[i] && a[i] < b[i]))
				cout << a[i] << endl;
			else if ((b[i] > a[i] && b[i] < c[i]) || (b[i] < a[i] && b[i] > c[i]))
				cout << b[i] << endl;
			else
				cout << c[i] << endl;
		}
	}
	return 0;
}

/*#include <cstdio>

using namespace std;

int main()
{
    int T, a, b, c;
    
    scanf("%d", &T);
    
    for (int round = 1; round <= T; ++round)
    {
        scanf("%d %d %d", &a, &b, &c);
        
        printf("Case %d: ", round);
        
		if ((a[i] > b[i] && a[i] < c[i]) || (a[i] > c[i] && a[i] < b[i]))
            printf("%d\n", a);
		else if ((b[i] > a[i] && b[i] < c[i]) || (b[i] < a[i] && b[i] > c[i]))
            printf("%d\n", b);
        else
            printf("%d\n", c);
        
        
    
    }

}*/