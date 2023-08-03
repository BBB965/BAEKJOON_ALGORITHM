#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K;
queue <int> q;
int trace[100001];
int used[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	q.push(N);
	used[N] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == K) break;
		int next1 = now - 1;
		int next2 = now + 1;
		int next3 = now * 2;

		if (used[next1] == 0 && next1 >= 0 && next1 <= 100000)
		{
			used[next1] = used[now] + 1;
			q.push(next1);
			trace[next1] = now;
		}
		if (used[next2] == 0 && next2 >= 0 && next2 <= 100000)
		{
			used[next2] = used[now] + 1;
			q.push(next2);
			trace[next2] = now;
		}
		if (used[next3] == 0 && next3 >= 0 && next3 <= 100000)
		{
			used[next3] = used[now] + 1;
			q.push(next3);
			trace[next3] = now;
		}
	}
	vector<int> ans1;
	ans1.push_back(K);
	int found = K;
	for (int i = 0; i < used[K]-1; i++)
	{
		ans1.push_back(trace[found]);
		found = trace[found];
	}
	cout << used[K] -1 << "\n";
	for (int i = ans1.size() - 1; i >= 0; i--)
	{
		cout << ans1[i] << " ";
	}
	return 0;
}