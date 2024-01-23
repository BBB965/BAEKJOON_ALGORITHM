#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M, sx, sy, lx, ly, ey, ex;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int visited[111][111][2] = {0,};
queue <pair<pair<int,int>, int>> q;

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j][0] = 1e9;
            visited[i][j][1] = 1e9;
            
            if (maps[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (maps[i][j] == 'L') {
                lx = i;
                ly = j;
            } else if (maps[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    
    visited[sx][sy][0] = 0;
    q.push({{sx, sy}, 0});
    
    while (!q.empty()) {
        pair<pair<int,int>, int> temp = q.front();
        q.pop();
        if (temp.first.first == ex && temp.first.second == ey && temp.second == 1) continue;
        
        for (int i = 0;i < 4; i++) {
            int nx = temp.first.first + dx[i];
            int ny = temp.first.second + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (maps[nx][ny] == 'X') continue;
            if (visited[nx][ny][temp.second] <= visited[temp.first.first][temp.first.second][temp.second] + 1) continue;
            visited[nx][ny][temp.second] = visited[temp.first.first][temp.first.second][temp.second] + 1;
            if (nx == lx && ny == ly && temp.second == 0) {
                visited[nx][ny][1] = visited[temp.first.first][temp.first.second][temp.second] + 1;
                q.push({{nx, ny}, 1});
            } else q.push({{nx, ny}, temp.second});
        }
    }
    
    return visited[ex][ey][1] == 1e9 ? -1 : visited[ex][ey][1];
}