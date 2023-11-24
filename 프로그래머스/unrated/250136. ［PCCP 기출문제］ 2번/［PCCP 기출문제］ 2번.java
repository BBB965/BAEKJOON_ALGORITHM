import java.util.*;

class Solution {
    public int solution(int[][] land) {
        int n = land.length;
        int m = land[0].length;
        int [][] dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};
        
        int[][] visited = new int[n][m];
        
        Queue <int[]> oil = new LinkedList<>();
        Map <Integer,Integer> idx = new HashMap<>();
        int id = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && visited[i][j] == 0 ) {
                    id++;
                    oil.add(new int[]{i,j});
                    visited[i][j] = id;
                    
                    int cnt = 1;
                    while (!oil.isEmpty()) {
                        int [] temp = oil.poll();
                        for (int k = 0; k < 4; k++) {
                            int nx = temp[0] + dir[k][0];
                            int ny = temp[1] + dir[k][1];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
                            if (land[nx][ny] == 0 || visited[nx][ny] > 0) continue;
                            visited[nx][ny] = id;
                            cnt++;
                            oil.add(new int[] {nx, ny});
                        }
                    }
                    idx.put(id, cnt);
                }
            }
        }
        int answer = 0;
        
        for (int j = 0; j < m; j++) {
            int maxOil = 0;
            boolean[] checked = new boolean[id+1];
            for (int i = 0; i < n; i++) {
                if (visited[i][j] != 0 && checked[visited[i][j]] == false) {
                    checked[visited[i][j]] = true;
                    maxOil += idx.get(visited[i][j]);
                }
            }
            answer = Math.max(answer, maxOil);
        }
        
        return answer;
    }
}