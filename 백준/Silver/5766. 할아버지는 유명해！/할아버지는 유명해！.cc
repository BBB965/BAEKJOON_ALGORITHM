#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ranking;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0) return 0;
		
		map <int, int> m;

		for (int w = 0; w < N; w++)
		{
			for (int p = 0; p < M; p++)
			{
				cin >> ranking;
				if (m.find(ranking) != m.end()) m[ranking]++;
				else m.insert({ ranking,1 });
			}
		}
		vector <pair<int, int>> vect(m.begin(), m.end());
		sort(vect.begin(), vect.end(), cmp);

		int num = vect[1].second;
		for (int i = 1; i < vect.size(); i++)
			if (vect[i].second == num) cout << vect[i].first << " ";
		cout << '\n';
	}
}