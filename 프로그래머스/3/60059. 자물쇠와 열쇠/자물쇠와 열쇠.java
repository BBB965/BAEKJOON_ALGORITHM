class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = false;
        int N = key.length; int M = lock.length;
        
        int [][] findKey = new int [N + 2 * M][N + 2 * M];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                findKey[i + M][j + M] = key[i][j];
            }
        }
        
        int [][] rotate = lock;
        int cnt = 4;
        while (cnt-- > 0) {
            for (int i = 0; i < N + M; i++) {
                if (answer == true) break;
                for (int j = 0; j < N + M; j++) {
                    boolean flag = false;
                    for (int x = 0; x < M; x++) {
                        if (flag == true) break;
                        for (int y = 0; y < M; y++) {
                            if (findKey[i+x][j+y] + rotate[x][y] != 1) {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag == false) {
                        answer = true;
                        break;
                    }
                }
            }
            if (answer == true) break;
            else {
                rotate = rotateList(rotate);
            }
        }
        
        return answer;
    }
    
    static int[][] rotateList(int[][] arr) {
        int n = arr.length;
        int[][] rotate = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotate[i][j] = arr[n-1-j][i];
            }
        }

        return rotate;
    }
}