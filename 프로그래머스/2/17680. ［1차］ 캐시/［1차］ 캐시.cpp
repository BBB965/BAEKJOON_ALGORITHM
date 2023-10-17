#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map <string, int> cache;

string change_str(string str) {
    string ret = "";
    for (char c : str) {
        ret += tolower(c);
    }
    return ret;
}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int N = cities.size();
    
    if (cacheSize == 0) return N * 5;
    
    for (int i = 0; i < N; i++)
    {
        string tc = change_str(cities[i]);
        
        if (cache.find(tc) != cache.end()) {
            cache[tc] = i;
            answer += 1;
        }
        
        else {
            if (cache.size() < cacheSize) {
                cache.insert({tc, i});
            }
            else {
                int t = 1e9;
                string city = "";
                for (auto& c : cache) {
                    if (c.second < t) {
                        city = c.first;
                        t = c.second;
                    }
                }
                cache.erase(city);
                cache.insert({tc, i});
            }
            answer += 5;
        }
    }
    
    return answer;
}