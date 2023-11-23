import java.io.*;
import java.util.*;

class Solution {
    public int solution(String s) {
        String answer = "";
        Map<String, Integer> map = new HashMap<>();
        
        map.put("zero", 0);
        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);
        map.put("four", 4);
        map.put("five", 5);
        map.put("six", 6);
        map.put("seven", 7);
        map.put("eight", 8);
        map.put("nine", 9);
        
        String number = "";
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c <= 'z' && c >= 'a') {
                number += c;
                if (map.containsKey(number) == true) {
                    answer += map.get(number);
                    number = "";
                }
            }
            else {
                answer += c;
            }
        }
        
        return Integer.parseInt(answer);
    }
}