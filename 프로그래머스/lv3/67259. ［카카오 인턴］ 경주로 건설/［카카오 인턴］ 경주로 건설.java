import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] board) {
        
        int N = board.length;
        
        int [] diry = {0,1,0,-1};
        int [] dirx = {1,0,-1,0};
        
        int [][][] cost = new int[N][N][4];
        
        Queue <int[]> q = new LinkedList<>();
        
        for (int i = 0; i < 4; i++)
        {
            int [] t = {0, 0, 100, i};
            cost[0][0][i] = 100;
            q.add(t);
        }
        
        while (!q.isEmpty())
        {
            int [] temp = q.poll();
            if (temp[0] == N-1 && temp[1] == N-1) continue;
            
            for (int i = 0; i < 4; i++)
            {
                int dy = temp[0] + diry[i];
                int dx = temp[1] + dirx[i];
                if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
                if (board[dy][dx] == 1) continue;
                int tCost = temp[2] + 100;
                if (temp[3] != i) tCost += 500;
                if (cost[dy][dx][i] != 0 && cost[dy][dx][i] < tCost) continue;
                cost[dy][dx][i] = tCost;
                
                int [] n = {dy,dx, tCost, i};
                q.add(n);
            }
        }
        
        int answer = (int)1e9;
        
        for (int i = 0; i < 4; i++) 
            if (cost[N-1][N-1][i] != 0 && answer > cost[N-1][N-1][i]) 
                answer = cost[N-1][N-1][i];
        
        return answer - 100;
    }
}