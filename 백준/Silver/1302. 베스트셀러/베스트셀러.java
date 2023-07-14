import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		HashMap<String, Integer> map = new HashMap<>();
		int M = 1;
		for (int i = 0; i < N; i++)
		{
		    String title = br.readLine();
		    if (!map.containsKey(title)) map.put(title, 1);
		    else 
		    {
		        int T = map.get(title);
		        map.put(title, T + 1);
		        M = Math.max(M, T + 1);
		    }
		}
		List<String> keySet = new ArrayList<>(map.keySet());
		Collections.sort(keySet);
		for (String key : keySet){
		    if (map.get(key) == M){
		        System.out.println(key);
		        break;
		    }
		}
	}
}