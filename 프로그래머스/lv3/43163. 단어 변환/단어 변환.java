import java.io.*;
import java.util.*;

class Solution {
    
    static String [] word;
    static int answer;
    static boolean[] check;
    
    public int solution(String begin, String target, String[] words) {
        answer = 100000;
        List<String> wordList = new ArrayList<>(Arrays.asList(words));
        if (wordList.contains(target) == false) return 0;
        word = words;
        check = new boolean[words.length];
        find(begin, 0, target);
        return answer;
    }
    
    static void find(String ww, int cnt, String goal)
    {
        if (ww.equals(goal)) 
        {
            answer = Math.min(answer, cnt);
            return;
        }
        
        for (int i = 0; i < word.length; i++)
        {
            if (check[i] == true) continue;
            int c = 0;
            for (int k = 0; k < ww.length(); k++)
                if (ww.charAt(k) != word[i].charAt(k)) c++;
            if (c == 1)
            {
                check[i] = true;
                find(word[i], cnt + 1, goal);
                check[i] = false;
            }
        }
    }
}