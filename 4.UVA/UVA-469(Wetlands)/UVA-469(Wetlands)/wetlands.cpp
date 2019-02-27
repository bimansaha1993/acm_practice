#include <bits/stdc++.h>
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
using namespace std;

int n,m,cnt;
char arr[101][101],cpy_arr[101][101];
int dx[8] = { 0, 0, -1, +1, -1, -1, +1, +1 };
int dy[8] = { -1, +1, 0, 0, -1, +1, -1, +1 };

void dfs(int i, int j)
{
	cpy_arr[i][j] = 'c';
	cnt++;
	for (int e = 0; e < 8; e++)
	{
		int new_i = i + dx[e];
		int new_j = j + dy[e];
		if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m)
			continue;
		if (cpy_arr[new_i][new_j] == 'c' || cpy_arr[new_i][new_j] == 'L')
			continue;

		dfs(new_i, new_j);

	}
}

int main()
{
    //freopen("input.txt", "r", stdin);
	int test;
	//char line[101];
	string line;
	cin >> test;
	getchar();
	getline(cin, line);

	for (int t = 1; t <= test;t++)
	{
        if(t!=1)
            cout << endl;
        n = 0;
		for (int i = 0; getline(cin, line) ; i++)
		{
			if(line[0] == '\0')
			{
			    break;
			}
			else if(line[0] >= '0' && line[0] <= '9')
            {
                int r = 0, c = 0, j = 0;
                while(line[j] >= '0' && line[j] <= '9')
                {
                    r = r*10 + (line[j] - '0');
                    j++;
                }
                j++;
                while(line[j] >= '0' && line[j] <= '9')
                {
                    c = c*10 + (line[j] - '0');
                    j++;
                }

                cnt = 0;
                for(int l=0;l<n;l++)
                {
                    for(int k =0;k<m;k++)
                    {
                        cpy_arr[l][k]=arr[l][k];
                    }
                }
                dfs(r-1, c-1);
                cout << cnt << endl;
            }
            else
            {
                int j = 0;
                while(line[j]!='\0')
                {
                    arr[i][j] = line[j];
                    j++;
                }
                m = j;
                n++;
            }
		}
	}
	return 0;
}
