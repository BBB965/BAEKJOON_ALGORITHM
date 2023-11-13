import java.util.*;

class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        
        ArrayList <double []> arrayList = new ArrayList<>();
        
        for (String line : lines) {
            String [] str = line.split(" ");
            String [] time = str[1].split(":");
            double endSecond = (Integer.parseInt(time[0]) * 3600 + Integer.parseInt(time[1]) * 60) + (Double.parseDouble(time[2]));

            double startSecond = endSecond - ((Double.parseDouble(str[2].substring(0, str[2].length() - 1)))) + 0.001;
            double [] temp = {startSecond, endSecond};
            arrayList.add(temp);
        }
        
        for (int i = 0; i < arrayList.size(); i++) {
            int cnt = 1;
            double endT = arrayList.get(i)[1];
            for (int j = i + 1; j < arrayList.size(); j++) {
                if (endT + 1 > arrayList.get(j)[0]) cnt++;
            }
            if (answer < cnt) answer = cnt;
        }
        
        return answer;
    }
}