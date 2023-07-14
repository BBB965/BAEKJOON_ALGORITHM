#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map <string, int> sales;
int N;
string title;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> title;
		sales[title]++;
	}
	vector <pair<string, int>> vect(sales.begin(), sales.end());
	sort(vect.begin(), vect.end(), cmp);
	cout << vect.front().first;
}