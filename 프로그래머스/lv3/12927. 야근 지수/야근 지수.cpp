#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue <int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for (int i = 0; i < works.size(); i++)
        pq.push(works[i]);
    
    while(n--)
    {
        if (pq.empty()) continue;
        int temp = pq.top();
        if (temp == 0) continue;
        pq.pop();
        pq.push(temp - 1);
    }
    
    while(!pq.empty())
    {
        int temp = pq.top();
        answer += temp * temp;
        pq.pop();
    }
    
    return answer;
}