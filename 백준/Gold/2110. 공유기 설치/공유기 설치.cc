#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, x, ans = 0;
vector <int> home;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		home.push_back(x);
	}
	sort(home.begin(), home.end());
	
	int ff = 1;
	int ee = home[N - 1] - home[0];
	while (ff <= ee)
	{
		int rr = 1;
		int mid = (ff + ee) / 2;
		int fir = home[0];

		for (int i = 1; i < N; i++)
		{
			if (home[i] - fir >= mid)
			{
				rr++;
				fir = home[i];
			}
		}
		if (rr >= C)
		{
			ans = max(ans, mid);
			ff = mid + 1;
		}
		else ee = mid - 1;
	}
	cout << ans;
}