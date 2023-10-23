#include <string>
#include <vector>
#include <queue>
using namespace std;

vector <int> answer;
vector <int> r[100010];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    for (vector<int> v : roads) {
        r[v[0]].push_back(v[1]);
        r[v[1]].push_back(v[0]);
    }
    
    for (int s : sources) {
        bool visited[1000010] = {0,};
        queue<pair<int,int>> q;
        
        visited[s] = 1;
        q.push({s,0});
        int dist = -1;
        
        while (!q.empty()) {
            pair<int,int> t = q.front();
            q.pop();
            
            if (t.first == destination) {
                dist = t.second;
                break;
            }
            
            for (int i = 0; i < r[t.first].size(); i++) {
                if (visited[r[t.first][i]]) continue;
                visited[r[t.first][i]] = 1;
                q.push({r[t.first][i], t.second+1});
            }
        }
        answer.push_back(dist);
    }
    
    return answer;
}