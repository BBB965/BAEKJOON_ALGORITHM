#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map <string, int> um;
set<string> gem;
int sIdx = 0, eIdx = 0;

vector<int> solution(vector<string> gems) {
    
    eIdx = gems.size() - 1;
    for (string str : gems) {
        gem.insert(str);
    }
    
    int N = gem.size();
    int st = 0, et = 0;
    for (int i = 0; i < gems.size(); i++) {
        um[gems[i]]++;
       // cout << gems[i] << " " << um[gems[i]] << '\n';
        if (um[gems[i]] > 1) {
            while (st < i && um[gems[st]] > 1){
               //cout << gems[i] << " " << um[gems[i]] << '\n';
                um[gems[st]]--; st++;
            }
        }
        if ((um.size() == N) && ((eIdx - sIdx) > (i - st))) {
            //cout << i << " " << st << '\n';
            eIdx = i;
            sIdx = st;
        }
    }
    
    vector<int> answer;
    answer.push_back(sIdx + 1);
    answer.push_back(eIdx + 1);
    return answer;
}