#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0;
map <int,int> m;

bool cmp(const pair<int,int>& a,const pair<int,int>& b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {

    for (int t : tangerine)
    {
        if (m.find(t) != m.end()) 
        {
            m[t]++;
            if (m[t] >= k) answer = 1;
        }
        else m.insert({t,1});
    }
    if (answer == 1) return answer;
    
    vector<pair<int,int>> vect(m.begin(),m.end());
    sort(vect.begin(), vect.end(), cmp);
    
    int cnt = k;
    
    for (auto um : vect)
    {
        if (cnt == 0) break;
        answer++;
        if (um.second >= cnt) cnt = 0;
        else cnt -= um.second;
    }

    return answer;
}