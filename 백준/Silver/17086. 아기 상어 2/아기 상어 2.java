import java.io.*;
import java.util.*;

public class Main
{
    static int N;
    static int M;
    static int [][] sea;
    static int [] dy = {-1,-1,-1,0,1,1,1,0};
    static int [] dx = {-1,0,1,1,1,0,-1,-1};
    
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] input = br.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		M = Integer.parseInt(input[1]);
		
		sea = new int[N][M];
		
		for (int i = 0; i < N; i++)
		{
		    input = br.readLine().split(" ");
		    for (int j = 0; j < M; j++) sea[i][j] = Integer.parseInt(input[j]);
		}
		
		int answer = 0;
		
		for (int i = 0; i < N; i++)
		{
		    for (int j = 0; j < M; j++)
		    {
		        if (sea[i][j] == 1) continue;
		        answer = Math.max(answer, BFS(i,j));
		    }
		}
		System.out.println(answer);
	}
	
	static int BFS(int a, int b)
	{
	    int [][] visit = new int[N][M];
	    Queue <int[]> q = new LinkedList<>();
	    q.add(new int [] {a, b, 0});
	    
	    visit[a][b] = 1;
	    
	    while (!q.isEmpty())
	    {
	        int [] n = q.poll();
	        
	        for (int i = 0; i < 8; i++)
	        {
	            int ny = n[0] + dy[i];
	            int nx = n[1] + dx[i];
	            
	            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
	            if (visit[ny][nx] == 1) continue;
	            if (sea[ny][nx] == 1) return n[2] + 1;
	            visit[ny][nx] = 1;
	            q.add(new int[] {ny, nx, n[2] + 1});
	        }
	    }
	    return 0;
	}
}