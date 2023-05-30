// map을 사용해서 재사용 -> 줄일수 있다
#include <iostream>
#include <map>
using namespace std;

map<long long, long long> fibo;
int m = 1000000007;
long long N;

long long fib(long long num) {
	if (num == 0) return 0;
	else if (num == 1) return 1;
	else if (num == 2) return 1;
	else if (fibo.count(num) > 0) return fibo[num];

	if (num % 2 == 0)
	{
		long long N1 = fib(num / 2);
		long long N2 = fib(num / 2 - 1);
		fibo[num] = ((N2 * 2 + N1)% m * (N1 % m)) % m;
		return fibo[num];
	}
	else
	{
		long long N1 = fib(num / 2 + 1);
		long long N2 = fib(num / 2);
		fibo[num] = ((N1 * N1) % m + (N2 * N2) % m) % m;
		return fibo[num];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cout << fib(N);
}