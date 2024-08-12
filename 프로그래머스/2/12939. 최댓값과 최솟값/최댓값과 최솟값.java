import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] numbers = s.split(" ");
        String minN = numbers[0];
        String maxN = numbers[0];
        
        for (String i : numbers)
        {
            minN = Integer.parseInt(minN) > Integer.parseInt(i) ? i : minN;
            maxN = Integer.parseInt(maxN) < Integer.parseInt(i) ? i : maxN;
        }
        
        answer += minN + " " + maxN;
        return answer;
    }
}