#include <string>
#include <vector>
using namespace std;

int answer = -1;
vector <int> dp[10];

int solution(int N, int number) {
    int temp = 0;
    for (int i = 1; i < 9; i++)
    {
        temp = temp * 10 + N;
        dp[i].push_back(temp);
        if (temp == number) return i;
    }
    if (N == number) return 1;
    for (int i = 2; i < 9; i++)
    {
        if (answer != -1) break;
        for (int j = 1; j < i; j++)
        {
            if (answer != -1) break;
            for (int a : dp[j])
            {
                if (answer != -1) break;
                for (int b : dp[i-j])
                {
                    if (a+b == number || a-b == number || a*b == number)
                    {
                        answer = i;
                        break;
                    }
                    dp[i].push_back(a+b);
                    dp[i].push_back(a-b);
                    dp[i].push_back(a*b);
                    if (b != 0)
                    {
                        if (a/b == number)
                        {
                            answer = i;
                            break;
                        }
                        dp[i].push_back(a/b);
                    }
                }
            }
        }
    }
    return answer;
}