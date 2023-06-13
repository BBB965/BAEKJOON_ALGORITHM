#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X, a, b, c;
int road[1010][1010];
vector <pair<int,int>> leng[1010];

void djk(int s)
{
	priority_queue <pair<int, int>> PQ;
	road[s][s] = 0;
	PQ.push({ s,0});
	while (!PQ.empty())
	{
		int cost = -PQ.top().second;
		int cur = PQ.top().first;
		PQ.pop();
		for (int i = 0; i < leng[cur].size(); i++)
		{
			int next = leng[cur][i].first;
			int ncost = leng[cur][i].second;

			if (road[s][next] > cost + ncost)
			{
				road[s][next] = cost + ncost;
				PQ.push({ next, -road[s][next] });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			road[y][x] = 1e9;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		leng[a].push_back({ b,c });
	}
	int ans = 0;
	djk(X);
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		djk(i);
		ans = max(ans, road[i][X] + road[X][i]);
	}
	cout << ans;
}