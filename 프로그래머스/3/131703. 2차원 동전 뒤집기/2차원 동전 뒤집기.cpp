#include <string>
#include <vector>

using namespace std;
int answer = 1e9, X, Y;
bool checked[10][2] = {0,};
vector<vector<int>> beging;
vector<vector<int>> tar;

void reverse_coin(int idx, int d) {
    if (d == 1) {
        for (int i = 0; i < Y; i++) beging[idx][i] = 1 - beging[idx][i]; 
    } else {
        for (int i = 0; i < X; i++) beging[i][idx] = 1 - beging[i][idx];
    }
}

void find_min(int idx, int cnt) {
    if (beging == tar) {
        answer = min(answer, cnt);
        return;
    }
    
    for (int i = idx; i < X; i++) {
        if (checked[i][1]) continue;
        checked[i][1] = true;
        reverse_coin(i, 1);
        find_min(i, cnt + 1);
        reverse_coin(i, 1);
        checked[i][1] = false;
    } 
    
    for (int i = idx; i < Y; i++) {
        if (checked[i][0]) continue;
        checked[i][0] = true;
        reverse_coin(i, 0);
        find_min(i, cnt + 1);
        reverse_coin(i, 0);
        checked[i][0] = false;
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    beging = beginning;
    tar = target;
    X = beginning.size();
    Y = beginning[0].size();
    find_min(0, 0);
    
    return answer == 1e9? -1 : answer;
}