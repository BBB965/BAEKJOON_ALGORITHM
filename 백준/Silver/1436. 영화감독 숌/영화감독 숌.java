import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    
	    int N = Integer.parseInt(br.readLine());
	    int num = 666;
	    int T = 0;
	    while (true) {
	        
	        int temp = num;
	        while (temp > 0) {
	            if (temp % 1000 == 666) {
	                T = T + 1;
	                break;
	            }
	            else {
	                temp /= 10;
	            }
	        }
	        if (T == N) {
	            break;
	        }
	        num++;
	    }
	    
		System.out.println(num);
	}
}