#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

set <string> s;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    char c = words[0].back();
    s.insert(words[0]);
    
    for (int i = 1; i < words.size(); i++)
    {
        if (words[i][0] == c && s.find(words[i]) == s.end()) 
        {
            c = words[i].back();
            s.insert(words[i]);
        }
        else
        {
            answer.push_back((i%n) + 1);
            answer.push_back((i/n) + 1);
            break;
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}