#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    
    sort(routes.begin(), routes.end(), cmp);
    int answer = 1;
    int idx = 1;
    int N = routes.size();
    int camera = routes[0][1];
    while (idx < N)
    {
        if (routes[idx][0] > camera)
        {
            answer++;
            camera = routes[idx][1];
        }
        idx++;
    }
    
    return answer;
}