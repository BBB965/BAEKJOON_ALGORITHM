#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int cheeze[110][110] = { 0, };
int inside[110][110] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue <pair<int, int>> melt;

void find_in()
{
	queue<pair<int, int>> ii;
	ii.push({ 0,0 });
	while (!ii.empty())
	{
		pair<int, int> temp = ii.front();
		ii.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = temp.first + dy[i];
			int nx = temp.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (cheeze[ny][nx] == 1 || inside[ny][nx]) continue;
			inside[ny][nx] = 1;
			ii.push({ ny,nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> cheeze[y][x];

	int answer = 0;
	while (true)
	{
		memset(inside, 0, sizeof(inside));
		find_in();
		for (int y = 0; y < N;y++)
			for (int x = 0; x < M; x++)
			{
				if (!cheeze[y][x]) continue;
				int checking = 0;
				for (int i = 0; i < 4; i++)
					if (cheeze[y + dy[i]][x + dx[i]] == 0 && inside[y + dy[i]][x + dx[i]] == 1) checking++;
				if (checking >= 2) melt.push({ y,x });
			}

		if (melt.empty()) break;
		while (!melt.empty())
		{
			pair<int, int> temp = melt.front();
			melt.pop();
			cheeze[temp.first][temp.second] = 0;
		}
		answer++;
	}
	cout << answer;
}