#include <string>
#include <vector>

using namespace std;

int N, M, subs = 0, sales = 0;
vector<vector<int>> user;
vector <int> emoticon;
int money[110] = {0,};
int min_sale = 40;

void min_sales()
{
    for (int i = 0; i < N; i++)
    {
        if (min_sale > user[i][0]) min_sale = user[i][0];
    }
    if (min_sale % 10 == 0) min_sale /= 10;
    else min_sale = min_sale/10 + 1;
}

void find_max(int now)
{
    if (now == M)
    {
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < N; i++)
        {
            if (money[i] >= user[i][1]) t1++;
            else t2 += money[i];
        }
        if (subs == t1) sales = max(sales, t2);
        else if (subs < t1) 
        {
            subs = t1;
            sales = t2;
        }
        return;
    }
    
    for (int i = min_sale; i <= 4; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (user[j][0] > i * 10) continue;
            else money[j] += emoticon[now] * 0.1 * (10 - i);
        }
        find_max(now+1);
        for (int j = 0; j < N; j++)
        {
            if (user[j][0] > i * 10) continue;
            else money[j] -= emoticon[now] * 0.1 * (10 - i);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    N = users.size();
    M = emoticons.size();
    user = users;
    emoticon = emoticons;
    min_sales();
    find_max(0);
    answer.push_back(subs);
    answer.push_back(sales);
    return answer;
}