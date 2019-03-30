#include<iostream>
using namespace std;
int main()
{
	int number[1000],cnt_d[1000],j=1;
	for (int k = 1; k <= 1000; k++)
	{
		int cnt = 0;
		for (int i = 1; i <= k; i++)
		{
			if (k%i == 0)
			{
				cnt++;
			}
		}
		cnt_d[j] = cnt;
		number[j] = k;
		j++;
	}
    for(int i=1;i<=1000;i++)
    {
        for(int k=i;k<=1000;k++)
        {
            if(cnt_d[i]>cnt_d[k])
            {
                int temp=cnt_d[i];
                cnt_d[i]=cnt_d[k];
                cnt_d[k]=temp;

                temp=number[i];
                number[i]=number[k];
                number[k]=temp;
            }
            if(cnt_d[i]==cnt_d[k])
            {
                if(number[i]<number[k])
                {
                    int temp=number[i];
                    number[i]=number[k];
                    number[k]=temp;
                }
            }
        }
    }
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<t<<": "<<number[n]<<endl;
    }
    system("pause");
	return 0;
}
