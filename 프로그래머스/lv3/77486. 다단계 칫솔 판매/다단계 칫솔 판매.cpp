#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map <string, int> salesman;
vector<pair<int,int>> money(10100);

void dadan(int idx, int price)
{
    if (price == 0) return;
    if (idx == 0) return;
    int temp = price * 0.1;
    money[idx].second += (price - temp);
    dadan(money[idx].first, temp);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    money[0] = {-1,0};
    
    int cnt = enroll.size();
    for (int i = 1; i <= cnt; i++)
    {
        salesman[enroll[i-1]] = i;
        if (referral[i-1] == "-") money[i] = {0,0};
        else
        {
            int idx = salesman[referral[i-1]];
            money[i] = {idx,0};
        }
    }
    for (int i = 0; i < seller.size();i++)
        dadan(salesman[seller[i]], amount[i] * 100);
    
    for (int i = 1; i <= cnt; i++)
        answer.push_back(money[i].second);
    
    return answer;
}