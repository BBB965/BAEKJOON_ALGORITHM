import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int N = Integer.parseInt(br.readLine());
	    
	    int Five = 0;
	    int Three = 0;
	    boolean ans = false;
	    Five += N / 5;
	    N %= 5;
	    Three += N /3;
	    N %= 3;
	    
	    while (N > 0)
	    {
	        if (Five <= 0)
	        {
	            ans = true;
	            break;
	        }
	        Five--;
	        Three += 2;
	        N--;
	    }
	    if (ans) System.out.println(-1);
	    else System.out.println(Five + Three);
	}
}