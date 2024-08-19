#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "0";
    int c = t * m;
    for (int i = 0; i < c; i++) {
        int k = i;
        string j = "";
        while (k > 0) {
            int a = k % n;
            k /= n;
            if (a > 9) {
                char tmp = 'A' + a - 10;
                j = tmp + j;
            } else {
                j = to_string(a) + j;
            }
        }
        str += j;
    }
    
    for (int i = 0; i < t; i++) {
        answer += str[i*m + p - 1];
    }
    
    return answer;
}