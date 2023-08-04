
#include <cmath>
using namespace std;

int answer;

void find_case(int num, int plus)
{
    if (num < 3 || pow(3, plus/2) > num) return;
    if (num == 3)
    {
        if (plus == 2) answer++;
        return;
    }
    
    if (num%3 == 0 && plus >= 2) find_case(num/3, plus - 2);
    find_case(num - 1, plus + 1);
}

int solution(int n) {
    answer = 0;
    find_case(n-2, 2);
    return answer;
}