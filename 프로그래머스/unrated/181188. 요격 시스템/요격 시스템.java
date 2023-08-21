import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        Arrays.sort(targets, (a,b) -> {
            return a[1] - b[1]; // 끝점으로 정렬시키기
        });
        
        int idx = 0;
        for (int i = 0; i < targets.length; i++)
        {
            if (idx <= targets[i][0]) // 겹쳐지는 범위가 없다면
            {
                answer++; // 하나 더 추가
                idx = targets[i][1]; // 범위 늘리기
            }
        }
        
        return answer;
    }
}