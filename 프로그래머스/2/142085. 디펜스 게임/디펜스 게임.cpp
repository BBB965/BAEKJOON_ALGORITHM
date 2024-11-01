#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = k;
    int idx = k;
    int ll = enemy.size();
    
    if (ll < k) return ll;
    
    for (int i = 0; i < k; i++) pq.push(enemy[i]);
    
    while (idx < ll) {
        int num = pq.top();
        if (enemy[idx] > num) {
            pq.pop();
            pq.push(enemy[idx]);
        }
        else num = enemy[idx];
        
        if (n < num) break;
        else {
            n -= num;
            idx++;
            //cout << num << '\n';
        }
    }
    
    return idx;
}