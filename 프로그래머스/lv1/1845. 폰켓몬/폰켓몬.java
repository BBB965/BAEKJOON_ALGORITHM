import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Set <Integer> set = new HashSet<>();
        int N = nums.length;
        for (int i = 0; i < N; i++)
        {
            set.add(nums[i]);
        }
        if (N/2 > set.size()) answer = set.size();
        else answer = N/2;
        return answer;
    }
}