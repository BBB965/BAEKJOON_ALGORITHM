#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long answer[100010] = {0,};

int solution(int n, vector<int> money) {
    
    sort(money.begin(), money.end());
    
    answer[0] = 1;
    for (auto m : money)
        for (int i = m; i <= n; i++)
            answer[i] += answer[i-m];

    return answer[n];
}