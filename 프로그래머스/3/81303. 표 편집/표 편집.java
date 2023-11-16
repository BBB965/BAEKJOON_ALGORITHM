import java.util.*;

class Solution {
    public Object solution(int n, int k, String[] commands) {
        var data = new char[n];
        for (var i = 0; i < n; i++) {
            data[i] = 'O';
        }

        int moves = 0;
        Stack<Integer> history = new Stack<Integer>();
        for (var cmd : commands) {
            var op = cmd.charAt(0);
            if (op == 'U') {
                var v = Integer.parseInt(cmd.substring(2));
                moves += -v;
            }
            else if (op == 'D') {
                var v = Integer.parseInt(cmd.substring(2));
                moves += v;
            }
            else {
                k = doMove(data, k, moves);
                moves = 0;
            }

            if (op == 'C') {
                k = clear(data, k, history);
            }
            else if (op == 'Z') {
                k = undo(data, k, history);
            }
        }

        return new String(data) + "";
    }

    public int doMove(char[] data, int k, int moves) {
        if (moves > 0) {
            while(moves > 0) {
                k++;
                if (data[k] == 'O') {
                    moves--;
                }
            }
        }
        else {
            while(moves < 0) {
                k--;
                if (data[k] == 'O') {
                    moves++;
                }
            }
        }
        return k;
    }

    public int clear(char[] data, int k, Stack<Integer> history) {
        data[k] = 'X';
        history.push(k);
        var t = k;
        while (k < data.length && data[k] == 'X') {
            k++;
        }
        if (k < data.length) {
            return k;
        }
        while (data[t] == 'X') {
            t--;
        }
        return t;
    }

    public int undo(char[] data, int k, Stack<Integer> history) {
        data[history.pop()] = 'O';
        return k;
    }
}

// import java.util.*;
// import java.io.*;

// class Solution {
//     public String solution(int n, int k, String[] cmd) {
//         boolean [] del = new boolean[n];
//         int length = n;
//         Stack <Integer> number = new Stack<>();

//         for (int i = 0; i < cmd.length; i++) {
//             if (cmd[i].equals("Z")) {
//                 if (number.size() > 0) {
//                     int id = number.peek();
//                     del[id] = false;
//                     length++;
//                 }
//             }
//             else if (cmd[i].equals("C")) {
//                 number.push(k);
//                 del[k] = true;
                
//                 if (length == k + 1) {
//                     while (del[k] == true) {
//                         k--;
//                     }
//                 }
//                 else {
//                     while (del[k] == true) {
//                         k++;
//                         if (k == n) k = 0;
//                     }
//                 }
//             }
//             else {
//                 String [] comm = cmd[i].split(" ");
//                 Integer cnt = Integer.parseInt(comm[1]);
//                 int p = comm[0] == "U" ? -1 : 1;
//                 while (cnt > 0) {                    
//                     if (del[k] == false) cnt--;
                    
//                     k += p;
//                     if (k == -1) k = n - 1;
//                     else if (k == n) k = 0;
//                 }
//             }
//         }
        
//         String answer = "";
        
//         for (int i = 0; i < n; i++) {
//             answer += del[i] == true ? "X" : "O";
//         }
        
//         return answer;
//     }
// }