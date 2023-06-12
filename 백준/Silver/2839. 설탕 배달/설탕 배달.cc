#include <iostream>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int ans = 0;
	int Five = 0, Three = 0;
	Five = N / 5;
	
	int T = N % 5;
	Three += T / 3;
	T = T % 3;
	while (T--)
	{
		if (Five <= 0)
		{
			ans = -1;
			break;
		}
		Five--;
		Three += 2;
	}
	if (ans != -1) cout << Five + Three;
	else cout << -1;
}