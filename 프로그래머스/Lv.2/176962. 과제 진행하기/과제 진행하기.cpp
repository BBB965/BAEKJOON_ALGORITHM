#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(const vector<string> &a, const vector<string> &b) {
    return a[1] < b[1];
}

vector<pair<string, int>> stop_hw;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), compare);
    
    for (int i = 0; i < plans.size(); i++) {
        if (i == plans.size() - 1) {
            answer.push_back(plans[i][0]);
        }
        else {
            int h = stoi(plans[i][1].substr(0,2));
            int m = stoi(plans[i][1].substr(3,2));
            int pt = stoi(plans[i][2]);
            
            int nh = stoi(plans[i+1][1].substr(0,2));
            int nm = stoi(plans[i+1][1].substr(3,2));
            
            int itv = h * 60 + m + pt - nh * 60 - nm;
            
            //cout << h << " " << m << " " << itv << '\n';
            
            if (itv > 0) {
                stop_hw.push_back({plans[i][0], itv});
            }
            else if (itv == 0) {
                answer.push_back(plans[i][0]);
            } 
            else {
                answer.push_back(plans[i][0]);
                if (!stop_hw.empty()) {
                    while (!stop_hw.empty() && itv < 0) {
                        pair<string, int> temp = stop_hw.back();
                        stop_hw.pop_back();
                        if (temp.second <= abs(itv)) {
                            itv += temp.second;
                            answer.push_back(temp.first);
                        } else {
                            temp.second += itv;
                            itv = 0;
                            stop_hw.push_back(temp);
                        }
                    }
                }
            }
        }
    }
    
    while (!stop_hw.empty()) {
        pair<string, int> temp = stop_hw.back();
        stop_hw.pop_back();
        answer.push_back(temp.first);
    }
    
    return answer;
}