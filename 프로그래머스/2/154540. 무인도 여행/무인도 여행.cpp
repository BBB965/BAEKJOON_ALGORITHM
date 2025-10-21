#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

queue <pair<int,int>> q;
int N, M;
int dir[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
bool visited[101][101];

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = maps.size();
    M = maps[0].size();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == true | maps[i][j] == 'X') continue;
            int isl = maps[i][j] - '0';
            visited[i][j] = true;
            q.push(make_pair(i,j));
            while (!q.empty()) {
                pair<int,int> p = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = p.first + dir[k][0];
                    int y = p.second + dir[k][1];
                    if (x < 0 | x >= N | y < 0 | y >= M) continue;
                    if (maps[x][y] == 'X' | visited[x][y] == true) continue;
                    isl += maps[x][y] - '0';
                    visited[x][y] = true;
                    q.push(make_pair(x,y));
                }
            }

            answer.push_back(isl);
        }
    }
    if (answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}