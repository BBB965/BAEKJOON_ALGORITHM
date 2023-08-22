import java.util.*;

class Solution {
    public int answer;
    public int[] visit;
    public int[][] dungeon;
    public int N;
    public int solution(int k, int[][] dungeons) {
        answer = -1;
        N = dungeons.length;
        visit = new int[N];
        dungeon = dungeons;
        dfs(k, 0);
        
        return answer;
    }
    
    public void dfs(int sum, int cnt)
    {
        answer = Math.max(answer, cnt);
        if (answer == N) return;
        for (int i = 0; i < N; i++)
        {
            if (visit[i] == 1) continue;
            if (dungeon[i][0] > sum) continue;
            visit[i] = 1;
            dfs(sum - dungeon[i][1], cnt + 1);
            visit[i] = 0;
        }
    }
}