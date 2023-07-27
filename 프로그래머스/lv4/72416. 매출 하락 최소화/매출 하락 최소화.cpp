#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> tree[300010];
int dp[300010][2] = {0,}; // 끝에 0, 1은 참석의 여부

void workshop (int p)
{
    int N = 0;
    int A = 1e9;
    bool flag = 0;
    for (int i = 0; i < tree[p].size(); i++)
    {
        workshop(tree[p][i]);
        N += min(dp[tree[p][i]][0], dp[tree[p][i]][1]);
        if (dp[tree[p][i]][1] <= dp[tree[p][i]][0]) flag = 1;
        else A = min(A, dp[tree[p][i]][1] - dp[tree[p][i]][0]);
    }
    dp[p][1] += N;
    dp[p][0] = N;
    if (!flag && A != 1e9) dp[p][0] += A;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    
    for (int i = 0; i < sales.size(); i++)
        dp[i+1][1] = sales[i];

    for (int i = 0; i < links.size(); i++)
        tree[links[i][0]].push_back(links[i][1]);
    
    workshop(1);
    int answer = min(dp[1][0], dp[1][1]);
    return answer;
}