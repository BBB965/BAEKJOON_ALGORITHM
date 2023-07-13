#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map <string, int> result;

void comb(string dish, int idx, string cc)
{
    if (cc.length() >= 2)
    {
        if (result.find(cc) != result.end())
            result[cc]++;
        else result.insert({cc, 1});
    }
    
    for (int i = idx + 1; i < dish.size(); i++)
        comb(dish, i, cc + dish[i]);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        comb(orders[i], -1, "");
    }
    vector <pair<int, string>> ans[21];

    for (auto it = result.begin(); it != result.end(); it++)
    {
        int temp = it->second;
        string str = it->first;
        if (temp >= 2) ans[str.length()].push_back({-temp, str});
    }
    
    for (int i = 0; i < course.size(); i++)
    {
        int idx = course[i];
        if (ans[idx].size() == 0) continue;
        sort(ans[idx].begin(), ans[idx].end());
        answer.push_back(ans[idx][0].second);
        //if (ans[idx].size() == 1) continue;
        for (int j = 1; j < ans[idx].size(); j++)
        {
            if (ans[idx][0].first == ans[idx][j].first) answer.push_back(ans[idx][j].second);
            else break;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}