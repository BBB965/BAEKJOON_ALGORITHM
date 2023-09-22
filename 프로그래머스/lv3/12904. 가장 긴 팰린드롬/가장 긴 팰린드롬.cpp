#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int solution(string s)
{
    int answer = 1;
    if (s.length() == 1) return 1;
    
    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = s.length() - 1; j > i; j--)
        {
            if ((j - i + 1) <= answer) break;
            if (s[i] == s[j])
            {
                int si = i;
                int sj = j;
                bool flag = 1;
                while (si < sj)
                {
                    if (s[si] == s[sj])
                    {
                        si++;
                        sj--;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag) 
                {
                    answer = max(answer, j-i+1);
                    break;
                }
            }
        }
    }
    
    return answer;
}