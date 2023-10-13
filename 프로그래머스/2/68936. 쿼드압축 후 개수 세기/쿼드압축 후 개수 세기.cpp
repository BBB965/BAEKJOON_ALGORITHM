#include <string>
#include <vector>

using namespace std;
int N;
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    N = arr.size();
    int itv = N;
    while (itv)
    {
        for (int i = 0; i < N; i += itv)
            for (int j = 0; j < N; j += itv)
                if (arr[i][j] >= 0)
                {
                    bool flag = true;
                    for (int a = 0; a < itv; a++)
                    {
                        for (int b = 0; b < itv; b++)
                        {
                            if (arr[i + a][j + b] != arr[i][j])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                    }
                    if (flag)
                    {
                        answer[arr[i][j]]++;
                        for (int a = 0; a < itv; a++)
                            for (int b = 0; b < itv; b++)
                                arr[i+a][j+b] = -1;
                    }
                }
        
        itv /= 2;
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[i][j] != -1) answer[arr[i][j]]++;
    
    return answer;
}