class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {

        int nowHealth = health;
        int time = 0;
        
        for (int i = 0; i < attacks.length; i++) {
            int t = attacks[i][0] - time - 1;
            time = attacks[i][0];
            nowHealth += t * bandage[1];
            nowHealth += (t/bandage[0]) * bandage[2];
            nowHealth = Math.min(nowHealth, health);
            
            nowHealth -= attacks[i][1];
            if (nowHealth <= 0) return -1;
        }
        
        return nowHealth;
    }
}