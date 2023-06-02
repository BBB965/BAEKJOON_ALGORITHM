#include <iostream>
using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	int num = 666;
	int t = 0;
	while (true)
	{
		int temp = num;
		while (temp > 0)
		{
			if (temp % 1000 == 666)
			{
				t++;
				break;
			}
			else temp /= 10;
		}
		if (N == t) break;
		num++;
	}
	cout << num;
}