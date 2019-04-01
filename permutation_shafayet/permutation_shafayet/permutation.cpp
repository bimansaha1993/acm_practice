#include<iostream>
using namespace std;

int n, r, arr[7], s[7], visited[7];

void permutation(int i,int st)
{
	if (i == r)
	{
		for (int j = 0; j < r; j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
		return;
	}
	for (int j = st; j < n; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			arr[i] = s[j];
			permutation(i + 1,j+1);
			visited[j] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		visited[i] = 0;
	}
	cin >> r;
	permutation(0,0);
	return 0;
}