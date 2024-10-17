#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> c;
int m1 = 0, m2 = 0;
bool checked[101] = {0,};

bool cmp (vector<int> a, vector<int> b) {
    return a.size() > b.size();
}

int solution(vector<int> cards) {
    for (int i = 0; i < cards.size(); i++) {
        int s = cards[i] - 1;
        if (checked[s]) continue;
        vector<int> tmp = {};
        while (!checked[s]) {
            checked[s] = 1;
            tmp.push_back(s);
            s = cards[s] - 1;
        }
        c.push_back(tmp);
    }
    
    if (c.size() == 1) return 0;
    else {
        sort(c.begin(), c.end(),cmp);
        return c[0].size() * c[1].size();
    }
}