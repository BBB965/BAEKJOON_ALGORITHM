#include <string>
#include <vector>
#include <iostream>
using namespace std;

string answer = "";
int tm[24][60] = {0,};
int ah = 0, am = 0, itv, N, M;

bool canride(int h, int m)
{
    bool flag = true;
    
    int sh = 9;
    int sm = 0;
    int bus = 0;
    int idx = 0;
    
    bool stop = false;
    for (int x = 0; x < 24; x++)
    {
        if (stop) break;
        for (int y = 0; y < 60; y++)
        {
            if (stop) break;
            bus += tm[x][y];
            while (bus >= M)
            {
                bus -= M;
                idx++;
                sm += itv;
                if (sm >= 60)
                {
                    sh++;
                    sm -= 60;
                }
                if (idx >= N) break;
            }
            
            if (x == sh && y == sm)
            {
                bus = 0;
                idx++;
                sm += itv;
                if (sm >= 60)
                {
                    sh++;
                    sm -= 60;
                }
            }
            
            if (idx >= N)
            {
                if (bus > 0 && x * 60 + y <= h * 60 + m) flag = false;
                if (x * 60 + y < h * 60 + m) flag = false;
                stop = true;
                break;
            }
            if (x * 60 + y > h * 60 + m) stop = true;
        }
    }
    return flag;
}

string solution(int n, int t, int m, vector<string> timetable) {
    
    N = n;
    itv = t;
    M = m;
    
    for (int i = 0; i < timetable.size(); i++)
    {
        int h = stoi(timetable[i].substr(0,2));
        int mm = stoi(timetable[i].substr(3,2));
        tm[h][mm]++;
    }
    bool flag = false;
    for (int x = 0; x < 24; x++)
    {
        if (flag) break;
        for (int y = 0; y < 60; y++)
        {
            tm[x][y]++;
            if (canride(x,y))
            {
                ah = x; am = y;
                tm[x][y]--;
            }
            else
            {
                flag = true;
                break;
            }
        }
    }
    string hour = ah >= 10 ? to_string(ah) : '0' + to_string(ah);
    string minute = am >= 10 ? to_string(am) : '0' + to_string(am);
    answer = hour + ':' + minute;
    return answer;
}