import java.io.*;
import java.util.*;

class Solution {
    public String solution(String s) {
        int [] check = new int[26];
        char [] string = s.toCharArray();
        
        for (int i = 0; i < s.length(); i++) check[string[i] - 'a']++;
        String answer = "";
        
        for (int i = 0; i < 26;i++)
            if (check[i] == 1) answer += (char)('a' + i);
        
        return answer;
    }
}