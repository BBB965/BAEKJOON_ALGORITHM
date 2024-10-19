#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> checked[101][101];
queue <vector<int>> q; 
// 0.로봇 순서, 1. 현재 r, 2. 현재 c, 3.목표 순서, 4.움직인 횟수

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    int rCnt = routes.size();
    for (int i = 0; i < rCnt; i++) {
        int r = points[routes[i][0]-1][0];
        int c = points[routes[i][0]-1][1];
        
        checked[r][c].push_back(0);
        
        vector<int> t = {i, r, c, 1, 0};
        q.push(t);
    }
    
    while (!q.empty()) {
        vector<int> t = q.front();
        q.pop();
        
        int tr = points[routes[t[0]][t[3]]-1][0];
        int tc = points[routes[t[0]][t[3]]-1][1];
        
        if (t[1] == tr && t[2] == tc) {
            t[3]++;
            if (t[3] == routes[t[0]].size()) continue;
            tr = points[routes[t[0]][t[3]]-1][0];
            tc = points[routes[t[0]][t[3]]-1][1];
        }
        
        if (t[1] != tr) {
            if (t[1] < tr) t[1]++;
            else t[1]--;
        } else {
            if (t[2] < tc) t[2]++;
            else t[2]--;
        }
        t[4]++;
        checked[t[1]][t[2]].push_back(t[4]);
        q.push(t);
    }
    
    for (int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if (checked[i][j].empty()) continue;
            int e = checked[i][j].size();
            int s = checked[i][j][0];
            int k = 1;
            while (k < e) {
                if (s == checked[i][j][k]) {
                    answer++;
                    while (s == checked[i][j][k]) k++;
                }
                s = checked[i][j][k];
                k++;
            }
        }
    }
    
    return answer;
}