#include <string>
#include <vector>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int d = 0;
    int p = 0;
    
    for (int i = n; i > 0; i--) {
        
        d -= deliveries[i-1];
        p -= pickups[i-1];
        
        int cnt = 0;
        
        while (d < 0 || p < 0) {
            d += cap;
            p += cap;
            cnt++;
        }
        
        answer += i * 2 * cnt; 
    }
    
    return answer;
}