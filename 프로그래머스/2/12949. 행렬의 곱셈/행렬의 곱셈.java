class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int A1 = arr1.length;
        int A2 = arr1[0].length;
        int A3 = arr2[0].length;
        int[][] answer = new int[A1][A3];
        
        for (int i = 0; i < A1; i++)
            for (int j = 0; j < A3; j++)
                for (int k = 0; k < A2; k++) 
                    answer[i][j] += arr1[i][k] * arr2[k][j];
        
        return answer;
    }
}