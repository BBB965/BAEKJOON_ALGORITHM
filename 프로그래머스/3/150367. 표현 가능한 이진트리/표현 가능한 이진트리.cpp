#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isTree(vector <int> t, int p, int l) {
    
    if (t[p-1] == 0 && (t[p-1-l] == 1 || t[p-1+l] == 1)) return false;
    else {
        if (l == 1) return true;
        else if (!isTree(t, p+l, l/2) || !isTree(t, p-l, l/2)) return false;
        else return true;
    }
}

bool changeBin(long long ll) {
    vector <int> vect;
    int N = 1;
    
    while (ll > 0) {
        vect.push_back(ll%2);
        ll /= 2;
    }
    
    while ((N-1) < vect.size()) {
        N *= 2;
    }
    
    N -= vect.size() + 1;
    while (N--) vect.push_back(0);
    N = (vect.size() / 2) + 1;
    return isTree(vect, N, N/2);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long num : numbers) {
        
        if (num == 1) {
            answer.push_back(1);
            continue;
        }
        
        if (changeBin(num)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}