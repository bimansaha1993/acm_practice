#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100000 //maximum node
vector<int>edges[MAX];
vector<int>cost[MAX]; //parallel vector to store costs;
int main()
{
	int N, E, i,size;
	cin >> N >> E;
	//scanf("%d%d", &N, &E);
	for (i = 1; i <= E; i++)
	{
		int x, y;
		cin >> x >> y;
		//scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
		//cost[x].push_back(1);
		//cost[y].push_back(1);
	}
	for (i = 1; i <= N; i++){
		size = edges[i].size();
		for (int j = 0; j < size; j++)
		{
			cout << edges[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}