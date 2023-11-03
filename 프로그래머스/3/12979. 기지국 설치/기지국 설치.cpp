#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int std = 2 * w + 1;
    
    if (stations[0] > w + 1) {
        answer += (stations[0] - w) / std;
        if ((stations[0] - w) % std != 0) answer++;
    }
    
    for (int i = 0; i < stations.size() - 1; i++) {
        if (stations[i + 1] - stations[i] > std) {
            int bet = stations[i+1] - stations[i] - std;
            answer += bet / std;
            if (bet%std != 0) answer++;
        }
    }
    
    if (stations.back() + w < n) {
        answer += (n - stations.back() - w) / std;
        if ((n- stations.back() - w) % std != 0) answer++;
    }
    
    return answer;
}