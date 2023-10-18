#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool erase[31][31] = {0,};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    bool flag = true;
    while(flag)
    {
        flag = false;
        
        for (int i = 0; i < m - 1; i++) 
        {
            for (int j = 0; j < n - 1; j++) 
            {
                if (board[i][j] == ' ') continue;
                else
                {
                    char t = board[i][j];
                    if (board[i+1][j] == t && board[i][j+1] == t && board[i+1][j+1] == t) 
                    {
                        flag = true;
                        erase[i][j] = true;
                        erase[i+1][j] = true;
                        erase[i][j+1] = true;
                        erase[i+1][j+1] = true;
                    }
                }
            }
        }
        
        if (flag) 
        {
            for (int i = 0; i < m; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (erase[i][j]) 
                    {
                        board[i][j] = ' ';
                        erase[i][j] = false;
                        answer++;
                    }
                }
            }
            
           for (int j = 0; j < n; j++)
           {
               for (int i = m-1; i >= 0; i--)
               {
                   if (board[i][j] == ' ')
                   {
                       int idx = i;
                       while (idx--)
                       {
                           if (board[idx][j] != ' ')
                           {
                                board[i][j] = board[idx][j];
                                board[idx][j] = ' ';
                                break;
                           }
                       }
                   }
               }
           }
        }
    }
    
    return answer;
}