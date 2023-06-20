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
	        int [][] arr = new int[N][2];
	        for (int j = 0; j < N; j++)
	        {
	            String [] input = br.readLine().split(" ");
	            arr[j][0] = Integer.parseInt(input[0]);
	            arr[j][1] = Integer.parseInt(input[1]);
	        }
	        
	        Arrays.sort(arr, new Comparator<int []>() {
	            @Override
	            public int compare(int[] o1, int[] o2) {
	                return o1[0] - o2[0];
	            }
	        });
	        
	        int ans = 1;
	        int temp = arr[0][1];
	        for (int j = 1; j < N; j++)
	        {
	            if (arr[j][1] < temp)
	            {
	                ans++;
	                temp = arr[j][1];
	            }
	        }
	        System.out.println(ans);
	    }
	}
}