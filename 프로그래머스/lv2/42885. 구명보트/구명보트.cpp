#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int p = people.size() - 1;
    int answer = p + 1;
    sort(people.begin(), people.end());
    int s = 0;
    while (s < p)
    {
        if (people[s] + people[p] <= limit)
        {
            answer--;
            s++;
            p--;
        }
        else p--;
    }
    
    return answer;
}