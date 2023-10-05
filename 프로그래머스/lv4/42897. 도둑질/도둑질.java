class Solution {
    public int solution(int[] money) {
        
        int N = money.length;
        int[][] dp = new int[2][N];
        
        dp[0][0] = money[0];
        dp[0][1] = money[1] > money[0] ? money[1] : money[0];
        dp[1][1] = money[1];
        
        for (int i = 2; i < N - 1; i++)
        {
            dp[0][i] = dp[0][i-1] >= dp[0][i-2] + money[i] ? dp[0][i-1] : dp[0][i-2] + money[i];
            dp[1][i] = dp[1][i-1] >= dp[1][i-2] + money[i] ? dp[1][i-1] : dp[1][i-2] + money[i];
        }
        
        dp[1][N-1] = dp[1][N-2] >= dp[1][N-3] + money[N-1] ? dp[1][N-2] : dp[1][N-3] + money[N-1];
        
        return Math.max(dp[1][N-1], dp[0][N-2]);
    }
}