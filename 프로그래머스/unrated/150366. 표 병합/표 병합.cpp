#include <string>
#include <vector>
#include <sstream>
 
using namespace std;
 
int link[2501];
string value[2501];
 
int flatPos(int r, int c) {
    return (r - 1) * 50 + c;
}
 
vector<string> solution(vector<string> commands) {
    vector<string> answer;
 
    //초기화
    for (int i = 1; i <= 2500; i++) {
        link[i] = i;
        value[i] = "EMPTY";
    }
 
    //해법
    for (string &command : commands) {
        vector<string> v;
        stringstream ss(command);
        string token;
        while (ss >> token) v.push_back(token);
 
        if (v[0] == "UPDATE") {
            if (v.size() == 4) { //1. UPDATE r c value
                int pos = flatPos(stoi(v[1]), stoi(v[2]));
                string val = v[3];
                int parent = link[pos];
                value[parent] = val;
            }
            else { //2. UPDATE value1 value2
                string val1 = v[1], val2 = v[2];
                for (int i = 1; i <= 2500; i++) {
                    if (value[i] == val1) value[i] = val2;
                }
            }
        }
        else if (v[0] == "MERGE") { //3. MERGE r1 c1 r2 c2
            int pos1 = flatPos(stoi(v[1]), stoi(v[2])), pos2 = flatPos(stoi(v[3]), stoi(v[4]));
            int parent1 = link[pos1], parent2 = link[pos2];
            if (parent1 != parent2) {
                for (int i = 1; i <= 2500; i++) {
                    if (link[i] == parent2) link[i] = parent1;
                }
                string val1 = value[parent1], val2 = value[parent2];
                if (val1 == "EMPTY" && val2 != "EMPTY") {
                    value[parent1] = value[parent2];
                }
                else {
                    value[parent2] = value[parent1];
                }
            }
        }
        else if (v[0] == "UNMERGE") { //4. UNMERGE r c
            int pos = flatPos(stoi(v[1]), stoi(v[2]));
            int parent = link[pos];
            string val = value[parent];
            for (int i = 1; i <= 2500; i++) {
                if (link[i] == parent) {
                    link[i] = i;
                    value[i] = "EMPTY";
                }
            }
            value[pos] = val;
        }
        else { //5. PRINT r c
            int pos = flatPos(stoi(v[1]), stoi(v[2]));
            int parent = link[pos];
            answer.push_back(value[parent]);
        }
    }
 
    return answer;
}

// #include <string>
// #include <vector>
// #include <sstream>
// #include <unordered_map>
// using namespace std;

// pair<string, pair<int,int>> cell[51][51];
// vector <pair<int,int>> vect[51][51];
// unordered_map <string, pair<int,int>> um;

// vector<string> split(string input, char delimiter){
//     vector<string> result;
//     stringstream ss(input);
//     string tmp;
    
//     while (getline(ss, tmp, delimiter)) result.push_back(tmp);
//     return result;
// }

// void reset()
// {
//     for (int y = 1; y <= 50; y++)
//         for (int x = 1; x <= 50; x++)
//             cell[y][x] = {"EMPTY", {y,x} };
// }

// vector<string> solution(vector<string> commands) {
//     vector<string> answer;
//     reset();
//     for (int i = 0; i < commands.size(); i++)
//     {
//         vector <string> result = split(commands[i], ' ');
//         if (result[0] == "UPDATE")
//         {
//             if (result.size() == 4) 
//             {
//                 int y = stoi(result[1]);
//                 int x = stoi(result[2]);
//                 cell[y][x].first = result[3];
//                 um.insert({result[3], {y,x}});
//                 if (cell[y][x].second.first != y || cell[y][x].second.second != x)
//                 {
//                     if (cell[y][x].first == "EMPTY")
//                     {
//                         cell[y][x].second = {y, x};
//                         continue;
//                     }
//                     pair<int,int> temp = cell[y][x].second;
//                     cell[temp.first][temp.second].first = result[3];
//                 }
//             }
//             else
//             {
//                 pair<int,int> temp = um[result[1]];
//                 um.erase(result[1]);
//                 um.insert({result[2], temp});
//                 cell[temp.first][temp.second].first = result[2];
//                 pair<int,int> parent = cell[temp.first][temp.second].second;
//                 if (temp != parent) cell[parent.first][parent.second].first = result[2];
//             }
//         }
        
//         else if (result[0] == "MERGE")
//         {
//             int r1 = stoi(result[1]);
//             int c1 = stoi(result[2]);
//             int r2 = stoi(result[3]);
//             int c2 = stoi(result[4]);
            
//             if (cell[r1][c1].second.first != r1 || cell[r1][c1].second.second != c1)
//             {
//                 pair<int,int> temp = cell[r1][c1].second;
//                 string st = cell[temp.first][temp.second].first;
                
//                 if (cell[r2][c2].second.first != r2 || cell[r2][c2].second.second != c2)
//                 {
//                     pair<int,int> ttt = cell[r2][c2].second;
//                     int cnt = vect[ttt.first][ttt.second].size() - 1;
//                     for (int i = cnt; i >= 0; i--)
//                     {
//                         vect[temp.first][temp.second].push_back(vect[ttt.first][ttt.second][i]);
//                         int ty = vect[ttt.first][ttt.second][i].first;
//                         int tx = vect[ttt.first][ttt.second][i].second;
//                         vect[ttt.first][ttt.second].pop_back();
//                         cell[ty][tx].second = temp;
//                         cell[ty][tx].first = st;
//                     }
//                     vect[temp.first][temp.second].push_back({ttt.first, ttt.second});
//                     continue;
//                 }
//                 cell[r1][c1].first = st;
//                 cell[r2][c2].first = st;
//                 cell[r2][c2].second = temp;
//                 vect[temp.first][temp.second].push_back({r2,c2});
//             }
//             else
//             {
//                 if (cell[r1][c1].first != "EMPTY")cell[r2][c2].first = cell[r1][c1].first;
//                 else cell[r1][c1].first = cell[r2][c2].first;
//                 cell[r2][c2].second = {r1,c1};
//                 vect[r1][c1].push_back({r2,c2});
//             }
//         }
//         else if (result[0] == "UNMERGE")
//         {
//             int r = stoi(result[1]);
//             int c = stoi(result[2]);
//             pair<int,int> temp = cell[r][c].second;
//             cell[r][c].second = {r,c};
//             cell[r][c].first = cell[temp.first][temp.second].first;
//             cell[temp.first][temp.second].first = "EMPTY";
//             for (int i = 0; i < vect[temp.first][temp.second].size(); i++)
//             {
//                 pair<int,int> ttt = vect[temp.first][temp.second][i];
//                 if (ttt.first != r && ttt.second != c)
//                 {
//                     cell[ttt.first][ttt.second].second = ttt;
//                     cell[ttt.first][ttt.second].first = "EMPTY";
//                 }
//             }
//         }
//         else
//         {
//             int r = stoi(result[1]);
//             int c = stoi(result[2]);
//             pair<int,int> temp = cell[r][c].second;
//             if (temp.first != r || temp.second != c) answer.push_back(cell[temp.first][temp.second].first);
//             else answer.push_back(cell[r][c].first);
//         }
//     }
//     return answer;
// }