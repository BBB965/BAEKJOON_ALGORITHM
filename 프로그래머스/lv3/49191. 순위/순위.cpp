#include <string>
#include <vector>
using namespace std;

int fw[101][101] = {0,};

int solution(int n, vector<vector<int>> results) {
    
    int answer = 0;
    
    for (vector<int> result : results)
    {
        fw[result[0]][result[1]] = 1;
        fw[result[1]][result[0]] = -1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (fw[j][k] == 0)
                {
                    if (fw[j][i] == 1 && fw[i][k] == 1) fw[j][k] = 1;
                    else if (fw[j][i] == -1 && fw[i][k] == -1) fw[j][k] = -1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            cnt += abs(fw[i][j]);
        if (cnt == n-1) answer++;
    }
    
    return answer;
}