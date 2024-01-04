#include <string>
#include <vector>

using namespace std;

int answer = 1e9, cnt = 0;
vector<int> p;
vector<string> m;

void dfs(int idx, int s) {
    if (cnt == 0) {
        answer = min(answer, s);
        return;
    }
    if (idx >= m.size()) {
        answer = min(answer, s);
        return;
    }
    
    if (p[0] > 0) {
        p[0]--;
        cnt--;
        if (idx + 5 > m.size()) dfs(m.size(), s + m.size() - idx);
        else dfs(idx + 5, s + 5);
        p[0]++;
        cnt++;
    }
    if (p[1] > 0) {
        p[1]--;
        cnt--;
        int t = 0;
        if (idx + 5 > m.size()) {
            for (int i = 0; i < m.size() - idx; i++) {
                if (m[i+idx] == "diamond") t += 5;
                else t += 1;
            }
            dfs(m.size(), s + t);
        }
        else {
            for (int i = 0; i < 5; i++) {
                if (m[i + idx] == "diamond") t += 5;
                else t += 1;
            }
            dfs(idx + 5, s + t);
        }
        p[1]++;
        cnt++;
    }
    if (p[2] > 0) {
        p[2]--;
        cnt--;
        int t = 0;
        if (idx + 5 > m.size()) {
            for (int i = 0; i < m.size() - idx; i++) {
                if (m[i+idx] == "diamond") t += 25;
                else if (m[i+idx] == "iron") t += 5;
                else t += 1;
            }
            dfs(m.size(), s + t);
        }
        else {
            for (int i = 0; i < 5; i++) {
                if (m[i + idx] == "diamond") t += 25;
                else if (m[i+idx] == "iron") t += 5;
                else t += 1;
            }
            dfs(idx+5, s + t);
        }
        p[2]++;
        cnt++;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    p = picks;
    m = minerals;
    
    for (int pick : picks) cnt += pick;
    
    dfs(0, 0);
    
    return answer;
}