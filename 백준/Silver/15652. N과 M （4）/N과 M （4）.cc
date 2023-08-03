#include <iostream>
using namespace std;

int N, M;
int arr[10] = { 0, };

void dfs(int level)
{
	if (level == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (level > 0 && arr[level - 1] > i) continue;
		arr[level] = i;
		dfs(level + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	dfs(0);
	return 0;
}