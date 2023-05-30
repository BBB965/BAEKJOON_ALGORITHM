#include <iostream>
#include <queue>
using namespace std;

int T, A, B;

int LL(int A)
{
	int d1 = A / 1000;
	A -= d1 * 1000;
	A *= 10;
	A += d1;
	return A;
}

int RR(int A)
{
	int d1 = A % 10;
	A /= 10;
 	A += d1 * 1000;
	return A;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> A >> B;
		queue <pair<string, int>> q;
		int num[10001] = { 0, };
		string ans = "";

		q.push({ "", A });

		while (true)
		{
			pair<string, int> temp = q.front();
			q.pop();
			
			int td = (temp.second * 2) % 10000;
			if (td == B) {
				ans = temp.first + "D";
				break;
			}
			if (num[td] == 0)
			{
				q.push({ temp.first + "D", td });
				num[td] = 1;
			}
			int ts = temp.second == 0 ? 9999 : temp.second - 1;
			if (ts == B) {
				ans = temp.first + "S";
				break;
			}
			if (num[ts] == 0) {
				q.push({ temp.first + "S", ts });
				num[ts] = 1;
			}
			int tl = LL(temp.second);
			int tr = RR(temp.second);
			if (tl == B) {
				ans = temp.first + "L";
				break;
			}
			if (num[tl] == 0)
			{
				q.push({ temp.first + "L" , tl});
				num[tl] = 1;
			}

			if (tr == B) {
				ans = temp.first + "R";
				break;
			}
			if (num[tr] == 0)
			{
				q.push({ temp.first + "R", tr });
				num[tr] = 1;
			}
		}
		cout << ans << "\n";
	}
}