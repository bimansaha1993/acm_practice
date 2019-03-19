#include<iostream>
#include<math.h>
using namespace std;

int n,arr[17],visit[17],prime[35];

int is_prime(int p)
{
	/*int flag = 1;
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
		return 0;*/
    if(prime[p]==1)
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
				cout << arr[j];
				if(j<n-1)
                    cout<<" ";
			}
			cout << endl;
		//}
	}
	for (int j = 1; j <= n; j++)
	{
		if (visit[j] == 0)
		{
		    int p = arr[i - 1] + j;
			if (is_prime(p) == 0)
				continue;
            if(i==n-1)
            {
                p=arr[0]+j;
                if(is_prime(p)==0)
                    continue;
            }
			visit[j] = 1;
			arr[i] = j;
			circle_set(i + 1);
			visit[j] = 0;
		}
	}
}

int main()
{
    //   seive for prime ///////
    for(int i=0;i<35;i++)
    {
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<=sqrt(35);i++)
    {
        if(prime[i]==1)
        {
            for(int j=i+i;j<35;j=j+i)
            {
                prime[j]=0;
            }
        }
    }
    //////////

	int t = 1;
	while (cin >> n)
	{
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
