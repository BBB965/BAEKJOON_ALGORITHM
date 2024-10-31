#include <string>
#include <vector>

using namespace std;

string returnUV(string w) {
    if (w == "") return "";
    
    string u = "";
    string v = "";
    int cnt = 0;
    bool split = false;
    
    for (char c : w) {
        if (c == '(') cnt++;
        else cnt--;
        
        if (!split) u += c;
        else v += c;
        
        if (cnt == 0) split = true;
    }
    
    if (u[0] == '(') return u + returnUV(v);
    
    string uv = "";
    
    for (int i = 1; i < u.length() - 1; i++) {
        if (u[i] == '(') uv += ')';
        else uv += '(';
    }
    
    return '(' + returnUV(v) + ')' + uv;
}

string solution(string p) {
    return returnUV(p);
}
