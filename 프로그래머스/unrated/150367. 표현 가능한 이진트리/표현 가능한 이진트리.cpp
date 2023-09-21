#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> answer;

string str;

bool isTree(int s, int e)
{
    if (s >= e) return true;
    int b = (s+e)/2;
    
    if (str[b] == '1') 
    {
        if (isTree(s, b-1) && isTree(b+1,e)) return true;
        else return false;
    }
    else
    {
        if (str[(s+b-1)/2] == '1' || str[(b+1+e)/2] == '1') return false;
        else 
        {
            if (isTree(s,b-1) && isTree(b+1,e)) return true;
            else return false;
        }
    }
}


vector<int> solution(vector<long long> numbers) {
    for (long long num : numbers)
    {
        if (num == 1)
        {
            answer.push_back(1);
            continue;
        }
        str = "";
        while (num > 0)
        {
            str += to_string(num % 2);
            num /= 2;
        }
        long long leng = 1;
        while (leng < (str.length() + 1)) leng *= 2;
        while (leng > (str.length() + 1)) str += '0';

        if (isTree(0, str.length()-1)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}