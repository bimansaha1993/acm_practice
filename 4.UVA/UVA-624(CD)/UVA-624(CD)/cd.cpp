#include<iostream>
using namespace std;

#define mx 25
int tape_len, num_track, track_len[mx], ans, arr[mx],cnt;

int find_track_list(int i,int st,int sum)
{
	if (sum > tape_len)
		return 0;
	if (sum > ans)
	{
		ans = sum;
	}
	if (i > num_track)
		return 0;
	for (int j = st; j < num_track; j++)
	{
		arr[i] = track_len[j];
		sum = sum + track_len[j];
		find_track_list(i + 1, j + 1,sum);
		sum = sum - track_len[j];

	}
}

int main()
{
	while (true)
	{
		cin >> tape_len >> num_track;
		for (int i = 0; i < num_track; i++)
		{
			cin >> track_len[i];
			arr[i] = 0;
		}
		ans = 0;
		find_track_list(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}