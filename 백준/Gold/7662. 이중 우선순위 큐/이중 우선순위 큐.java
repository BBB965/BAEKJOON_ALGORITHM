import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int T = Integer.parseInt(br.readLine());
	    
	    for (int tc = 1; tc <= T; tc++)
	    {
	        int K = Integer.parseInt(br.readLine());
	        boolean[] bool = new boolean[1000100];
	        PriorityQueue<dual> pqLow = new PriorityQueue<>();
	        PriorityQueue<dual> pqHigh = new PriorityQueue<>(Collections.reverseOrder());
	        for (int i = 0; i < K; i++)
	        {
	            String [] input = br.readLine().split(" ");
	            char C = input[0].charAt(0);
	            int N = Integer.parseInt(input[1]);
	            
	            if (C == 'I')
	            {
	                pqLow.offer(new dual(N, i));
	                pqHigh.offer(new dual(N, i));
	                bool[i] = true;
	            }
	            
	            else
	            {
	                if (N == 1)
	                {
	                    while (!pqLow.isEmpty())
	                    {
	                        dual temp = pqLow.poll();
	                        if (temp == null) break;
	                        else if (bool[temp.i] == true)
	                        {
	                            bool[temp.i] = false;
	                            break;
	                        }
	                    }
	                }
	                else
	                {
	                    while (!pqHigh.isEmpty())
	                    {
	                        dual temp = pqHigh.poll();
	                        if (temp == null) break;
	                        else if (bool[temp.i] == true)
	                        {
	                            bool[temp.i] = false;
	                            break;
	                        }
	                    }
	                }
	            }
	        }
	        
	        while(!pqLow.isEmpty())
	        {
	            dual temp = pqLow.poll();
	            if (temp == null) break;
	            else if (bool[temp.i] == true)
	            {
	                pqLow.add(temp);
	                break;
	            }
	        }
	        while(!pqHigh.isEmpty())
	        {
	            dual temp = pqHigh.poll();
	            if (temp == null) break;
	            else if (bool[temp.i] == true)
	            {
	                pqHigh.add(temp);
	                break;
	            }
	        }
	        
	        if (pqLow.isEmpty() && pqHigh.isEmpty()) System.out.println("EMPTY");
	        else System.out.println(pqLow.poll().N + " " + pqHigh.poll().N);
	    }
	}
	
	static class dual implements Comparable<dual>{
	    int N;
	    int i;
	    
	    public dual(int N, int i) {
	        this.N = N;
	        this.i = i;
	    }
	    
	    @Override
	    public int compareTo(dual target) {
	        return this.N <= target.N ? 1 : -1;
	    }
	}
}