#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ans = 0, T = 0;

struct cmp {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    }  
};

priority_queue <pair<int,int>, vector<pair<int,int>>, cmp> pq;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int idx = 0;
    int N = jobs.size();
    
    while (idx < N || !pq.empty())
    {
        if (pq.empty())
        {
            T = max(T, jobs[idx][0]);
            T += jobs[idx][1];
            ans += jobs[idx][1];
            idx++;
        }
        else
        {
            pair<int,int> temp = pq.top();
            pq.pop();
            T += temp.second;
            ans += (T - temp.first);
        }
        
        for (int i = idx; i < N; i++)
        {
            if (jobs[i][0] > T) break;
            pq.push({jobs[i][0], jobs[i][1]});
            idx++;
        }
    }
    ans /= N;
    return ans;
}