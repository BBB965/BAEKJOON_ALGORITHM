import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Integer N = Integer.parseInt(br.readLine());
		int [] number = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	    boolean [][] idx = new boolean[N][N];
	    
	    for (int i = 0; i < N; i++) idx[i][i] = true;
	    for (int i = 0; i < N-1; i++) {
	        if (number[i] == number[i+1]) {
	            idx[i][i+1] = true;
	        }
	    }
	    
	    for (int i = 2; i < N; i++) {
	        for (int j = 0; j < N - i; j++) {
	            if (number[j] == number[j + i] && idx[j+1][j+i-1]) {
	                idx[j][j+i] = true;
	            }
	        }
	    }
	    
	    
	    Integer M = Integer.parseInt(br.readLine());
	    StringBuilder sb = new StringBuilder();
	    while (M-- > 0) {
	        String [] q = br.readLine().split(" ");
	        Integer S = Integer.parseInt(q[0]);
	        Integer E = Integer.parseInt(q[1]);
	        
	        if (idx[S-1][E-1]) sb.append("1\n");
	        else sb.append("0\n");
	    }
	    System.out.println(sb);
	}
}