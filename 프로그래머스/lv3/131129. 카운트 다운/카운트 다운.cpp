#include <string>
#include <vector>

using namespace std;
vector <pair<int,int>> dart(100010);
vector<int> solution(int target) {
    vector<int> answer;
    
    for (int i = 1; i <= 20; i++) dart[i] = {1,1};
    
    for (int i = 21; i <= 40; i++)
    {
        if (i%2 == 0) dart[i] = {1,0};
        else if (i%3 == 0) dart[i] = {1,0};
        else dart[i] = {dart[i-20].first + 1, dart[i-20].second + 1};
    }
    
    for (int i = 41; i < 50; i++)
    {
        if (i%3 == 0) dart[i] = {1,0};
        else dart[i] = {dart[i-20].first + 1, dart[i-20].second + 1};
    }
    dart[50] = {1,1};
    for (int i = 51; i < 60; i++)
    {
        if (i%3 == 0) dart[i] = {1,0};
        else dart[i] = {dart[i-50].first + 1, dart[i-50].second + 1};
    }
    dart[60] = {1,0};
    
    if (target > 60)
    {
        for (int i = 61; i <= target; i++)
        {
            dart[i] = {dart[i-50].first + 1, dart[i-50].second + 1};
            if (dart[i].first > dart[i-60].first + 1)
                dart[i] = {dart[i-60].first + 1, dart[i-60].second};
        }
    }
    
    answer.push_back(dart[target].first);
    answer.push_back(dart[target].second);
    return answer;
}