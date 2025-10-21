#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map <char, int> skills;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int idx = 0;
    for (char c : skill) {
        skills.insert({c,idx});
        idx++;
    }
    
    for (string st : skill_trees) {
        int cnt = st.length();
        idx = skills.find(st[0]) != skills.end() ? skills[st[0]] : -1;
        if (idx > 0) continue;
        
        bool isP = true;
        
        for (int i = 1; i < cnt; i++) {
            int n = skills.find(st[i]) != skills.end() ? skills[st[i]] : -1;
            if (n == -1) continue;
            else if (n - idx == 1) idx = n;
            else {
                isP = false;
                break;
            }
        }
        if (isP) answer++; 
    }
    
    return answer;
}