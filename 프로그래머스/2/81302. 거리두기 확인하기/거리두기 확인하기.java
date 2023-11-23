import java.util.*;

class Solution {
    
    public int[] solution(String[][] places) {
        
        int [] answer = new int [places.length];
        int[][] dir = {
            {0, -1},
            {1, 0},
            {0, 1},
            {-1, 0}
        };
        
        for (int p = 0; p < places.length; p++) {
            String [] place = places[p];
            
            int flag = 1;
            for (int i = 0; i < 5; i++) {
                if (flag == 0) break;
                for (int j = 0; j < 5; j++) {
                    if (place[i].charAt(j) != 'P') continue;
                    if (flag == 0) break;
                    for (int k = 0; k < 4; k++) {
                        if (i + dir[k][0] < 0 || i + dir[k][0] >= 5 || j + dir[k][1] < 0 || j + dir[k][1] >= 5) {
                            continue;
                        }
                        if (place[i + dir[k][0]].charAt(j + dir[k][1]) == 'X') {
                            continue;
                        }
                        if (place[i + dir[k][0]].charAt(j + dir[k][1]) == 'P') {
                            flag = 0;
                            break;
                        }
                        else {
                            int x = i + dir[k][0];
                            int y = j + dir[k][1];
                            for (int t = 0; t < 4; t++) {
                                if (x + dir[t][0] < 0 || x + dir[t][0] >= 5 || y + dir[t][1] < 0 || y + dir[t][1] >= 5) {
                                    continue;
                                }
                                if (x + dir[t][0] == i && y + dir[t][1] == j)
                                {
                                    continue;
                                }
                                if (place[x + dir[t][0]].charAt(y + dir[t][1]) == 'P') {
                                    flag = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            
            answer[p] = flag;
        }
        
        return answer;
    }
}