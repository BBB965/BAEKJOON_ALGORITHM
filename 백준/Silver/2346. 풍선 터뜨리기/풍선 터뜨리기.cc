#include <iostream>
using namespace std;

int N, numbers[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> numbers[i];

	int idx = 1;
	int temp = numbers[idx];
	int cnt = N;

	while (cnt--)
	{
		cout << idx << ' ';
		if (cnt == 0) break;
		temp = numbers[idx];
		numbers[idx] = 0;
		while (temp != 0)
		{
			if (temp < 0)
			{
				idx--;
				if (idx <= 0) idx += N;
				if (numbers[idx] != 0)temp++;
			}
			else
			{
				idx++;
				if (idx > N) idx -= N;
				if (numbers[idx] != 0) temp--;
			}
		}
		while (idx <= 0)
			idx += N;
		while (idx > N)
			idx -= N;
	}
	return 0;
}