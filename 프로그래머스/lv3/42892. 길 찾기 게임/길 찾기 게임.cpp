#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector <int> node[100001];
vector <int> post;
vector <int> pre;
vector <vector<int>> answer;

void find_post(int N)
{
    for (int i = 0; i < node[N].size(); i++)
    {
        find_post(node[N][i]);
        post.push_back(node[N][i]);
    }
}

void find_pre(int N)
{
    pre.push_back(N);
    for (int i = 0; i < node[N].size(); i++)
        find_pre(node[N][i]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i+1);
    
    sort(nodeinfo.begin(), nodeinfo.end());
    int topnode = 0;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        vector <int> r = nodeinfo[i];
        vector <int> l = nodeinfo[i];
        for (int ll = i - 1; ll >= 0; ll--)
        {
            if (l[1] < nodeinfo[ll][1]) 
            {
                l = nodeinfo[ll];
                break;
            }
        }
        for (int rr = i+1; rr < nodeinfo.size(); rr++)
        {
            if (r[1] < nodeinfo[rr][1])
            {
                r = nodeinfo[rr];
                break;
            }
        }
        //cout << nodeinfo[i][2] << " " << l[2] << " " << r[2] << '\n';
        
        if (r[1] == nodeinfo[i][1])
        {
            if (l[1] == nodeinfo[i][1]) topnode = nodeinfo[i][2];
            else node[l[2]].push_back(nodeinfo[i][2]);
        }
        else
        {
            if (l[1] == nodeinfo[i][1]) node[r[2]].push_back(nodeinfo[i][2]);
            else
            {
                if (l[1] < r[1]) node[l[2]].push_back(nodeinfo[i][2]);
                else node[r[2]].push_back(nodeinfo[i][2]);
            }
        }
    }
    
    find_pre(topnode);
    find_post(topnode);
    post.push_back(topnode);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}