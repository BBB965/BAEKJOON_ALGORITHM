#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<int> vect[300010];
vector <long long> s;

void dfs(int p, int c)
{
    for (int i = 0; i < vect[c].size(); i++)
        if (vect[c][i] != p) dfs(c, vect[c][i]);
    
    s[p] += s[c];
    answer += abs(s[c]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    for (int A : a) s.push_back(A);
    
    for (vector<int> t : edges)
    {
        vect[t[0]].push_back(t[1]);
        vect[t[1]].push_back(t[0]);
    }
    
    dfs(0,0);
    return s[0] == 0 ? answer : -1;
}