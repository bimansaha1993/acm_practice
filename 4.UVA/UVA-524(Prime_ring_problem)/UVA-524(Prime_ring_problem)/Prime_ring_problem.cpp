#include<iostream>
#include<math.h>
using namespace std;

int n,arr[17],visit[17];

int is_prime(int p)
{
	int flag = 1;
	for (int i = 2; i <= sqrt(p); i++)
	{
		if (p%i == 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}

void circle_set(int i)
{
	if (i == n)
	{
		/*int prime = 1;
		for (int j = 0; j < n && prime==1; j++)
		{
			int p = arr[j%n] + arr[(j + 1)%n];
			prime = is_prime(p);
		}
		if (prime == 1)
		{*/
			for (int j = 0; j < n; j++)
			{
				cout << arr[j] << " ";
			}
			cout << endl;
		//}
	}
	for (int j = 1; j <= n; j++)
	{
		if (visit[j] == 0)
		{
			visit[j] = 1;
			arr[i] = j;
			//
			int p = arr[i - 1] + arr[i];
			if (is_prime(p) == 0)
				continue;
			//
			circle_set(i + 1);
			visit[j] = 0;
		}
	}
}

int main()
{
	int t = 1;
	while (true)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			visit[i] = 0;
		}
		arr[0] = 1;
		visit[1] = 1;
		cout << "Case " << t << ":" << endl;
		circle_set(1);
		t++;
	}
	return 0;
}