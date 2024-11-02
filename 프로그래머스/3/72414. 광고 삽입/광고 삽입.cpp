#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long tt[360002] = {0,};

int sti(string t) {
    int h = stoi(t.substr(0,2));
    int m = stoi(t.substr(3,2));
    int s = stoi(t.substr(6,2));
    return h*60*60 + m*60 + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int pt = sti(play_time);
    
    for (string log : logs) {
        int st = sti(log.substr(0,8));
        int et = sti(log.substr(9,8));
        
        tt[st]++;
        tt[et]--;
    }
    
    int at = sti(adv_time);
    
    for (int i = 1; i <= pt; i++) tt[i] += tt[i-1]; //재생 시간 수
    for (int i = 1; i <= pt; i++) tt[i] += tt[i-1]; //누적 재생 시간 수
    
    int idxT = 0;
    long long cnt = 0;
    
    for (int i = 0; i <= pt - at + 1; i++) {
        long long temp = tt[i + at - 1];
        if (i > 0) temp -= tt[i - 1];
        
        if (temp > cnt) {
            idxT = i;
            cnt = temp;
        }
    }
    
    int hh = idxT / 3600;
    if (hh < 10) answer += '0';
    answer += to_string(hh) + ':';
    
    int mm = (idxT%3600)/60;
    if (mm < 10) answer += '0';
    answer += to_string(mm) += ':';
    
    int ss = (idxT%3600)%60;
    if (ss < 10) answer += '0';
    answer += to_string(ss);
    
    return answer;
}