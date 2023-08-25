import java.io.*;
import java.util.*;

class Solution {
    
    static int N;
    static int [][] color;
    static int [] dy = {1,0,-1,0};
    static int [] dx = {0,1,0,-1};
    static ArrayList<Info> list;
    static int [] parent;
    static int answer;
    
    static class Info {
        int a; 
        int b;
        int c;
    
        public Info(int a, int b, int c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    
    public static int findParent (int v) {
        if (v == parent[v]) return v;
        return parent[v] = findParent(parent[v]);
    }
    
    public static void union(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }
    
    public int solution(int[][] land, int height) {
        N = land.length;
        color = new int[N][N];
        answer = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N ; j++)
            {
                if (color[i][j] > 0) continue;
                Queue <int []> q = new LinkedList<>();
                cnt++;
                color[i][j] = cnt;
                q.add(new int[] {i, j});
                while (!q.isEmpty())
                {
                    int [] temp = q.poll();
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = temp[0] + dy[k];
                        int nx = temp[1] + dx[k];
                        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                        if (color[ny][nx] != 0) continue;
                        if (Math.abs(land[ny][nx] - land[temp[0]][temp[1]]) > height) continue;
                        color[ny][nx] = cnt;
                        q.add(new int[] {ny,nx});
                    }
                }
            }
        }
        list = new ArrayList<>();
        parent = new int[cnt + 1];
        
        if (cnt == 1) return 0;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if (color[i][j] == color[ny][nx]) continue;
                    
                    list.add(new Info(color[i][j], color[ny][nx], Math.abs(land[i][j] - land[ny][nx])));
                }
            }
        }
    
        
        Collections.sort(list, (o1, o2) -> {
            if (o1.c == o2.c){
                if (o1.a == o2.a) return o1.b - o2.b;
                else return o1.a - o2.a;
            }
            else return o1.c - o2.c;
        });
        
        for (int i = 1; i <= cnt; i++ ) parent[i] = i;
        
        int t = 1;
        for (Info n : list){
            if (findParent(n.a) != findParent(n.b)) {
                union(n.a, n.b);
                answer += n.c;
                
                if (++t == cnt) break;
            }
        }
        return answer;
    }
}