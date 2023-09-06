#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[101] = {0,};
vector <pair<int,int>> vect[101];

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;
    for (vector <int> cost : costs)
    {
    	vect[cost[0]].push_back({cost[1], cost[2]});
        vect[cost[1]].push_back({cost[0], cost[2]});
    }
    
    priority_queue<pair<int,int>> pq;
    
    visited[0] = true;
    for (int i = 0; i < vect[0].size(); i++)
    {
    	int nxt = vect[0][i].first;
        int nCost = vect[0][i].second;
        pq.push({-nCost, nxt});
    }
    
    while (!pq.empty())
    {
    	int dist =  -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (!visited[cur])
        {
        	visited[cur] = true;
            answer += dist;
            
            for (int i = 0; i < vect[cur].size(); i++)
            {
            	int nxt = vect[cur][i].first;
                int nCost = vect[cur][i].second;
                if (!visited[nxt]) pq.push({-nCost,nxt});
            }
        }
    }
    return answer;
}