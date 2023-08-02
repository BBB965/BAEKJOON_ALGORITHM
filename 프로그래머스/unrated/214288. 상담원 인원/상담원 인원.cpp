#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 1e9;
int K, N;
vector <vector<int>> info;
vector <int> mentors;

void waiting_time()
{
    int T = 0;
    vector <int> vect[5];
    for (int i = 0; i < info.size(); i++)
    {
        int idx = info[i][2] - 1;
        if(vect[idx].size() < mentors[idx])
            vect[idx].push_back(info[i][0] + info[i][1]);
        else
        {
            int ttt = info[i][0];
            int ss = 1e9;
            int kk = -1;
            for (int j = 0; j < vect[idx].size(); j++)
            {
                if (vect[idx][j] <= ttt)
                {
                    vect[idx][j] = ttt + info[i][1];
                    kk = -1;
                    break;
                }
                else
                {
                    if (vect[idx][j] < ss)
                    {
                        ss = vect[idx][j];
                        kk = j;
                    }
                }
            }
            if (kk != -1)
            {
                T += vect[idx][kk] - info[i][0];
                vect[idx][kk] += info[i][1];
            }
        }
    }
    answer = min(answer, T);
}

void assign(int idx, int left)
{
    if (idx == K - 1)
    {
        mentors[idx] += left;
        waiting_time();
        mentors[idx] -= left;
        return;
    }
    for (int i = 0; i <= left; i++)
    {
        mentors[idx] += i;
        assign(idx+1, left - i);
        mentors[idx] -= i;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K = k;
    N = n;
    info = reqs;
    for (int i = 0; i < k; i++) mentors.push_back(1);
    assign(0, n - k);
    return answer;
}