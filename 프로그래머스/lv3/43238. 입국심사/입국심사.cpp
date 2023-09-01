#include <string>
#include <iostream>
#include <vector>
// 시간에 대한 이분 탐색
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s = 1;
    long long e= 1e18;
    
    while (s <= e)
    {
        long long mid = (s + e) / 2;
        long long cnt = 0;
        
        for (int i = 0; i < times.size(); i++)
            cnt += (mid / (long long) times[i]);

        if (cnt < n) s = mid + 1;
        else e = mid - 1;
    }
    answer = s;
    return answer;
}