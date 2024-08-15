#include <iostream>

using namespace std;
int A, B, N, M;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (a != b) {
        if (a%2) a++;
        if (b%2) b++;
        
        if (a != 1) {
            a /= 2;
        }
        if (b != 1) {
            b /= 2;
        }
        answer++;
    }
    return answer;
}