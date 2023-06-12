#include <iostream>
#include <set>
using namespace std;

int N, M;
string name;
set <string> listen;
set <string> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		listen.insert(name);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> name;
		if (listen.find(name) != listen.end()) ans.insert(name);
	}
	cout << ans.size() << "\n";
	set<string> ::iterator iter;
	for (iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << "\n";
}