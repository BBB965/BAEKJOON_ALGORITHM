#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, a, b;
vector <pair<int, int>> score;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		score.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			score.push_back({ a,b });
		}
		sort(score.begin(), score.end());
		int ans = 1;
		int temp = score[0].second;
		for (int i = 1; i < N; i++)
		{
			if (score[i].second < temp)
			{
				ans++;
				temp = score[i].second;
			}
		}
		cout << ans << "\n";
	}
}