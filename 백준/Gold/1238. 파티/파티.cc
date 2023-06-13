#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X, a, b, c;
int leng[1010];
int leng_back[1010];
vector <pair<int,int>> road[1010];
vector <pair<int, int>> road_back[1010];

void djk(bool dir)
{
	priority_queue <pair<int, int>> PQ;
	leng[X] = 0;
	leng_back[X] = 0;
	PQ.push({ X,0 });
	
	while (!PQ.empty())
	{
		int cost = -PQ.top().second;
		int cur = PQ.top().first;
		PQ.pop();
		if (dir)
		{
			for (int i = 0; i < road[cur].size(); i++)
			{
				int ncost = road[cur][i].second;
				int next = road[cur][i].first;
				if (leng[next] > cost + ncost)
				{
					leng[next] = cost + ncost;
					PQ.push({ next, -leng[next] });
				}
			}
		}
		else
		{
			for (int i = 0; i < road_back[cur].size(); i++)
			{
				int ncost = road_back[cur][i].second;
				int next = road_back[cur][i].first;
				if (leng_back[next] > cost + ncost)
				{
					leng_back[next] = cost + ncost;
					PQ.push({ next, -leng_back[next] });
				}
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
	{
		leng[y] = 1e9;
		leng_back[y] = 1e9;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road_back[b].push_back({ a,c });
	}
	int ans = 0;
	djk(0); djk(1);
	for (int i = 1; i <= N; i++)
		ans = max(ans, leng[i] + leng_back[i]);
	cout << ans;
}