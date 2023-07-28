#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int answer = 0;
bool used[10] = {0,};
vector <vector<string>> s;
vector <string> temp;
vector <string> user;
vector <string> banned;

void find_(int idx)
{
    if (idx == banned.size())
    {
        s.push_back(temp);
        return;
    }
    
    for (int i = 0; i < user.size(); i++)
    {
        if (used[i]) continue;
        if (user[i].size() != banned[idx].size()) continue;
        bool flag = true;
        for (int j = 0; j < user[i].size(); j++)
        {
            if (banned[idx][j] == '*') continue;
            if (user[i][j] != banned[idx][j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            used[i] = 1;
            temp.push_back(user[i]);
            find_(idx+1);
            temp.pop_back();
            used[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    user = user_id;
    banned = banned_id;
    
    find_(0);
    for (int i = 0; i < s.size(); i++)
        sort(s[i].begin(), s[i].end());
    sort(s.begin(), s.end());
    set <vector<string>> v(s.begin(), s.end());
    answer = v.size();
    
    return answer;
}