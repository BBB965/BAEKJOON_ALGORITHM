#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    // O,X 잘못둔 경우 찾기
    int Ocnt = 0;
    int Xcnt = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') Ocnt++;
            else if (board[i][j] == 'X') Xcnt++;
        }
    }
    
    if (Ocnt < Xcnt || abs(Ocnt - Xcnt) > 1) return 0;
    else if (Ocnt + Xcnt == 0) return 1;
    else {
        // 선공, 후공 승리해서 게임 종료 상황
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                if (board[i][0] == 'O' && Ocnt == Xcnt) return 0;
                if (board[i][0] == 'X' && Ocnt > Xcnt) return 0;
            }
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                if (board[0][i] == 'O' && Ocnt == Xcnt) return 0;
                if (board[0][i] == 'X' && Ocnt > Xcnt) return 0;
            }
        }
        
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            if (board[0][0] == 'O' && Ocnt == Xcnt) return 0;
            if (board[0][0] == 'X' && Ocnt > Xcnt) return 0;
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            if (board[2][0] == 'O' && Ocnt == Xcnt) return 0;
            if (board[2][0] == 'X' && Ocnt > Xcnt) return 0;
        }
        
        return 1;
    }
}