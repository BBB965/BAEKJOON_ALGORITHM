import java.io.*;
import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int N = name.length();
        int A = 0;
        int cur = N - 1;
        for (int i = 0; i < N; i++)
        {
            answer += Math.min((int) (name.charAt(i) - 'A'), (int) (26 - name.charAt(i) + 'A'));
            A = i + 1;
            while (A < N && name.charAt(A) == 'A') A++;
            
            cur = Math.min(cur, i * 2 + N - A);
            cur = Math.min(cur, (N - A) * 2 + i);
        }
        answer += cur;
             
        return answer;
    }
}