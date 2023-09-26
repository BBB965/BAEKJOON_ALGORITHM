import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] numbers = s.split(" ");
        List<Integer> num = new ArrayList<>();
        for (String n : numbers) num.add(Integer.parseInt(n));
        
        Collections.sort(num);
        answer += num.get(0);
        answer += " ";
        answer += num.get(num.size() - 1);
        return answer;
    }
}