import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String [] input = br.readLine().split(" ");
	    int N = Integer.parseInt(input[0]);
	    int M = Integer.parseInt(input[1]);
	    
	    HashSet<String> listen = new HashSet<>();
	    HashSet<String> ans = new HashSet<>();
	    for(int i = 0; i < N; i++)
	    {
	        String name = br.readLine();
	        listen.add(name);
	    }
	    for (int i = 0; i < M; i++)
	    {
	        String name = br.readLine();
	        if (listen.contains(name))
	        {
	            ans.add(name);
	        }
	    }
	    System.out.println(ans.size());
	    ans.stream().sorted().forEach(System.out::println);
	}
}