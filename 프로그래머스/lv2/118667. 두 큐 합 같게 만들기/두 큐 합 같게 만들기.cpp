#include <string>
#include <vector>
#include <queue>
using namespace std;
long long q1 = 0;
long long q2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0;
    int qs = queue1.size();
    for (int i = 0; i < qs; i++)
    {
        q1 += queue1[i];
        q2 += queue2[i];
    }
    int idx1 = 0; int idx2 = 0;
    while (answer < qs * 4)
    {
        if (q1 == q2) break;
        if (q1 < q2)
        {
            q1 += queue2[idx2];
            q2 -= queue2[idx2];
            queue1.push_back(queue2[idx2]);
            idx2++;
        }
        else if (q2 < q1)
        {
            q1 -= queue1[idx1];
            q2 += queue1[idx1];
            queue2.push_back(queue1[idx1]);
            idx1++;
        }
        answer++;
    }
    if (answer == qs * 4) answer = -1;
    return answer;
}