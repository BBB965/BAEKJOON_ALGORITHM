class Solution {
    public int[] solution(int[] sequence, int k) {
        int N = sequence.length;
        int[] answer = {0,N};
        
        int sum = 0;
        int s = 0;
        int e = 0;
        
        for (int i = 0; i < N; i++) {
            sum += sequence[i];
            e = i;

            if (sum > k) {
                while (sum > k) {
                    sum -= sequence[s];
                    s++;
                }
            }
            
            if (sum == k) {
                if (answer[1] - answer[0] > e - s) {
                    answer[0] = s;
                    answer[1] = e;
                }
            }
        }
        
        return answer;
    }
}