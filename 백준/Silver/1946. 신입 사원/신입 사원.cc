#include <iostream>
using namespace std;

int T, N, a, b;
int score[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			score[a] = b;
		}
		int ans = 1;
		int temp = score[1];
		for (int i = 2; i <= N; i++)
		{
			if (score[i] < temp)
			{
				ans++;
				temp = score[i];
			}
		}
		cout << ans << "\n";
	}
}