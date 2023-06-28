#include <iostream>
using namespace std;

int custom, A, B,pizzaA[1001], pizzaB[1001];
int pieceA[2000001] = { 0, };
int pieceB[2000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> custom;
	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> pizzaA[i];
	for (int i = 0; i < B; i++)
		cin >> pizzaB[i];
	
	for (int i = 0; i < A; i++)
	{
		int temp = pizzaA[i];
		pieceA[temp]++;
		for (int j = 1; j < A-1; j++)
		{
			temp += pizzaA[(i + j) % A];
			pieceA[temp]++;
		}
		if (i == 0)
		{
			temp += pizzaA[A - 1];
			pieceA[temp]++;
		}
	}

	for (int i = 0; i < B; i++)
	{
		int temp = pizzaB[i];
		pieceB[temp]++;
		for (int j = 1; j < B-1; j++)
		{
			temp += pizzaB[(i + j) % B];
			pieceB[temp]++;
		}
		if (i == 0)
		{
			temp += pizzaB[B-1];
			pieceB[temp]++;
		}
	}
	int cnt = 0;
	cnt += pieceA[custom] + pieceB[custom];
	for (int i = 1; i < custom; i++)
		cnt += (pieceA[i] * pieceB[custom - i]);
	cout << cnt;
}