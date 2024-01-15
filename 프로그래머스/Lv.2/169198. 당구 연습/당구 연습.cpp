#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (vector<int> ball : balls) {
        int ans = 1e9;
        
        int tbx2 = 2 * n - ball[1];
        if ((startY < ball[1] || startX != ball[0])&& ans > pow(startX - ball[0], 2) + pow(startY + ball[1], 2))
            ans = pow(startX - ball[0], 2) + pow(startY + ball[1], 2);
                
        if ((startY > ball[1] || startX != ball[0])&& ans > pow(startX - ball[0], 2) + pow(startY - tbx2, 2))
            ans = pow(startX - ball[0], 2) + pow(startY - tbx2, 2);
        
        int tby2 = 2 * m - ball[0];
            
        if ((startX < ball[0] || startY != ball[1]) && ans > pow(startY - ball[1], 2) + pow(startX + ball[0], 2))
            ans = pow(startY - ball[1], 2) + pow(startX + ball[0], 2);
            
        if ((startX > ball[0] || startY != ball[1])&& ans > pow(startY - ball[1], 2) + pow(startX - tby2, 2))
            ans = pow(startY - ball[1], 2) + pow(startX - tby2, 2);
        
        answer.push_back(ans);
    }
    
    return answer;
}