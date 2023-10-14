import java.util.HashMap;
import java.io.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        int N = discount.length;
        int M = want.length;
        
        HashMap<String, Integer> map = new HashMap<>();
        
        for (int j = 0; j < 10; j++) {
            if (map.containsKey(discount[j]) == true) {
                map.replace(discount[j], map.get(discount[j]) + 1);
            }
                
            else {
                map.put(discount[j], 1);
            }
        }
        
        
        for (int i = 9; i < N; i++)
        {
            if (i > 9) {
                map.replace(discount[i-10], map.get(discount[i-10]) - 1);
                
                if (map.containsKey(discount[i]) == true) {
                    map.replace(discount[i], map.get(discount[i]) + 1);
                }
                
                else {
                    map.put(discount[i], 1);
                }
            }
            
            Boolean flag = true;
            for (int j = 0; j < M; j++)
            {
                if (!map.containsKey(want[j]) || map.get(want[j]) != number[j]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag == true) {
                answer++;
            }
        }
        
        return answer;
    }
}