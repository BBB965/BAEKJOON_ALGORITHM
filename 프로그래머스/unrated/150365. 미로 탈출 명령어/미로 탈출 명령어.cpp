#include <string>
using namespace std;

int dir[4];

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int dist = abs(x-r) + abs(y-c);
    int kk = k - dist;
    if (kk < 0 || kk%2) return "impossible";
    
    if (x > r) dir[0] += x - r; // u
    else dir[1] += r - x; // d
    if (y > c) dir[2] += y - c; // l
    else dir[3] += c- y; // r
    
    for (int i = 0; i < dir[1]; i++) answer += 'd';
    int ld = min(kk/2, n - (x + dir[1]));
    for (int i = 0; i < ld; i++)answer += 'd';
    dir[0] += ld;
    kk -= 2 * ld;
    
    for (int i = 0; i < dir[2]; i++) answer += 'l';
    int ll = min(kk/2, y - dir[2] - 1);
    for (int i = 0; i < ll; i++) answer += 'l';
    dir[3] += ll;
    kk -= ll * 2;
    
    for (int i = 0; i < kk/2 ; i++) answer += "rl";
    for (int i = 0; i < dir[3]; i++)answer += 'r';
    for (int i = 0; i < dir[0]; i++)answer += 'u';
    
    return answer;
}