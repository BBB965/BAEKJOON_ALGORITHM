#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string num = "";

bool checked(long long N)
{
    if (N <= 1) return 0;
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0) return 0;
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    while (n > 0)
    {
        num += to_string(n%k);
        n /= k;
    }
    reverse(num.begin(), num.end());
    
    string temp = "";
    for (char alp : num)
    {
        if (alp == '0')
        {
            if (temp != "" && checked(stol(temp))) answer++;
            temp = "";
        }
        else temp += alp;
    }
    if (temp != "" && checked(stol(temp))) answer++;
    return answer;
}