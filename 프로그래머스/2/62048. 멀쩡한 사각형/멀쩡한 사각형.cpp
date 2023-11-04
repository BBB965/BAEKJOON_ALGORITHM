#include <iostream>
using namespace std;

int comm(int w, int h) {
    for (int i = min(w,h); i >= 1; i--) {
        if (w%i == 0 && h%i == 0) return i;
    }
    return 0;
}

long long solution(int w,int h) {
    long long answer = (long long) w * (long long) h;
    answer -= (w + h - comm(w,h));
    return answer;
}