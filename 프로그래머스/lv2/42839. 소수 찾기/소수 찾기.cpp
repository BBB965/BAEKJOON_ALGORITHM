#include <string>
#include <vector>
#include <cmath>
using namespace std;

int answer = 0;
bool nums[10000000] = {0,};
bool used[7] = {0,};
string st;

void isPrime(int t)
{
    bool flag = true;
    for (int i = 2; i <= sqrt(t); i++)
        if (t%i == 0)
        {
            flag = false;
            break;
        }
            
    if (flag) answer++;
}

void makePrime(string temp)
{
    for (int i = 0; i < st.length(); i++)
    {
        if (used[i]) continue;
        used[i] = 1;
        int t = stoi(temp + st[i]);
        if (!nums[t])
        {
            isPrime(t);
            nums[t] = 1;
        }
        makePrime(temp + st[i]);
        used[i] = 0;
    }
}

int solution(string numbers) {
    st = numbers;
    nums[0] = 1;
    nums[1] = 1;
    makePrime("");
    
    return answer;
}