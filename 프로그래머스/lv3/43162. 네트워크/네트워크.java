import java.io.*;
import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] check = new boolean[n];
        
        for (int i = 0; i < n; i++)
        {
            if (check[i] == true) continue;
            Queue <Integer> q = new LinkedList<>();
            check[i] = true;
            q.add(i);
            while (!q.isEmpty())
            {
                int t = q.poll();
                for (int j = 0; j < n; j++)
                {
                    if (t == j || check[j] == true) continue;
                    if (computers[t][j] == 1)
                    {
                        check[j] = true;
                        q.add(j);
                    }
                }
            }
            answer++;
        }
        
        return answer;
    }
}