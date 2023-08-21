import java.io.*;
import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        int N = phone_book.length;
        
        for (int i = 0; i < N - 1; i++)
        {
            if (answer == false) break;
            for (int j = i + 1; j < N; j++)
            { 
                if (answer == false) break;
                if (phone_book[i].length() > phone_book[j].length()) break;
                if (phone_book[j].startsWith(phone_book[i])) {
                    answer = false;
                    break;
                }
                else break;
            }
        }
        
        return answer;
    }
}