#include <iostream>
using namespace std;

int N, K, I;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K >> I;
	int answer = 0;
	while (K != I)
	{
		answer++;
		if (K % 2) K = K / 2 + 1;
		else K /= 2;

		if (I % 2) I = I / 2 + 1;
		else I /= 2;
	}
	cout << answer;
	return 0;
}