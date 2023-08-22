import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int N = sizes.length;
        int W = 0;
        int H = 0;
        for (int i = 0; i < N; i++)
        {
            if (sizes[i][0] > sizes[i][1])
            {
                if (W < sizes[i][0]) W = sizes[i][0];
                if (H < sizes[i][1]) H = sizes[i][1];
            }
            else
            {
                if (W < sizes[i][1]) W = sizes[i][1];
                if (H < sizes[i][0]) H = sizes[i][0];
            }
        }
        
        answer = H * W;
        return answer;
    }
}