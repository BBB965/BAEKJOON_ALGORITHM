#include <iostream>
#include <queue>
using namespace std;

struct info
{
	int yy;
	int xx;
	int dd;
};

int W, H;
char map[110][110];
bool checked[110][110][4];
int rr[110][110][4];
int sx = -1, sy = -1, ex = -1, ey = -1;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> W >> H;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 'C')
			{
				if (sx == -1)
				{
					sx = x; sy = y;
				}
				else
				{
					ex = x; ey = y;
				}
			}
		}
	
	queue <info> q;
	q.push({ sy,sx,-1 });
	for (int i = 0; i < 4; i++)
	{
		checked[sy][sx][i] = 1;
		rr[sy][sx][i] = 0;
	}

	while (!q.empty())
	{
		int y = q.front().yy;
		int x = q.front().xx;
		int d = q.front().dd;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (map[ny][nx] == '*') continue;
			if (d == i)
			{
				if (!checked[ny][nx][i])
				{
					rr[ny][nx][i] = rr[y][x][d];
					checked[ny][nx][i] = 1;
					q.push({ ny,nx,i });
				}
				else
				{
					if (rr[ny][nx][i] > rr[y][x][d])
					{
						rr[ny][nx][i] = rr[y][x][d];
						q.push({ ny,nx,i });
					}
				}
			}
			else
			{
				if (!checked[ny][nx][i])
				{
					rr[ny][nx][i] = rr[y][x][d] + 1;
					checked[ny][nx][i] = 1;
					q.push({ ny,nx,i });
				}
				else
				{
					if (rr[ny][nx][i] > rr[y][x][d] + 1)
					{
						rr[ny][nx][i] = rr[y][x][d] + 1;
						q.push({ ny,nx,i });
					}
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 4; i++)
		if (rr[ey][ex][i] < ans && checked[ey][ex][i]) ans = rr[ey][ex][i];
	
	cout << ans - 1;
}