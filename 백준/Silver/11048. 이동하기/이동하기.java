import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);
		
		int [][] maze = new int[N+2][M+2];
		int [][] dp = new int[N+2][M+2];
		
		for (int i = 1; i <= N; i++) {
		    String[] num = br.readLine().split(" ");
		    for (int j = 1; j <= M; j++) {
		        maze[i][j] = Integer.parseInt(num[j-1]);
		    }
		}
		
		for (int i = 0; i <= N; i++) {
		    for (int j = 0; j <= M; j++) {
		        dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j] + maze[i+1][j]);
		        dp[i][j+1] = Math.max(dp[i][j+1], dp[i][j] + maze[i][j+1]);
		        dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j] + maze[i+1][j+1]);
		    }
		}
		
		System.out.println(dp[N][M]);
	}
}