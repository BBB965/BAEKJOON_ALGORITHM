#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0;
    int num = 0;
    vector <int> lotto;
    set <int> win_num;
    for (int i = 0; i < 6; i++)
    {
        win_num.insert(win_nums[i]);
        if (lottos[i] == 0) zero++;
        else lotto.push_back(lottos[i]);
    }
    for (int i = 0; i < lotto.size(); i++)
        if (win_num.find(lotto[i]) != win_num.end()) num++;
    
    answer.push_back(num + zero >= 2 ? 7 - num - zero : 6);
    answer.push_back(num >= 2 ? 7 - num : 6);
    
    return answer;
}