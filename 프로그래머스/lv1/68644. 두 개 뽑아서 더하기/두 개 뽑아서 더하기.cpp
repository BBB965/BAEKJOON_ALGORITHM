#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check[210];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int leng = numbers.size();
    for (int i = 0; i < leng - 1; i++)
        for (int j = i+1; j < leng; j++)
        {
            int temp = numbers[i] + numbers[j];
            if (!check[temp])
            {
                check[temp] = 1;
                answer.push_back(temp);
            }
        }
    
    sort(answer.begin(), answer.end());
    return answer;
}