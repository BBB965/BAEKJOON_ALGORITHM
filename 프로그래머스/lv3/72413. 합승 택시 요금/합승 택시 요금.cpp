#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long dp[201][201] = {0,};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = 1e9;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i != j) dp[i][j] = 1e9;
    
    for (int i = 0; i < fares.size(); i++)
    {
        dp[fares[i][0]][fares[i][1]] = fares[i][2];
        dp[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for (int y = 1; y <= n; y++)
        for (int x = 1; x<= n; x++)
            for (int z = 1; z<= n; z++)
                dp[z][x] = min(dp[z][x], dp[y][z] + dp[y][x]);
    
    for (int y = 1; y <= n; y++)
        answer = min(answer, dp[s][y] + dp[a][y] + dp[b][y]);
    
    return answer;
}