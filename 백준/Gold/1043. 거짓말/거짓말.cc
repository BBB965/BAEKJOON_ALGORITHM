#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt_t, t, cnt_p, p,answer;
vector <int> truth;
vector <int> party[60];
int parent[60];

int find_p(int A) {
	if (A == parent[A]) return A;
	return parent[A] = find_p(parent[A]);
}

void UNI(int A, int B)
{
	A = find_p(A);
	B = find_p(B);
	parent[B] = A;
}

bool ppp(int A, int B)
{
	A = find_p(A);
	B = find_p(B);
	if (A == B) return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> cnt_t;
	for (int i = 0; i < cnt_t; i++)
	{
		cin >> t;
		truth.push_back(t);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> cnt_p;
		for (int j = 0; j < cnt_p; j++)
		{
			cin >> p;
			party[i].push_back(p);
		}
	}
	answer = M;

	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++)
	{
		int T1 = party[i][0];
		for (int j = 1; j < party[i].size(); j++)
		{
			int T2 = party[i][j];
			UNI(T1, T2);
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool can_go = 0;
		for (int j = 0; j < party[i].size(); j++)
		{
			if (can_go) break;
			int T1 = party[i][j];
			for (int x = 0; x < truth.size(); x++)
			{
				int T2 = truth[x];
				if (ppp(T1, T2)) {
					can_go = 1;
					break;
				}
			}
		}
		answer -= can_go;
	}
	cout << answer;
}