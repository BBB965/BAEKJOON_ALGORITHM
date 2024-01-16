#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 1e9;
int N, M;

int solution(int n, vector<int> weak, vector<int> dist) {
    
    N = weak.size();
    M = dist.size();
    
    for (int i = 0; i < N - 1; i++) weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end());
    
    for (int i = 0; i < N; i++) {
        bool checked[8] = {0,};
        
        int s = i;
        int e = i + N - 1;
        
        while (s <= e) {
            int t = weak[e] - weak[s];
            int idx = 0;
            while (idx < M) {
                if (t > dist[idx]) idx++;
                else {
                    if (checked[idx]) idx++;
                    else break;
                }
            }
            if (idx == M) {
                e--;
            } else {
                checked[idx] = true;
                s = e + 1;
                e = i + N - 1;
            }
        }
        
        if (e == i + N - 1) {
            int t = 0;
            for (int j = 0; j < M; j++) {
                if (checked[j]) t++;
            }
            if (answer > t) answer = t;
        }
    }
    
    return answer == 1e9 ? -1 : answer;
}