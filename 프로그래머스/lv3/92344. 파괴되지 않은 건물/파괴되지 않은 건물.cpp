#include <string>
#include <vector>

using namespace std;

int accum[1010][1010] = {0,};

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int N = board.size();
    int M = board[0].size();
    int answer = N * M;
    for (int i = 0; i < skill.size();i++)
    {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if (type == 1) degree *= -1;
        accum[r1][c1] += degree;
        accum[r2 + 1][c2 + 1] += degree;
        accum[r2 + 1][c1] -= degree;
        accum[r1][c2 + 1] -= degree;
    }
    for (int y = 0; y < N; y++)
        for (int x = 1; x < M; x++)
            accum[y][x] += accum[y][x-1];
    
    for (int x = 0; x < M; x++)
        for (int y = 0; y < N; y++)
        {
            if (y > 0) accum[y][x] += accum[y-1][x];
            if (board[y][x] + accum[y][x] <= 0) answer--;
        }
    
    return answer;
}