import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		String [] input = br.readLine().split(" ");
		int [] miro = new int[N];
		int [] dp = new int[N];
		for (int i = 0; i < N; i++) {
		    miro[i] = Integer.parseInt(input[i]);
		    dp[i] = 100000000;
		}
		
		dp[0] = 0;
		
		for (int i = 0; i < N; i++) {
		    for (int j = 1; j <= miro[i]; j++) {
		        if (i + j >= N) continue;
		        dp[i+j] = Math.min(dp[i+j], dp[i] + 1);
		    }
		}
		int answer = dp[N-1] == 100000000 ? -1 : dp[N-1];
		System.out.println(answer);
	}
}
