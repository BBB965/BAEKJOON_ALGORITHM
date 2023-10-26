import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input[] = br.readLine().split(" ");
		int N = Integer.parseInt(input[0]);
		int D = Integer.parseInt(input[1]);
		
		int [][] road = new int[D+1][D+1];
		
		for (int i = 0; i <= D; i++) {
		    for (int j = i; j <= D; j++) {
		        road[i][j] = j-i;
		    }
		}
		
		for (int i = 0; i < N; i++) {
		    String[] info = br.readLine().split(" ");
		    int S = Integer.parseInt(info[0]);
		    int E = Integer.parseInt(info[1]);
		    int DT = Integer.parseInt(info[2]);
		    
		    if (E > D || road[S][E] <= DT) continue;
		    road[S][E] = DT;
		}
		
		for (int i = 1; i <= D; i++) {
		    for (int j = 0; j < i; j++) {
		        road[0][i] = Math.min(road[0][i], road[0][j] + road[j][i]);
		    }
		}
		
		System.out.println(road[0][D]);
	}
}