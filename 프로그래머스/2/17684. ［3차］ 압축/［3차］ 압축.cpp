#include <string>
#include <vector>
#include <map>
using namespace std;

map <string, int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    int index = 1;
    for (; index <= 26; index++) {
        char tmp = (char) (64 + index);
        string key(1, tmp);
        m.insert({key, index});
    }
    int i = 0;
    string str = msg.substr(i,1);
    int prestr = 0;
    while (i < msg.size()) {
        if (m.find(str) != m.end()) {
            prestr = m[str];
            i++;
            str += msg.substr(i, 1);
        }
        else {
            answer.push_back(prestr);
            m.insert({str, index});
            index++;
            str = msg.substr(i, 1);
        }
    }
    if (m.find(str) != m.end()) answer.push_back(m[str]);
    else answer.push_back(prestr);
    return answer;
}