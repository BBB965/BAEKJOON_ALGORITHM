import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] input;
		ArrayList<pair> list = new ArrayList<>();
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++)
		{
		    input = br.readLine().split(" ");
		    pair pp = new pair(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
		    list.add(pp);
		}
		Collections.sort(list, (pair p1, pair p2) -> {
		    return p1.idx - p2.idx;
		});
		
		int answer = 0;
		int top = 0;
		pair last = list.get(0);
        
        for (int i = 1; i < list.size(); i++)
        {
            if (last.h <= list.get(i).h) 
            {
                answer += (list.get(i).idx - last.idx) * last.h;
                last = list.get(i);
                top = i;
            }
        }
        last = list.get(list.size() - 1);
        for (int i = list.size() - 1; i >= top; i--)
        {
            if (last.h <= list.get(i).h)
            {
                answer += (last.idx - list.get(i).idx) * last.h;
                last = list.get(i);
            }
        }

		answer += list.get(top).h;
		System.out.println(answer);
	}
	
	static class pair{
	    int idx, h;
	    
	    public pair(int idx, int h){
	        this.idx = idx;
	        this.h = h;
	    }
	}
}