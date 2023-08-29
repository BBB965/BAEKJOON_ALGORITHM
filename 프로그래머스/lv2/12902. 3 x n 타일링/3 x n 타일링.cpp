#include <string>
#include <vector>

using namespace std;
long long dp[5001] = {0,};
int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    
    for (int i = 4; i <= n; i++)
        dp[i] = (((dp[i-2] * 4) % 1000000007) - (dp[i-4] % 1000000007) + 1000000007) % 1000000007;
    
    return (int) dp[n];
}