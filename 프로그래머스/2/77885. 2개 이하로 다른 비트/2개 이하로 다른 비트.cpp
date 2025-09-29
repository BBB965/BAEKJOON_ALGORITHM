#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> bit(long long N) {
    vector <int> rt;
    bool checked = false;
    while (N > 0) {
        rt.push_back(N%2);
        N /= 2;
    }
    rt.push_back(0);
    
    for (int i  = 0; i < rt.size() - 1; i++) {
        if (rt[i] == 1 && rt[i+1] == 0) {
            rt[i] = 0;
            rt[i+1] = 1;
            break;
        }
    }
    
    return rt;
}

long long changed(vector<int> bits) {
    long long rt = 0;
    long long b = 1;
    for (int i : bits) {
        rt += i * b;
        b *= 2;
    }
    return rt;
}


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long ll : numbers) {
        long long N = ll;
        if (N%2 == 0) answer.push_back(ll + 1);
        else {
            vector<int> numBits = bit(N);
            answer.push_back(changed(numBits));
        }
    }
    return answer;
}