import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        int fl = friends.length; // friends 수
        HashMap<String, Integer> kakao = new HashMap<>(); // 이름 - 인덱스
        int[][] gat = new int[fl][fl]; // 주고받은 선물 표
        int[] giftIdx = new int[fl]; // 친구별 선물지수
        int[] giftCnt = new int[fl]; // 주고 받을 선물 개수
        
        // 문자열(이름) 인덱스화 시키기
        for (int i = 0; i < fl; i++) {
            kakao.put(friends[i], i);
        }
        // 주고 받은 선물 + 선물지수 등록
        for(String gift : gifts) {
            String[] friend = gift.split(" ");
            int give = kakao.get(friend[0]);
            int take = kakao.get(friend[1]);
            gat[give][take]++;
            giftIdx[give]++; // 준 선물 (+선물지수)
            giftIdx[take]--; // 받은 선물 (-선물지수)
        }
        
        // 친구별 주고받을 선물 예측
        for (int i = 0; i < fl - 1; i++) {
            for (int j = i + 1; j < fl; j++) {
                // 두 사람이 선물 주고 받은 기록이 없거나, 주고 받은 수가 같을 때,
                if (gat[i][j] == gat[j][i]) {
                    // 선물지수 비교
                    if (giftIdx[i] > giftIdx[j]) {
                        giftCnt[i]++;
                    } else if(giftIdx[j] > giftIdx[i]) {
                        giftCnt[j]++;
                    }
                }
                // 두 사람이 선물 주고 받은 기록이 있을 때 주고받은 선물 개수 비교
                else if (gat[i][j] > gat[j][i]) {
                    giftCnt[i]++;
                } else {
                    giftCnt[j]++;
                }
            }
        }
        
        // 주고 받을 선물 개수 최댓값 구하기
        for (int i = 0; i < fl; i++) {
            answer = Math.max(answer, giftCnt[i]);
        }
        
        return answer;
    }
}