#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int N;
int start, finish;
int used[10001] = { 0, };
queue <int> pw;

bool prime(int num)
{
	int num_p = (int)sqrt(num);
	for (int i = 3; i <= num_p; i++)
		if (num % i == 0) return false;
	return true;
}

int password(int num, int i, int j)
{
	int a[4] = { 0, };
	int temp = num;
	for (int k = 0; k <4; k++)
	{
		a[k] = temp % 10;
		temp = (temp - a[k]) / 10;
	}
	a[i] = j;
	return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

void bfs()
{
	while (!pw.empty())
	{
		int now = pw.front();
		if (now == finish) break;
		pw.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 && j % 2 == 0) continue;
				if (i == 3 && j == 0) continue;

				int next = password(now, i, j);
				if (used[next] != 0) continue;
				if (prime(next) == false) continue;
				used[next] = used[now] + 1;
				if (next == finish) break;
				pw.push(next);
			}
		}
		if (used[finish] != 0) break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> finish;
		if (start == finish)
		{
			cout << 0 << "\n";
		}
		else
		{
			used[start] = 1;
			pw.push(start);
			bfs();
			if (used[finish] == 0) cout << "Impossible" << "\n";
			else cout << used[finish] - 1 << "\n";
		}
		memset(used, 0, sizeof(used));
		while (!pw.empty()) pw.pop();
	}
}