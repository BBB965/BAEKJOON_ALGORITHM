import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int T = Integer.parseInt(br.readLine());
	    
	    for (int i = 0; i < T; i++)
	    {
	        int N = Integer.parseInt(br.readLine());
	        int [] arr = new int[N+1];
	        for (int j = 0; j < N; j++)
	        {
	            String [] input = br.readLine().split(" ");
	            int a = Integer.parseInt(input[0]);
	            arr[a] = Integer.parseInt(input[1]);
	        }
	        
	        int ans = 1;
	        int temp = arr[1];
	        for (int j = 2; j <= N; j++)
	        {
	            if (arr[j] < temp)
	            {
	                ans++;
	                temp = arr[j];
	            }
	        }
	        System.out.println(ans);
	    }
	}
}