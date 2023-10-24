#include <iostream>
#include <vector>
using namespace std;

int N, P, a, b;
vector <int> vect[7];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int answer = 0;
    
    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (vect[a].empty()) {
            vect[a].push_back(b);
            answer++;
            continue;
        }
        
        if (vect[a].back() > b) {
            while (!vect[a].empty() && vect[a].back() > b) {
                vect[a].pop_back();
                answer++;
            }
        }
        if (vect[a].empty() || vect[a].back() < b) {
            vect[a].push_back(b);
            answer++;
        }
        else if (vect[a].back() == b) {
            continue;
        }
    }
    cout << answer;
    return 0;
}
