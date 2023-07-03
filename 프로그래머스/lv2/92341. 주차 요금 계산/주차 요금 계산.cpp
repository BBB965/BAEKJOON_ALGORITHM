#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map <string, int> checked;
map <string, int> fee;
int ended = 23 * 60 + 59;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++)
    {
        string num = records[i].substr(5,6);
        int hour = stoi(records[i].substr(0,2));
        int minute = stoi(records[i].substr(3,5));
        int timing = hour * 60 + minute;

        if (checked.find(num) != checked.end())
        {
             int temp = timing - checked[num];
             fee[num] += temp;
             checked.erase(num);
        }
        else
        {
            if (fee.find(num) != fee.end()) fee.insert({num, 0});
            checked.insert({num,timing});
        }
    }
    for (auto iter : checked)
    {
        string num = iter.first;
        int temp = ended - checked[num];
        fee[num] += temp;
    }
    for (auto iter : fee)
    {
        int accum = iter.second - fees[0];
        int money = fees[1];
        while (accum > 0)
        {
            money += fees[3];
            accum -= fees[2];
        }
        answer.push_back(money);
    }
    return answer;
}