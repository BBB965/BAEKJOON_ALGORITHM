#include <iostream>
#include <queue>
using namespace std;

int T, K, N;
char C;
// priority_queue로 문제 풀기 (min_heap / max_heap)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> K;
		priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_top; // minHeap
		priority_queue <pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq_bottom; // maxHeap
		bool checked[1000010] = { 0, }; // 삭제 index 표시 배열
		for (int i = 0; i < K; i++)
		{
			cin >> C >> N;

			if (C == 'I')
			{
				pq_top.push({ N,i });
				pq_bottom.push({ N,i });
				checked[i] = 1; // 방문 표시
			}
			else if (C == 'D' && N == -1)
			{
				while(!pq_top.empty() && !checked[pq_top.top().second]) pq_top.pop();
				// 삭제전에 우선순위 큐가 안비워져 있고, 이미 삭제된 숫자(index)라면 없애기
				// 만약 삭제되지 않은 숫자라면, 그 숫자가 가장 작은값
				if (!pq_top.empty())
				{
					checked[pq_top.top().second] = 0;
					pq_top.pop();
					// 없애기
				}
			}
			else if (C == 'D' && N == 1)
			{
				while (!pq_bottom.empty() && !checked[pq_bottom.top().second]) pq_bottom.pop();
				if (!pq_bottom.empty())
				{
					checked[pq_bottom.top().second] = 0;
					pq_bottom.pop();
				}
			}
		}
		// 삭제된 숫자인지 마지막으로 점검
		while (!pq_top.empty() && !checked[pq_top.top().second]) pq_top.pop();
		while (!pq_bottom.empty() && !checked[pq_bottom.top().second]) pq_bottom.pop();

		if (pq_bottom.empty() && pq_top.empty()) cout << "EMPTY" << "\n";
		else cout << pq_bottom.top().first << " " << pq_top.top().first << "\n";
	}
}