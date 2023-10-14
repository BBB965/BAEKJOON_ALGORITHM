import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Long> solution(int n, long left, long right) {
        long t;
        List <Long> answer = new ArrayList<>();
        for (long i = left; i <= right; i++) {
            t = i%n > i/n ? i%n : i/n;
            answer.add(t + 1);
        }
        
        return answer;
    }
}
