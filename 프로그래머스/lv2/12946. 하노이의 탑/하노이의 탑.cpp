#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int d, int from, int by, int to)
{
    if (d == 1) answer.push_back({from, to});
    else
    {
        hanoi(d-1, from, to, by);
        answer.push_back({from, to});
        hanoi(d-1, by, from ,to);
    }
}

vector<vector<int>> solution(int n) {
    
    hanoi(n, 1, 2, 3);
    return answer;
}