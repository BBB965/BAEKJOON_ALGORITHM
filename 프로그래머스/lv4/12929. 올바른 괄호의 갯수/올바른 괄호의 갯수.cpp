#include <string>
#include <vector>
using namespace std;

int dp[15] = {0,};
int solution(int n) {
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i-j-1];
    
    return dp[n];
}