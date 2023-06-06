#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K, u, v, w;
vector <pair<int,int>> node[20100];
int d[20100];

void shortcut()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,K });
	d[K] = 0;
	
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[cur].size(); i++)
		{
			int n = node[cur][i].first;
			int nc = node[cur][i].second;

			if (d[n] > cost + nc)
			{
				d[n] = cost + nc;
				pq.push({ -d[n], n });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		node[u].push_back({v,w});
	}
	for (int i = 1; i <= V; i++) d[i] = 2e9;
	shortcut();
	for (int i = 1; i <= V; i++)
	{
		if (d[i] == 2e9) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}
}