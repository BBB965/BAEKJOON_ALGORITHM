#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < schedules.size(); i++) {
        int hm = schedules[i]%100 + (schedules[i]/100) * 60 + 10;
        bool event = true;
        for (int j = 0; j < 7; j++) {
            if ((startday+j)%7 == 6 || (startday+j)%7 == 0) continue;
            int shm = timelogs[i][j]%100 + (timelogs[i][j]/100) * 60;
            if (shm > hm) {
                event = false;
                break;
            }
        }
        if (event) answer++;
    }
    
    return answer;
}