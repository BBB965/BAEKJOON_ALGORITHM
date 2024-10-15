#include <iostream>
#include <vector>
using namespace std;

vector <int> roads[51];
int al[51][51] = {0,};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i != j) al[i][j] = 1e9;
    
    for (vector<int> r : road) {
        al[r[0]][r[1]] = min(al[r[0]][r[1]], r[2]);
        al[r[1]][r[0]] = min(al[r[1]][r[0]], r[2]);
    }
    
    for (int i = 1; i <= N ; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                al[j][k] = min(al[j][k], al[j][i] + al[i][k]);
    
    
    for (int i = 1; i <= N; i++)
        if(al[1][i] <= K) answer++;
    
    return answer;
}