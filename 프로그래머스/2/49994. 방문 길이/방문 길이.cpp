#include <string>
#include <iostream>
#include <map>
using namespace std;

int y,x;
bool visited[11][11][4] = {0,};
int mDir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
map <char,int> m;

bool moved(char dir) {
    int d = m[dir];
    int ny = y + mDir[d][0];
    int nx = x + mDir[d][1];
    
    bool rt = true;
    
    if (ny < 0 || nx < 0 || ny >= 11 || nx >= 11) rt = false;
    else if (visited[y][x][d]) rt = false;
    else if (visited[ny][nx][(d+2)%4]) rt = false;
    else visited[y][x][d] = true;
    if (ny >= 0 && ny < 11) y = ny;
    if (nx >= 0 && nx < 11) x = nx;
    return rt;
}

int solution(string dirs) {
    int answer = 0;
    y = 5;
    x = 5;
    
    m.insert({'U', 0});
    m.insert({'D', 2});
    m.insert({'R', 1});
    m.insert({'L', 3});
    
    //visited[5][5] = true;
    
    for(char dir : dirs) {
        if (moved(dir)) answer++;
    }
    
    
    return answer;
}