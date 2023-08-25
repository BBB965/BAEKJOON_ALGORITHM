import java.io.*;
import java.util.*;

class Solution {
    static int[][] board = new int[110][110];
    static int[] dy = {1,0,-1,0};
    static int[] dx = {0,1,0,-1};
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        characterX *= 2;
        characterY *= 2;
        itemX *= 2;
        itemY *= 2;
        
        for (int i = 0; i < rectangle.length; i++)
        {
            int sx = rectangle[i][0] * 2;
            int sy = rectangle[i][1] * 2;
            int ex = rectangle[i][2] * 2;
            int ey = rectangle[i][3] * 2;
            
            for (int x = sx; x <= ex; x++)
            {
                if (board[x][sy] == 0) board[x][sy] = 1;
                if (board[x][ey] == 0) board[x][ey] = 1;
            }
            
            for (int y = sy; y<= ey; y++)
            {
                if (board[sx][y] == 0) board[sx][y] = 1;
                if (board[ex][y] == 0) board[ex][y] = 1;
            }
            
            for (int x = sx + 1; x < ex; x++)
                for (int y = sy + 1; y < ey; y++)
                    board[x][y] = 2;
        }
        
        int answer = 200000;
        boolean[][] checked = new boolean[110][110];
        Queue <int[]> q = new LinkedList<>();
        q.add(new int[] {characterX, characterY, 0});
        checked[characterX][characterY] = true;
        
        while (!q.isEmpty())
        {
            int [] temp = q.poll();
            if (temp[0] == itemX && temp[1] == itemY)
            {
                answer = Math.min(answer, temp[2]/2);
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = temp[0] + dx[i];
                int ny = temp[1] + dy[i];
                if (nx < 0 || ny <0 || nx >= 101 || ny >= 101) continue;
                if (checked[nx][ny] == true || board[nx][ny] != 1) continue;
                checked[nx][ny] = true;
                q.add(new int [] {nx, ny, temp[2] + 1});
            }
        }
        
        return answer;
    }
}