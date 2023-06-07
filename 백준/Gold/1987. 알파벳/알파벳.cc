#include <iostream>
using namespace std;

int R, C, ans = 0;
char alpha[22][22];
bool check_a[27];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void board(int y, int x, int cnt)
{
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (check_a[alpha[ny][nx] - 'A']) continue;
		check_a[alpha[ny][nx] - 'A'] = 1;
		board(ny, nx, cnt + 1);
		check_a[alpha[ny][nx] - 'A'] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int y = 0; y < R; y++)
		cin >> alpha[y];
	check_a[alpha[0][0] - 'A'] = 1;
	board(0, 0, 1);
	cout << ans;
}