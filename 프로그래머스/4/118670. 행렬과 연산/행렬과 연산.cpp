#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int N, M;
vector<vector<int>> answer;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    
//     N = rc.size();
//     M = rc[0].size();
    
//     deque <deque<int>> dq;
//     for (int i = 0; i < N; i++) {
//         deque<int> t;
//         for (int r : rc[i]) {
//             t.push_back(r);
//         }
//         dq.push_back(t);
//     }
    
//     for(string op : operations) {
//         if (op == "Rotate") {
//             for (int j = 0; j < N-1; j++) {
//                 dq[j].push_front(dq[j+1].front());
//                 dq[j+1].pop_front();
//             }
    
//             for (int j = N-1; j > 0; j--) {
//                 dq[j].push_back(dq[j-1].back());
//                 dq[j-1].pop_back();
//             }
//         }
//         else {
//             dq.push_front(dq.back());
//             dq.pop_back();
//         }
//     }
    
//     for (int i = 0; i < N; i++) {
//         vector<int> t;
//         for (int d : dq[i]) {
//             t.push_back(d);
//         }
//         answer.push_back(t);
//     }
    
//     return answer;
    
    int r = rc.size();
    int c = rc[0].size();
    deque<int> col1, col2;
    for(int i = 0; i < r; i++){
        col1.push_back(rc[i][0]);
        col2.push_back(rc[i][c-1]);
    }

    deque<int> rows[r];
    for(int i = 0; i < r; i++)
        for(int j = 1; j <= c-2; j++)
            rows[i].push_back(rc[i][j]);
    
    int idx = 0;
    for(auto op : operations){
        if(op == "ShiftRow"){
            col1.push_front(col1.back());
            col1.pop_back();
            col2.push_front(col2.back());
            col2.pop_back();
            idx--;
            if(idx == -1) idx = r-1;
        }
        else{ // Rotate
            rows[idx].push_front(col1.front());
            col1.pop_front();
            
            col2.push_front(rows[idx].back());
            rows[idx].pop_back();
            
            rows[(idx+r-1)%r].push_back(col2.back());
            col2.pop_back();
            
            col1.push_back(rows[(idx+r-1)%r].front());
            rows[(idx+r-1)%r].pop_front();
        }
    }
    
    
    vector<vector<int>> ret(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        ret[i][0] = col1[i];
        for(int j = 1; j <= c-2; j++)
            ret[i][j] = rows[(i + idx) % r][j-1];
        ret[i][c-1] = col2[i];
    }
    return ret;
}