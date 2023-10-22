#include <iostream>
using namespace std;
// 'SWEA 활주로 건설'과 같은 문제

int N, L;
int road[101][101];
int used_y[101][101] = {0,};
int used_x[101][101] = {0,};
int ans = 0;

int same_y(int y)
{
	for (int i = 0; i < N-1; i++)
		if (road[y][i] != road[y][i + 1]) return 0;
	return 1;
}

int same_x(int x)
{
	for (int i = 0; i < N - 1; i++)
		if (road[i][x] != road[i + 1][x]) return 0;
	return 1;
}

int diff_y(int y, int x, int k)
{
	for (int i = 1; i <= L; i++)
	{
		int a = x + i * k;
		if (a < 0 || a >= N) return 0;
		if ((road[y][x] - road[y][a]) != 1) return 0;
		if (used_y[y][a] == 1) return 0;
		
		used_y[y][a] = 1;
	}
	return 1;
}

int diff_x(int y, int x, int k)
{
	for (int i = 1; i <= L; i++)
	{
		int a = y + i * k;
		if (a < 0 || a >= N) return 0;
		if ((road[y][x] - road[a][x]) != 1) return 0;
		if (used_x[a][x] == 1) return 0;
		used_x[a][x] = 1;
	}
	return 1;
}

void fly()
{
	for (int y = 0; y < N; y++)
	{
		int flag = 2;
		if (same_y(y) == 1) ans += 1;
		else
		{
			for (int i = 0; i < N-1; i++)
			{
				if (road[y][i] == road[y][i + 1] + 1)
				{
					flag = diff_y(y, i, 1);
					if (flag == 0) break;
				}
				else if (abs(road[y][i] - road[y][i + 1]) > 1)
				{
					flag = 0; break;
				}
			}
			if (flag == 0) continue;
			for (int i = N - 1; i >= 1; i--)
			{
				if ((road[y][i] - road[y][i - 1]) == 1)
				{
					flag = diff_y(y, i, -1);
					if (flag == 0) break;
				}
				else if (abs(road[y][i] - road[y][i - 1]) > 1)
				{
					flag = 0; break;
				}
			}
		}
		if (flag == 1) ans++;
	}

	for (int x = 0; x < N; x++)
	{
		int flag = 2;
		if (same_x(x) == 1) ans += 1;
		else
		{
			for (int i = 0; i < N -1; i++)
			{
				if (road[i][x] - road[i + 1][x] == 1)
				{
					flag = diff_x(i, x, 1);
					if (flag == 0) break;
				}
				else if (abs(road[i][x] - road[i + 1][x]) > 1)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0) continue;
			for (int i = N - 1; i >= 1; i--)
			{
				if ((road[i][x] - road[i - 1][x]) == 1)
				{
					flag = diff_x(i, x, -1);
					if (flag == 0) break;
				}
				else if (abs(road[i][x] - road[i - 1][x]) > 1)
				{
					flag = 0; break;
				}
			}
		}
		if (flag == 1) ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> road[y][x];
	fly();
	cout << ans;
	return 0;
}