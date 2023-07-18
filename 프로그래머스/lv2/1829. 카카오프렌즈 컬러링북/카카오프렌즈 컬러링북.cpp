#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int tcnt, color;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    queue <pair<int,int>> q;
    
    bool checked[101][101] = {0,};
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int y = 0; y < m;y++)
    {
        for (int x = 0; x < n;x++)
        {
            if (picture[y][x] == 0 || checked[y][x]) continue;
            checked[y][x] = 1;
            tcnt = 1;
            color = picture[y][x];
            
            q.push({y,x});
            number_of_area++;
            
            while (!q.empty())
            {
                pair<int,int> temp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int ny = temp.first + dy[i];
                    int nx = temp.second + dx[i];
                    if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
                    if (checked[ny][nx] == 1) continue;
                    if (picture[ny][nx] != color) continue;
                    tcnt++;
                    checked[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, tcnt);
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}