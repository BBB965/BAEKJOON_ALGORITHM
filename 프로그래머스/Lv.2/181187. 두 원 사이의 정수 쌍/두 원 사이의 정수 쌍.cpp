#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long r11 = (long long) r1;
    long long r111 = pow(r11, 2);
    
    long long r22 = (long long) r2;
    long long r222 = pow(r22, 2);
    
    for (long i = 1; i < r2; i++) {
        long long t = pow(i, 2);
        long long u = floor(sqrt(r222 - t));
        long long l = ceil(sqrt(r111 - t));
        answer += (u - l + 1);
        //cout << i << " " << answer << '\n';
    }
    
    answer += 1;
    
    return answer * 4;
}