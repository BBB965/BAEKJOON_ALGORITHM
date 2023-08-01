import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int [] ranking = new int[10001];
		while (true)
		{
		    String [] input = br.readLine().split(" ");
		    int N = Integer.parseInt(input[0]);
		    int M = Integer.parseInt(input[1]);
		    if (N == 0 && M == 0) break;
		    
		    int max_num = 0;
		    for (int w = 0; w < N; w++)
		    {
		        input = br.readLine().split(" ");
		        for (int p = 0; p < M; p++)
		        {
		            int temp = Integer.parseInt(input[p]);
		            ranking[temp]++;
		            if (max_num < ranking[temp]) max_num = ranking[temp];
		        }
		    }
		    
		    int ans_num = 0;
		    for (int i = 1; i <= 10000; i++)
		        if (ranking[i] != max_num && ans_num < ranking[i]) ans_num = ranking[i];
		    
		    for (int i = 1; i <= 10000; i++)
		    {
		        if (ans_num == ranking[i]) System.out.print(i + " ");
		        ranking[i] = 0;
		    }
		    System.out.println();
		}
	}
}