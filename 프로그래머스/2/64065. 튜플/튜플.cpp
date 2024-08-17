#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checked[1000001] = {0,};
bool comp (vector<int> a, vector<int> b) {
    if (a.size() < b.size()) return true;
    else return false;
}

vector<vector<int>> numbers;

vector<int> solution(string s) {
    vector<int> answer;
    
    int n = 1;
    int m = s.length();
    
    while (n < m) {
        if (s[n] == '{') {
            vector<int> tmp = {};
            string num = "";
            while (s[n] != '}') {
                n++;
                if (s[n] == ',') {
                    tmp.push_back(stoi(num));
                    num = "";
                } else {
                    num += s[n];
                }
            }
            tmp.push_back(stoi(num));
            num = "";
            numbers.push_back(tmp);
        } else {
            n++;
        }
    }
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for (vector<int> v : numbers) {
        for (int i : v) {
            if (!checked[i]) {
                checked[i] = 1;
                answer.push_back(i);
                break;
            }
        }
    }
    
    
    return answer;
}