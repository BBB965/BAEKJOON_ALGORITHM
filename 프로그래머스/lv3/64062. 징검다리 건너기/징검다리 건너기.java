class Solution {
    public int solution(int[] stones, int k) {
        int min = 1;
        int max = 200000000;
        int mid = 0;
        while(min <= max) {
            mid = (min + max) / 2;
            int seq = 0, maxseq = 0;
            
            for(int n: stones) {
                if(n <= mid) ++seq;
                else {
                    maxseq = Math.max(maxseq, seq);
                    seq = 0;
                }
            }
            maxseq = Math.max(maxseq, seq);
            
            if(maxseq >= k) max = mid -1;
            else min = mid + 1;
        }
        
        return min;
    }
}