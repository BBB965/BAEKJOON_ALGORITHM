class Solution {
    int MOD = 20170805;
    int y, x;
    public int solution(int m, int n, int[][] cityMap) {
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        
        for (int i = 1; i < m; i++)
        {
            if (cityMap[i][0] != 1) dp[i][0] += dp[i-1][0];
            else break;
        }
        for (int i = 1; i < n; i++)
        {
            if (cityMap[0][i] != 1) dp[0][i] += dp[0][i-1];
            else break;
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (cityMap[i][j] == 1) continue;
                else
                {
                    int yIdx = i-1;
                    while ( yIdx >= 0)
                    {
                        if (cityMap[yIdx][j] != 2) break;
                        else yIdx--;
                    }
                    
                    int xIdx = j-1;
                    while(xIdx >= 0)
                    {
                        if (cityMap[i][xIdx] != 2) break;
                        else xIdx--;
                    }

                    y = yIdx == -1 ? 0 : dp[yIdx][j];
                    x = xIdx == -1 ? 0 : dp[i][xIdx];
    
                    dp[i][j] = (y + x) % MOD;
                }
            }
        }
        return dp[m-1][n-1];
    }
}