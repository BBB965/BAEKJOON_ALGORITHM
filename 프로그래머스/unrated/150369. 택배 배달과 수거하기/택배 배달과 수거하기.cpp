#include <string>
#include <vector>
using namespace std;

int box[2] = {0,0};

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] > 0 || pickups[i] > 0)
        {
            int cnt = 0;
            while (box[0] < deliveries[i] || box[1] < pickups[i])
            {
                cnt++;
                box[0] += cap;
                box[1] += cap;
            }
            box[0] -= deliveries[i];
            box[1] -= pickups[i];
            answer += cnt * (i + 1) * 2;
        }
    }
    return answer;
}