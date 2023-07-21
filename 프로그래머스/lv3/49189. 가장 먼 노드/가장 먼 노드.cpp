#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int M = 0;
bool node[20001];
int dist[50001];
vector<int> vect[20001];
queue <int> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        vect[edge[i][0]].push_back(edge[i][1]);
        vect[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    node[1] = 1;
    while(!q.empty())
    {
        int qs = q.size();
        M++;
        while (qs--)
        {
            int num = q.front();
            q.pop();
            for (int i = 0; i < vect[num].size(); i++)
            {
                if (node[vect[num][i]]) continue;
                node[vect[num][i]] = 1;
                q.push(vect[num][i]);
                dist[M]++;
            }
        }
    }
    answer = dist[M-1];
    return answer;
}