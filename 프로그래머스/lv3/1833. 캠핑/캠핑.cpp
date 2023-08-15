#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end());
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <n; j++)
        {
            bool checked = false;
            if (data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            for (int k = i + 1; k < j; k++)
            {
                int minx = min(data[i][0], data[j][0]);
                int maxx = max(data[i][0], data[j][0]);
                int miny = min(data[i][1], data[j][1]);
                int maxy = max(data[i][1], data[j][1]);
                if (data[k][0] > minx && data[k][0] < maxx && data[k][1] > miny && data[k][1] < maxy)
                {
                    checked = true;
                    break;
                }
            }
            if (!checked) answer++;
        }
    }
    
    return answer;
}