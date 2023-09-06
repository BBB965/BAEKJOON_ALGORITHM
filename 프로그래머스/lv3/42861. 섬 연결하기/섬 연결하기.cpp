#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101] = {0,};

bool cmp (const vector<int>& a, const vector<int>& b) {
    if (a[2] == b[2]) 
    {
        if (a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    else return a[2] < b[2];
}

int isParent(int c) {
    if (parent[c] == c) return c;
    else return isParent(parent[c]);
}

void unionP(int a, int b)
{
    int aP = isParent(a);
    int bP = isParent(b);
    if (aP < bP) parent[bP] = aP;
    else parent[aP] = bP;
}

bool findP(int a, int b) 
{
    return isParent(a) == isParent(b) ? true : false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    
    for (vector<int> cost : costs)
    {
        if (!findP(cost[0], cost[1]))
        {
            answer += cost[2];
            unionP(cost[0], cost[1]);
        }
    }
    
    return answer;
}