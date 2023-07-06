#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int lyan[11] = {0,};
int appeach[11] = {0,};
int gap = 0;

void find_ans(int idx, int N)
{
    if (N == 0)
    {
        int sumL = 0;
        int sumA = 0;
        for (int i = 0; i < 11; i++)
        {
            if (lyan[i] > appeach[i]) sumL += i;
            else if (appeach[i] > 0) sumA += i;
        }
        if (sumL - sumA > gap)
        {
            answer.clear();
            for (int i = 10; i >= 0; i--)
                answer.push_back(lyan[i]);
            gap = sumL - sumA;
        }
        return;
    }
    for (int i = idx; i <= 10; i++)
    {
        if (lyan[i] > appeach[i]) continue;
        lyan[i]++;
        find_ans(i, N - 1);
        lyan[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    for (int i = 0; i < 11; i++)
        appeach[i] = info[10 - i];
    find_ans(0, n);
    if (gap == 0) answer.push_back(-1);
    return answer;
}