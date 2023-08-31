import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] input = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int M = Integer.parseInt(input[1]);
		
		PriorityQueue <Long> pq = new PriorityQueue<>();
		
		input = br.readLine().split(" ");
	    for (int i = 0; i < N; i++)
	        pq.add(Long.parseLong(input[i]));
	   
	    while(M-- > 0)
	    {
	        long a = pq.poll();
	        long b = pq.poll();
	        pq.add(a+b);
	        pq.add(a+b);
	    }
	    
	    long answer = 0;
	    while (!pq.isEmpty())
	        answer += pq.poll();
	    
	    System.out.println(answer);
	}
}