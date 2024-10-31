#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int s = 1;
    int e = 100000;
    
    while (s+1 < e) {
        int a = (s + e) / 2;
        
        long long ss = times[0];
        
        for (int i = 1; i < times.size(); i++) {
            if (diffs[i] <= a) ss += times[i];
            else ss += (times[i] + times[i-1]) * (diffs[i] - a) + times[i];
        }
        if (limit < ss) s = a;
        else e = a;
    }
    
    long long sss = times[0];
    for (int i = 1; i < times.size(); i++) {
        if (diffs[i] <= s) sss += times[i];
        else sss += (times[i] + times[i-1]) * (diffs[i] - s) + times[i];
    }
    if (limit < sss) return e;
    else return s;
    //return e;
}