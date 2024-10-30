#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int ans = number.length() - k;
    int sIdx = 0;
    
    for (int i = 0; i < ans; i++) {
        char num = number[sIdx];
        int maxIdx = sIdx;
        for (int j = sIdx + 1; j <= k + i; j++) {
            if (num < number[j]) {
                num = number[j];
                maxIdx = j;
            }
        }
        sIdx = maxIdx + 1;
        answer += num;
    }
    return answer;
}