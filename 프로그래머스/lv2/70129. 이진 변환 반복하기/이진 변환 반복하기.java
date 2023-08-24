import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(String s) {
        int cnt = 0;
        int zero = 0;
        
        while (true)
        {
            if (s.length() == 1) break;
            int bin = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s.charAt(i) == '1') bin++;
                else zero++;
            }
            
            String temp = "";
            while (bin > 0)
            {
                int p = bin%2;
                temp = (char)(p + '0') + temp;
                bin /= 2;
            }
            s = temp;
            cnt++;
        }
        int [] answer = {cnt, zero};
        return answer;
    }
}