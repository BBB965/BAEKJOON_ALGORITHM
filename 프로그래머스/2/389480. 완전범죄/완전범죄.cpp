#include <string>
#include <vector>

using namespace std;

int answer = 1e9;
int nn, mm, inf;
bool cnt[41][121][121] = {0,};

void findA(vector<vector<int>> info, int A, int B, int i) {
    if (A >= nn || B >= mm) return;
    if (cnt[i][A][B]) return;
    cnt[i][A][B] = 1;
    
    if (i == inf) {
        if (answer > A) answer = A;
        return;
    }

    findA(info, A + info[i][0], B, i+1);
    findA(info, A, B + info[i][1], i+1);
    
}

int solution(vector<vector<int>> info, int n, int m) {
    
    inf = info.size();
    nn = n; mm = m;
    
    findA(info, 0, 0, 0);
    
    return answer >= n ? -1 : answer;
}