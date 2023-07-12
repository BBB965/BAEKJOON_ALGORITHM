#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++)
    {
        bool flag = 0;
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (places[i][y][x] == 'P')
                {
                    bool checked[5][5] = {0,};
                    checked[y][x] = 1;
                    queue <pair<pair<int,int>,int>> q;
                    q.push({{y,x},0});
                    while (!q.empty())
                    {
                        pair<pair<int,int>,int> temp = q.front();
                        q.pop();
                        if (temp.second == 2) continue;
                        for (int j = 0; j < 4; j++)
                        {
                            int ny = temp.first.first + dy[j];
                            int nx = temp.first.second + dx[j];
                            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
                            if (checked[ny][nx] || places[i][ny][nx] == 'X') continue;
                            if (places[i][ny][nx] == 'P')
                            {
                                flag = 1;
                                break;
                            }
                            checked[ny][nx] = 1;
                            q.push({{ny,nx}, temp.second + 1});
                        }
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}