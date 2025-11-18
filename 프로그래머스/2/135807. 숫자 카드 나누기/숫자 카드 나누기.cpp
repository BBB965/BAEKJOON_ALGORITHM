#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int sA = sqrt(arrayA[0]);
    int sB = sqrt(arrayB[0]);
    
    for (int i = 1; i <= sA; i++) {
        int ri = arrayA[0]/i;
        bool findi = true;
        bool findri = true;
        
        for (int n : arrayA) {
            if (findi && n%i != 0) findi = false;
            if (findri && n%ri != 0) findri = false;
            if (!findi && !findri) break;
        }
        if (!findi && !findri) continue;
        
        for (int n : arrayB) {
            if (findi && n%i == 0) findi = false;
            if (findri && n%ri == 0) findri = false;
            if (!findi && !findri) break;            
        }
        
        if (findi) answer = max(answer, i);
        if (findri) answer = max(answer, ri);
    }

    for (int i = 1; i <= sB; i++) {
        int ri = arrayB[0]/i;
        bool findi = true;
        bool findri = true;
        
        for (int n : arrayB) {
            if (findi && n%i != 0) findi = false;
            if (findri && n%ri != 0) findri = false;
            if (!findi && !findri) break;
        }
        if (!findi && !findri) continue;
        
        for (int n : arrayA) {
            if (findi && n%i == 0) findi = false;
            if (findri && n%ri == 0) findri = false;
            if (!findi && !findri) break;            
        }
        
        if (findi) answer = max(answer, i);
        if (findri) answer = max(answer, ri);
    }
    
    return answer;
}