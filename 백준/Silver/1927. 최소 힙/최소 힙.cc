#include <iostream>
#include <queue>
using namespace std;

int N, num;
priority_queue <int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--)
	{
		cin >> num;
		if (num == 0)
		{
			if (pq.size() > 0)
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << 0 << '\n';

		}
		else if (num > 0) pq.push(num);
	}
	return 0;
}