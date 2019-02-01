#include<iostream>
using namespace std;

int hurdleRace(int d, int h)
{
	int result = h - d;
	if (result < 0){
		result = 0;
		return result;
	}
	else
		return result;

}

int main()
{
	int n, k, a[101], i, dose, max = 0;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i]>max)
			max = a[i];
	}
	dose = hurdleRace(k,max); //max - k;
	/*if (dose < 0){
		dose = 0;
		cout << dose << endl;
	}
	else
		cout << dose << endl;*/
	cout << dose << endl;
	return 0;
}