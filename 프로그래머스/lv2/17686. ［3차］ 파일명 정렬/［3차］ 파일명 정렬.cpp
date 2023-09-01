#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct info {
    string HEAD;
    int NUMBER;
    string file;
};
vector <info> vect;
vector <string> answer;

bool cmp (const info& a, const info& b){
    if (a.HEAD == b.HEAD) return a.NUMBER < b.NUMBER;
    else return a.HEAD < b.HEAD;
}

vector<string> solution(vector<string> files) {
    
    for (int i = 0; i < files.size(); i++)
    {
        int idx = 0;
        string H = "";
        while (idx < files[i].size())
        {
            if (files[i][idx] >= '0' && files[i][idx] <= '9') break;
            else H += tolower(files[i][idx]);
            idx++;
        }
        string N = "";
        while (idx < files[i].size())
        {
            if (files[i][idx] < '0' || files[i][idx] > '9') break;
            else N += files[i][idx];
            idx++;
        }
        int n = stoi(N);
        vect.push_back({H, n, files[i]});
    }
    
    stable_sort(vect.begin(), vect.end(), cmp);
    for (int i = 0; i < vect.size(); i++)
        answer.push_back(vect[i].file);
    
    return answer;
}