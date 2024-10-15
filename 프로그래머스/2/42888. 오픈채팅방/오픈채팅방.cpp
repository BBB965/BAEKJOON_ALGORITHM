#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string,string> id_nick;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    
    vector<string> result;
    
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,int>> ans;
    
    for (string r : record) {
        vector tmp = split(r, ' ');
        if (tmp[0] == "Enter") {
            ans.push_back({tmp[1], 0});
            if(id_nick.find(tmp[1]) != id_nick.end()) {
                id_nick[tmp[1]] = tmp[2];
            } else {
                id_nick.insert(make_pair(tmp[1], tmp[2]));
            }
        } else if(tmp[0] == "Leave") {
            ans.push_back({tmp[1], 1});
        } else {
            id_nick[tmp[1]] = tmp[2];
        }
    }
    
    for(pair<string,int> a : ans) {
        if (a.second == 0) answer.push_back(id_nick[a.first] + "님이 들어왔습니다.");
        else answer.push_back(id_nick[a.first] + "님이 나갔습니다."); 
    }
    
    return answer;
}