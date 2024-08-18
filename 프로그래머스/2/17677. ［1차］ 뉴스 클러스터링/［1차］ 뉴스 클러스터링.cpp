#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

// 중복을 허용하는 multiset 사용
multiset<string> J1, J2;
set <string> uni;
int UNI = 0, INTERSEC = 0;

bool checking(char c)
{
    if (c >= 'A' && c <= 'Z') return true;
    else if (c >= 'a' && c <= 'z') return true;
    else return false;
}

int solution(string str1, string str2) {
    
    for (int i = 0; i < str1.length() - 1; i++)
    {
        bool j = checking(str1[i]);
        bool k = checking(str1[i+1]);
        if (!k)
        {
            i++;
            continue;
        }
        else if (!j) continue;
        else 
        {
            string temp = "";
            temp += tolower(str1[i]);
            temp += tolower(str1[i+1]);
            J1.insert(temp);
            uni.insert(temp);
        }
    }
    
    for (int i = 0; i < str2.length() - 1; i++)
    {
        bool j = checking(str2[i]);
        bool k = checking(str2[i+1]);
        if (!k)
        {
            i++;
            continue;
        }
        else if (!j) continue;
        else 
        {
            string temp = "";
            temp += tolower(str2[i]);
            temp += tolower(str2[i+1]);
            J2.insert(temp);
            uni.insert(temp);
        }
    }
    
    for (string t : uni) {
        int t1 = J1.count(t);
        int t2 = J2.count(t);
        if (t1 != 0 && t2 != 0) {
            INTERSEC += min(t1, t2);
            UNI += max(t1, t2);
        } else {
            UNI += t1 + t2;
        }
    }
    
    int answer = 65536;
    if (UNI == 0) return answer;
    else {
        double ans = (double)INTERSEC / UNI;      
        return answer * ans;
    }
}