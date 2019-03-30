#include<iostream>
using namespace std;

int n, k, number[200],j,set_cnt,sum,visit[200];

void prime_number()
{
	int first = 2;
	j = 0;
	while (first <= n)
	{
		int flag = 0;
		for (int i = 2; i <= first / 2; i++)
		{
			if (first%i == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			number[j] = first;
			j++;
		}
		first++;
	}
}

void find_set(int st, int cnt)
{
    if(cnt==k)
    {
		if(sum==n)
		{
			set_cnt++;
		}
		return;
    }

	for(int l=st; l<j; l++)
	{
		sum=sum+number[l];
		find_set(l+1,cnt+1);
		sum=sum-number[l];
	}
}


// int find_set(int i, int cnt, int sum)
// {
//     if(cnt>=k)
//     {
//         return sum == n ? 1 : 0;
//     }

//     return find_set(i+1, cnt+1, sum + number[i]) + find_set(i+1, cnt, sum);
// }

int main()
{
	while (cin>>n>>k)
	{
		if (n == 0 && k == 0)
			break;
		prime_number();
		for(int i=0;i<200;i++)
		{
			visit[i]=0;
		}
        sum=0,set_cnt=0;
		find_set(0,0);
        cout<<set_cnt<<endl;
	}
    system("pause");
	return 0;
}
