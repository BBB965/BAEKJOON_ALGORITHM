import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Integer T = Integer.parseInt(br.readLine());
		
		int [][] dp = new int[10010][4];
		
		dp[1][1] = 1;
		dp[2][1] = 1;
		dp[2][2] = 1;
		dp[3][1] = 1;
		dp[3][2] = 1;
		dp[3][3] = 1; 
		
		for (int i = 4; i <= 10000; i++) {
		    dp[i][1] = dp[i-1][1];
		    dp[i][2] = dp[i-2][1] + dp[i-2][2];
		    dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
		}
		
		
		while (T-- > 0) {
		    Integer N = Integer.parseInt(br.readLine());
		    System.out.println(dp[N][1] + dp[N][2] + dp[N][3]);
		}
	}
}