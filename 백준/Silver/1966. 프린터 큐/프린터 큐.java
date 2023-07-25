import java.io.*;
import java.util.*;


public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++)
		{
		   String [] input = br.readLine().split(" ");
		   int M = Integer.parseInt(input[0]);
		   int N = Integer.parseInt(input[1]);
		   
		   Queue<pair> q = new LinkedList<>();
		   PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		   
		   String [] docList = br.readLine().split(" ");
		   for (int d = 0; d < M; d++)
		   {
		       int doc = Integer.parseInt(docList[d]);
		       pair pp = new pair(d,doc);
		       q.offer(pp);
		       pq.offer(doc);
		   }
		   int answer = 1;
		   while (!q.isEmpty())
		   {
		       pair temp = q.poll();
		       if (temp.doc == pq.peek())
		       {
		           pq.remove();
		           if (temp.d == N) break;
		           answer++;
		       }
		       else q.offer(temp);
		   }
		   System.out.println(answer);
		}
	}
	
	static class pair{
	    int d, doc;
	    
	    pair(int d, int doc) {
	        this.d = d;
	        this.doc = doc;
	    }
	}
}