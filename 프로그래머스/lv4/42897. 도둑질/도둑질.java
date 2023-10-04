class Solution {
    public int solution(int[] money) {
        
        int N = money.length;
        int [] dp0 = new int[N];
        int [] dp1 = new int[N];
        
        dp0[0] = money[0];
        dp0[1] = money[1] > money[0] ? money[1] : money[0];
        
        dp1[1] = money[1];
        
        for (int i = 2; i < N - 1; i++)
        {
            dp0[i] = dp0[i-1] >= dp0[i-2] + money[i] ? dp0[i-1] : dp0[i-2] + money[i];
            dp1[i] = dp1[i-1] >= dp1[i-2] + money[i] ? dp1[i-1] : dp1[i-2] + money[i];
        }
        
        dp1[N-1] = dp1[N-2] >= dp1[N-3] + money[N-1] ? dp1[N-2] : dp1[N-3] + money[N-1];
        
        return Math.max(dp1[N-1], dp0[N-2]);
    }
}