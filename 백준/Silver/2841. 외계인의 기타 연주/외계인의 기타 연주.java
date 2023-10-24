import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int P = Integer.parseInt(input[1]);
        
        Stack<Integer>[] stackArray = new Stack[7];
        for (int i = 1; i <= 6; i++) {
            stackArray[i] = new Stack<Integer>();
        }
        
        Integer answer = 0;
        
        for (int i = 0; i < N; i++) {
            String str[] = br.readLine().split(" ");
            int line = Integer.parseInt(str[0]);
            int ord = Integer.parseInt(str[1]);
            
            if (stackArray[line].isEmpty()) {
                stackArray[line].push(ord);
                answer++;
            } else {
                if (stackArray[line].peek() > ord) {
                    while (!stackArray[line].isEmpty() && stackArray[line].peek() > ord) {
                        answer++;
                        stackArray[line].pop();
                    }
                }
                if (stackArray[line].isEmpty() || stackArray[line].peek() < ord) {
                    stackArray[line].push(ord);
                    answer++;
                } else if (stackArray[line].peek() == ord) {
                    continue;
                }
            }
        }
        System.out.println(answer);
    }
}