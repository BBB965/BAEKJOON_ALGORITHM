import java.util.*;

class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        
        ArrayList <int []> arrayList = new ArrayList<>();
        
        for (String line : lines) {
            String [] str = line.split(" ");
            String [] time = str[1].split(":");
            int endSecond = (Integer.parseInt(time[0]) * 3600 + Integer.parseInt(time[1]) * 60) * 1000 + (int) (Double.parseDouble(time[2]) * 1000);

            int startSecond = endSecond - (int) ((Double.parseDouble(str[2].substring(0, str[2].length() - 1))) * 1000) + 1;
            int [] temp = {startSecond, endSecond};
            arrayList.add(temp);
        }
        
        for (int i = 0; i < arrayList.size(); i++) {
            int cnt = 1;
            int endT = arrayList.get(i)[1];
            for (int j = i + 1; j < arrayList.size(); j++) {
                if (endT + 1000 > arrayList.get(j)[0]) cnt++;
            }
            if (answer < cnt) answer = cnt;
        }
        
        return answer;
    }
}