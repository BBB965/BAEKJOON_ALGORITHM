// #include <string>
// #include <vector>
// #include <map>
// using namespace std;

// map<string, int> jewel;
// map<string, int> jewel1;

// vector<int> solution(vector<string> gems) {
//     vector<int> answer;
    
//     int N = gems.size();
    
//     for (string gem : gems)
//     {
//         if (jewel.find(gem) != jewel.end()) 
//         {
//             jewel[gem]++;
//             jewel1[gem]++;
//         }
//         else 
//         {
//             jewel.insert({gem, 1});
//             jewel1.insert({gem, 1});
//         }
//     }
    
//     int s1 = 0, s2 = 0;
//     int e1 = N-1, e2 = N-1;
    
//     while (s1 < e1)
//     {
//         if (jewel[gems[e1]] > 1)
//         {
//             jewel[gems[e1]]--;
//             e1--;
//         }
//         else break; 
//     }
    
//     while (s1 < e1)
//     {
//         if (jewel[gems[s1]] > 1)
//         {
//             jewel[gems[s1]]--;
//             s1++;
//         }
//         else break;
//     }
    
//     while (s2 < e2)
//     {
//         if (jewel1[gems[s2]] > 1)
//         {
//             jewel1[gems[s2]]--;
//             s2++;
//         }
//         else break; 
//     }
    
//     while (s2 < e2)
//     {
//         if (jewel1[gems[e2]] > 1)
//         {
//             jewel1[gems[e2]]--;
//             e2--;
//         }
//         else break;
//     }
    
//     if ((e2 - s2) < (e1 - s1))
//     {
//         answer.push_back(s2+1);
//         answer.push_back(e2+1);
//     }
//     else
//     {
//         answer.push_back(s1+1);
//         answer.push_back(e1+1);
//     }
    
//     return answer;
// }

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> gemCount;
    set<string> gemTypes;
    
    int left = 0;
    int minLen = 10000000;
    
    for (string gem : gems) {
        gemTypes.insert(gem);
    }
    
    int start = 0;
    
    for (int right = 0; right < gems.size(); right++) {
        gemCount[gems[right]]++;
        
        while (gemCount.size() == gemTypes.size()) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }
            
            gemCount[gems[left]]--;
            
            if (gemCount[gems[left]] == 0) {
                gemCount.erase(gems[left]);
            }
            
            left++;
        }
    }
    
    answer.push_back(start + 1);
    answer.push_back(start + minLen + 1);
    
    return answer;
}