#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long sy = -1e14, sx = -1e14, ey = 1e14, ex = 1e14;
double ax, ay, a, bx, by, b;
double x ,y;

vector <pair<long long,long long>> star;
vector<string> answer;

vector<string> solution(vector<vector<int>> line) {
    for (int i = 0; i < line.size() - 1; i++)
    {
        for (int j = i+1; j < line.size(); j++)
        {
            ax = (double) line[i][0];
            ay = (double) line[i][1];
            a = (double) line[i][2];
            
            bx = (double) line[j][0];
            by = (double) line[j][1];
            b = (double) line[j][2];
            
            double m = ax * by - ay * bx;
            double n = ay * b - a * by;
            double o = a * bx - ax * b;
            
            if (m == 0) continue;
            x = n / m;
            y = o / m;
            if (x - (long long) x != 0 || y - (long long) y != 0) continue;
            star.push_back({(long long) x,(long long) y});
            
            sx = max(sx, (long long) x);
            sy = max(sy, (long long) y);
            ex = min(ex, (long long) x);
            ey = min(ey, (long long) y);
        }
    }

    for (long long i = sy; i >= ey; i--)
    {
        string temp = "";
        for (long long j = ex; j <= sx; j++) temp += '.';
        answer.push_back(temp);
    }
    
    for (int i = 0; i < star.size(); i++)
        answer[sy - star[i].second][star[i].first - ex] = '*';
    
    return answer;
}