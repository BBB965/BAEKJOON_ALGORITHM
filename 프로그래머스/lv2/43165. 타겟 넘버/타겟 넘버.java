import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        Queue <int[]> q = new LinkedList<>();
        q.add(new int[] {numbers[0], 0});
        q.add(new int[] {-numbers[0], 0});
        
        int N = numbers.length;
        while (!q.isEmpty())
        {
            int [] temp = q.poll();
            if (temp[1] == N - 1)
            {
                if (temp[0] == target) answer++;
                continue;
            }
            temp[1]++;
            q.add(new int[] {temp[0] + numbers[temp[1]], temp[1]});
            q.add(new int[] {temp[0] - numbers[temp[1]], temp[1]});
        }
        return answer;
    }
}