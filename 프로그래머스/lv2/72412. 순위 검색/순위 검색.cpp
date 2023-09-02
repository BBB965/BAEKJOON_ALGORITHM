#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map <string, int> m;
int l,o,c,sf,score;
vector <int> vect[4][3][3][3];

void make_map()
{
    m.insert({"-", 0});
    
    m.insert({"cpp", 1});
    m.insert({"java", 2});
    m.insert({"python", 3});
    
    m.insert({"backend", 1});
    m.insert({"frontend", 2});
    
    m.insert({"junior", 1});
    m.insert({"senior", 2});
    
    m.insert({"chicken", 1});
    m.insert({"pizza", 2});
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    make_map();
    
    for (string i : info)
    {
        istringstream iss(i);
        string s[5];
        iss >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
        
        l = m.find(s[0])->second;
        o = m.find(s[1])->second;
        c = m.find(s[2])->second;
        sf = m.find(s[3])->second;
        score = stoi(s[4]);
        
        vect[l][o][c][sf].push_back(score);
    }
    
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 3; j++)
            for (int k = 1; k < 3; k++)
                for (int l = 1; l < 3; l++)
                    sort(vect[i][j][k][l].begin(),vect[i][j][k][l].end());
    
    for (string q : query)
    {
        istringstream iss(q);
        string stringBuffer;
        vector <string> v;
        while (getline(iss, stringBuffer, ' ')) {
            if (stringBuffer != "and")v.push_back(stringBuffer);
        }
        l = m.find(v[0])->second;
        o = m.find(v[1])->second;
        c = m.find(v[2])->second;
        sf = m.find(v[3])->second;
        score = stoi(v[4]);
        int cnt = 0;
        for (int i = 1; i < 4; i++)
        {
            if (l != 0 && l != i) continue;
            for (int j = 1; j < 3; j++)
            {
                if (o != 0 && o != j) continue;
                for (int k = 1; k < 3; k++)
                {
                    if (c != 0 && c != k) continue;
                    for (int p = 1; p < 3; p++)
                    {
                        if (sf != 0 && sf != p) continue;
                        
                        int sss = vect[i][j][k][p].size();
                        if (sss == 0) continue;
                        for (int ord = 0; ord < sss; ord++)
                        {    
                            if (vect[i][j][k][p][ord] >= score)
                            {
                                cnt += (sss - ord);
                                break;
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}