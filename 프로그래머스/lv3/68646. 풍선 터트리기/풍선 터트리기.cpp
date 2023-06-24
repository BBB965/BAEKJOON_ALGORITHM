#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int min_a = a[0];
    int idx = 0;
    if (a.size() == 1) return 1;
    else 
    {
        while (idx < a.size())
        {
            if (a[idx] <= min_a)
            {
                min_a = a[idx];
                answer++;
            }
            idx++;
        }
        int temp = a[idx - 1];
        while (idx--)
        {
            if (a[idx] == min_a) break;
            else if (a[idx] <= temp)
            {
                temp = a[idx];
                answer++;
            }
        }
        return answer;
    }
}