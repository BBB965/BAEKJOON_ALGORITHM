import java.util.LinkedList;
import java.util.Stack;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int N = s.length();
        int idx = 0;
        while (idx < N)
        {
            Stack <Character> Open = new Stack<>();
            Boolean flag = true;
            for (int i = 0; i < N; i++)
            {
                char t = s.charAt((idx + i) % N);
                if (t == '[' || t == '{' || t == '(') Open.push(t);
                else
                {
                    if (Open.size() == 0) 
                    {
                        flag = false;
                        break;
                    }
                    char b = Open.pop();
                    if (t == ']')
                        if (b != '[') Open.push(b);
                    
                    else if (t == '}')
                        if (b != '{') Open.push(b);
                    
                    else
                        if (b != '(') Open.push(b);
                }
            }
            idx++;
            if (Open.size() == 0 && flag == true) answer++;
        }
        
        return answer;
    }
}