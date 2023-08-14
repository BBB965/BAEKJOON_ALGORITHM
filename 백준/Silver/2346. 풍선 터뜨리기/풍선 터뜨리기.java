import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		String [] input = br.readLine().split(" ");
		Deque<Balloon> dq = new ArrayDeque<>();
		
		for (int i = 1; i <= N; i++)
		{
		    dq.addLast(new Balloon(i, Integer.parseInt(input[i-1])));
		}
		
		
		while (dq.isEmpty() == false){
		    Balloon temp = dq.pollFirst();
		    System.out.print(temp.idx + " ");
		    if (dq.isEmpty()) break;
		    if (temp.num > 0) 
		    {
		        for (int i = 1; i < temp.num; i++){
		            dq.addLast(dq.pollFirst());
		        }
		    }
		    else
		    {
		        int tmp = -temp.num;
		        for (int i = 0; i < tmp; i++){
		            dq.addFirst(dq.pollLast());
		        }
		    }
		}
	}
	
	static class Balloon {
	    int idx;
	    int num;
	    
	    public Balloon(int idx, int num) {
	        this.idx = idx;
	        this.num = num;
	    }
	}
}