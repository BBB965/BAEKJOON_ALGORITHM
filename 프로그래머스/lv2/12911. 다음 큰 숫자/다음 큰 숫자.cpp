#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n+1;
    int cnt = 0;
    
    while(n)
    {
        cnt += n%2;
        n /= 2;
    }
    
    while (true)
    {
        int t = answer;
        int c = 0;
        while (t)
        {
            c += t%2;
            t /= 2; 
        }
        if (c == cnt) break;
        answer++;
    }
    
    return answer;
}