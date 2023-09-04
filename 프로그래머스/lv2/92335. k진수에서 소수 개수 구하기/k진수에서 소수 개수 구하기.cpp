#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string num = "";
// 소수인지 아닌지 판단
bool checked(long long N)
{
    if (N <= 1) return 0;
    // 소수에서는 sqrt(N)보다 작거나 같은 값에서 찾아줌
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0) return 0;
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    // k진수로 바꿔주기
    while (n > 0)
    {
        num += to_string(n%k);
        n /= k;
    }
    reverse(num.begin(), num.end());
    
    // 숫자에서 소수 찾기
    string temp = "";
    for (char alp : num)
    {
        // 만약 0일때, temp 가 소수인지 아닌지 판단
        if (alp == '0')
        {
            if (temp != "" && checked(stol(temp))) answer++;
            temp = "";
        }
        // 그외는 temp에 포함시키기
        else temp += alp;
    }
    // 남은 temp
    if (temp != "" && checked(stol(temp))) answer++;
    return answer;
}