#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    int N = cookie.size();
    
    for (int i = 0; i < N-1; i++)
    {
        int l = i;
        int r = i+1;

        int son1 = cookie[i];
        int son2 = cookie[i+1];
        
        while (true)
        {
            if (l == 0)
            {
                if (son1 < son2) break;
                else if (son1 == son2)
                {
                    answer = max(answer, son1);
                    break;
                }
            }
            if (r == N-1)
            {
                if (son1 > son2) break;
                else if (son1 == son2)
                {
                    answer = max(answer, son1);
                    break;
                }
            }
            if (l == 0 && r == N-1)
            {
                if (son1 == son2) answer = max(answer, son1);
                break;
            }
            
            if (son1 == son2)
            {
                answer = max(answer, son1);
                l--;
                r++;
                son1 += cookie[l];
                son2 += cookie[r];
            }
            else if (son1 > son2)
            {
                son2 += cookie[r+1];
                r++;
            }
            else
            {
                son1 += cookie[l-1];
                l--;
            }
        }
    }
    
    return answer;
}