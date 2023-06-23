#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> a) {
    int answer = 0;
    vector<int> cnt(a.size());
    if (a.size() < 2) return 0;
    else
    {
        
        for (int i = 0; i < a.size(); i++) cnt[a[i]]++;
        for (int i = 0; i < cnt.size(); i++)
        {
            if (cnt[i] <= answer) continue;
            int temp = 0;
            for (int j = 0; j < a.size() - 1; j++)
            {
                if ((a[j] == i or a[j+1] == i) && a[j] != a[j+1])
                {
                    temp++;
                    j++;
                }
            }
            answer = max(answer, temp);
        }
        return answer * 2;
    }
}