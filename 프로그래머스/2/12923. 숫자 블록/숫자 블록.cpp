#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 1);
    if (begin == 1) answer[0] = 0;
    for (long long j = begin; j <= end; j++) {
        long long rt = sqrt(j);
        for (long long i = 2; i <= rt; i++) {
            if (j%i == 0) {
                if (answer[j - begin] > i && answer[j - begin] > j/i) break;
                if (answer[j-begin] < i) answer[j - begin] = i;
                if (j/i <= 10000000 && answer[j-begin] < j/i) answer[j-begin] = j/i;
            }
        }
    }
    return answer;
}