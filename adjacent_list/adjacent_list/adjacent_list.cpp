#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100000 //maximum node
vector<int>edges[MAX];
int main()
{
	int N, E, i,size;
	cin >> N >> E;
	for (i = 1; i <= E; i++)
	{
		int x, y;
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for (i = 1; i <= N; i++){
		size = edges[i].size();
		cout << i << " -> ";
		for (int j = 0; j <size; j++)
		{
			cout << edges[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}