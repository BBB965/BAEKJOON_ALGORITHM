import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        
        HashMap<String,Integer> genre = new HashMap<>();
        HashMap<String,List<Integer[]>> play = new HashMap<>();
        //MultiValueMap<String,Integer[]> play = new LinkedMultiValueMap<>();
        
        for (int i = 0; i < genres.length; i++)
        {
            if (genre.containsKey(genres[i])) 
            {
                genre.put(genres[i], genre.get(genres[i]) + plays[i]);
                List<Integer[]> genreList = play.get(genres[i]);
                genreList.add(new Integer[] {plays[i], i});
                play.put(genres[i], genreList);
            }
            else 
            {
                genre.put(genres[i], plays[i]);
                List<Integer[]> genreList = new ArrayList<>();
                genreList.add(new Integer[]{plays[i], i});
                play.put(genres[i], genreList);
            }
        }
        List <String> keySet = new ArrayList<>(genre.keySet());
        keySet.sort((o1, o2) -> genre.get(o2).compareTo(genre.get(o1)));
        
        List<Integer> result = new ArrayList<>();
        for (String str : keySet){
            List<Integer[]> playList = play.get(str); 
            Collections.sort(playList, new Comparator<Integer[]>() {

                public int compare(Integer[] o1, Integer[] o2) {
                    return o2[0] - o1[0];
                }
            });
            result.add(playList.get(0)[1]);
            if (playList.size() != 1) result.add(playList.get(1)[1]);
        }
        
        int[] answer = new int[result.size()];
        
        for(int i=0; i<result.size(); i++){
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}