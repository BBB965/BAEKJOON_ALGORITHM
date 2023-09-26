#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 110을 모두 구하고, 마지막 0 뒤에 넣기
// 만약 0이 없다면 앞에 놓기
vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (string str : s)
    {
        if (str.length() <= 3)
        {
            answer.push_back(str);
            continue;
        }
        string t = "";
        int cnt = 0;
        for (int i = 0; i < str.length(); i++)
        {
            t += str[i];
            if (t.length() >= 3)
            {
                if (t.substr(t.length() - 3, 3) == "110")
                {
                    cnt++;
                    t.erase(t.length() - 3 ,3);
                }
            }
        }
        
        for (int i = t.length() -1; i >= 0; i--)
            if (t[i] == '0')
            {
                while (cnt--) t.insert(i+1, "110");
                break;
            }
        
        if (cnt > 0)
            while (cnt--) t.insert(0, "110");
        
        answer.push_back(t);
    }
    
    return answer;
}