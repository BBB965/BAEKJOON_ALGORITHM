#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s/n <= 0) answer.push_back(-1);
    else
    {
        while (s > 0)
        {
            answer.push_back(s/n);
            s -= s/n;
            n--;
        }
    }
    return answer;
}