#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long answer = 0;
bool check[3] = {0,};
char c[3] = {'*', '-', '+'};
vector <long long> number;
vector <char> sign;
vector <int> ord;

void make_max()
{
    vector <long long> copy_n = number;
    vector <char> copy_c = sign;
    
    for (int i = 0; i < 3; i++)
    {
        int idx = 0;
        while (idx < copy_c.size())
        {
            if (copy_c[idx] == c[ord[i]])
            {
                if (copy_c[idx] == '*') copy_n[idx] *= copy_n[idx + 1];
                else if (copy_c[idx] == '-') copy_n[idx] -= copy_n[idx+1];
                else copy_n[idx] += copy_n[idx+1];
                
                copy_c.erase(copy_c.begin() + idx, copy_c.begin() + idx + 1);
                copy_n.erase(copy_n.begin() + idx + 1, copy_n.begin() + idx + 2);
            }
            else idx++;
        }
    }
    answer = max(answer, abs(copy_n[0]));
}

void make_ord(int cnt)
{
    if (cnt == 3) 
    {
        make_max();
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (check[i]) continue;
        ord.push_back(i);
        check[i] = 1;
        make_ord(cnt + 1);
        ord.pop_back();
        check[i] = 0;
    }
}

long long solution(string expression) {
    int idx1 = 0;
    int idx2 = 0;
    while (idx2 < expression.length())
    {
        if (expression[idx2] < '0' || expression[idx2] > '9')
        {
            number.push_back(stoll(expression.substr(idx1, idx2 - idx1)));
            sign.push_back(expression[idx2]);
            idx1 = idx2+1;
        }
        idx2++;
    }
    
    number.push_back(stoll(expression.substr(idx1)));
    make_ord(0);
    
    return answer;
}