#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
int dp[100010] = {0,};

int solution(vector<int> sticker)
{
    int N = sticker.size();
    if (N == 1) return sticker[0];
    
    dp[0] = sticker[0]; //첫번째 스티커 사용한 경우
    dp[1] = dp[0]; // 두번째 스티커는 사용 못함 (그래서 자동 최대값 == 첫번째 스티커)
    for (int i = 2; i < N - 1; i++) // 마지막 스티커는 사용 못함
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    answer = max(answer, dp[N-2]);
    
    dp[0] = 0; // 두번째 스티커부터 사용할 경우
    dp[1] = sticker[1];
    for (int i = 2; i < N; i++)
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    answer = max(answer, dp[N-1]);
    
    return answer;
}