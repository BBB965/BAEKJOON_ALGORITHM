#include <string>
#include <vector>
#include <iostream>
using namespace std;

int r, c;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
bool bb[6][6] = {0,};
bool checked[6][6] = {0,};

int shortcut(int wy, int wx, int ly, int lx)
{
    if (checked[wy][wx]) return 0;
    int cnt = 0;
    
    for (int i = 0; i < 4 ;i++)
    {
        int nwy = wy + dy[i];
        int nwx = wx + dx[i];
        if (nwy < 0 || nwy >= r || nwx < 0 || nwx >= c) continue;
        if (checked[nwy][nwx] || !bb[nwy][nwx]) continue;
        checked[wy][wx] = 1;
        
        int temp = shortcut(ly,lx,nwy,nwx) + 1;
        checked[wy][wx] = 0;
        
        if (cnt%2 == 0 && temp%2 == 1) cnt = temp;
        else if (cnt%2 == 0 && temp%2 == 0) cnt = max(cnt, temp);
        else if (cnt%2 == 1 && temp%2 == 1) cnt = min(cnt, temp);
    }
    return cnt;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    r = board.size();
    c = board[0].size();
    if (r == 1 && c == 1) return 0;

    for (int y = 0; y < r; y++)
        for (int x = 0; x < c; x++)
            if (board[y][x] == 1) bb[y][x] = 1;
    
    int answer = shortcut(aloc[0], aloc[1], bloc[0], bloc[1]);
    
    return answer;
}