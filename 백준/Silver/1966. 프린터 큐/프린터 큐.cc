#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, M, N, doc;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.first < b.first;
	}
}; 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> M >> N;
		priority_queue<int> pq;
		queue <pair<int, int>> q;

		for (int d = 0; d < M; d++)
		{
			cin >> doc;
			pq.push(doc);
			q.push({d,doc});
		}

		int ans = 1;
		while (!q.empty())
		{
			pair<int, int> temp = q.front();
			q.pop();

			if (temp.second == pq.top())
			{
				pq.pop();
				if (temp.first == N) break;
				ans++;
			}
			else q.push(temp);
		}
		cout << ans << '\n';
	}
}