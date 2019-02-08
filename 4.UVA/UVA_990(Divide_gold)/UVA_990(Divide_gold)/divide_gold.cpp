#include<iostream>
using namespace std;

int d[31], v[31], t, w, num_tre,cnt=0;

int divide_gold(int i, int cap)
{
	int profit1=0, profit2=0;
	if (i >= num_tre)
		return 0;
	if (cap > (3 * w * d[i]))
	{
		profit1 = v[i] + divide_gold(i + 1, (cap - (3 * w*d[i])));
	}
	profit2 = divide_gold(i + 1, cap);
	if (profit1 > profit2)
		return profit1;
	else
		return profit2;
}

int main()
{
	while (true)
	{
		cin >> t >> w;
		cin >> num_tre;
		for (int i = 0; i < num_tre; i++)
		{
			cin >> d[i] >> v[i];
		}
		int result = divide_gold(0, t);
		cout << result << endl;
		cout << cnt << endl;
	}
	return 0;
}