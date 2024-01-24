#include <string>
#include <vector>
#include <queue>
using namespace std;

queue <pair<int,int>> pq;

int solution(int x, int y, int n) {
    
    int cnt[100000000] = {0,};
    
    pq.push({y, 1});
    cnt[y] = 1;
    
    int answer = 1e9;
    while (!pq.empty()) {
        pair<int,int> num = pq.front();
        pq.pop();
        if (num.first == x) {
            answer = num.second - 1;
            break;
        } else if (num.first > x) {
            pq.push({num.first - n, num.second + 1});
            if (num.first%2 == 0 && cnt[num.first/2] == 0)  {
                pq.push({num.first / 2, num.second + 1});
                cnt[num.first / 2] = num.second + 1;
            }
            if (num.first%3 == 0&& cnt[num.first/3] == 0) {
                pq.push({num.first / 3, num.second + 1});
                cnt[num.first / 3] = num.second + 1;
            }
        }
    }

    return answer == 1e9 ? -1 : answer;
}