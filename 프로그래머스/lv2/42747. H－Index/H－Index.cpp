#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = -1;
    int cnt = citations.size();
    sort(citations.begin(), citations.end());
    int mxx = citations[cnt-1];
    for (int i = mxx; i > -1; i--)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (citations[j] >= i && cnt - j >= i)
            {
                answer = i;
                break;
            }
        }
        if (answer != -1) break;
    }
    
    return answer;
}