import java.util.*;

class Solution {
    public int solution(int[] food_times, long k) {
        int answer = 0;
        int N = food_times.length;
        List <Integer> food_list = new ArrayList<>();
        
        for (int i = 0; i < N; i++) {
            food_list.add(i);
        }
        
        Collections.sort(food_list, (o1,o2) -> food_times[o1] - food_times[o2]);
        
        int prev = 0;
        int idx = 0;
        for (int i : food_list) {
            long sub = food_times[i] - prev;
            if (sub > 0) {
                long temp = sub * N;
                if (temp <= k) {
                    k -= temp;
                    prev = food_times[i];
                } else {
                    k %= N;
                    Collections.sort(food_list.subList(idx, food_times.length));
                    return food_list.get(idx + (int) k) + 1;
                }
            }
            idx++;
            N--;
        }
        
        return -1;
    }
}