import java.io.*;
import java.util.*;

public class Main
{
    public static class Pair implements Comparable<Pair>{
        int x;
        String y;
        Pair(int x, String y) {
            this.x = x;
            this.y = y;
        }
        
        @Override
        public int compareTo(Pair o) {
            return y.compareTo(o.y);
        }
    }
    
	public static void main(String[] args) throws IOException{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] input = br.readLine().split(" ");
		
		int p = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		boolean[] checked = new boolean[p];
		Pair[] players = new Pair[p];
		
		for (int i = 0; i < p; i++) {
		    String[] pp = br.readLine().split(" ");
		    players[i] = new Pair(Integer.parseInt(pp[0]), pp[1]);
		}
		
		for (int i = 0; i < p; i++) {
		    ArrayList<Pair> playerTeam = new ArrayList<>();
		    if (!checked[i]) {
		        for (int j = i; j < p; j++) {
		            if (playerTeam.size() == m) {
		                break;
		            }
		            if (!checked[j] && Math.abs(players[i].x - players[j].x) <= 10) {
		                checked[j] = true;
		                playerTeam.add(players[j]);
		            }
		        }
		        
		        Collections.sort(playerTeam);
		        if (playerTeam.size() == m) {
		            System.out.println("Started!");
		        } else {
		            System.out.println("Waiting!");
		        }
		        for (Pair pair : playerTeam) {
		            System.out.println(pair.x + " " + pair.y);
		        }
		    }
		}
	}
}