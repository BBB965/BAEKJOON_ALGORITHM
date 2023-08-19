#include <string>
#include <vector>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey != 0)
    {
        if (storey%10 > 5 || storey%10 == 5 && (storey/10)%10 >= 5)
        {
            int temp = 10 - storey%10;
            answer += temp;
            storey += temp;
        }
        else
        {
            int temp = storey%10;
            answer += temp;
            storey -= temp;
        }
        storey /= 10;
    }
    
    return answer;
}