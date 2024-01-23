import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int S = Integer.parseInt(input[1]);
		int M = Integer.parseInt(input[2]);
		
		String [] nums = br.readLine().split(" ");
		
		boolean [][] vol = new boolean[1020][61];
		vol[S][0] = true;
		
		for (int i = 0; i < N; i++) {
		    int num = Integer.parseInt(nums[i]);
		    for (int j = 0; j <= M; j++) {
		        if (vol[j][i] == true) {
		            if (j - num >= 0) vol[j - num][i+1] = true;
		            if (j + num <= M) vol[j + num][i+1] = true;
		        }
		    }
		}
		
		int answer = -1;
		for (int i = M; i >= 0; i--) {
		    if (vol[i][N] == true) {
		        answer = i;
		        break;
		    }
		}
		System.out.println(answer);
	}
}