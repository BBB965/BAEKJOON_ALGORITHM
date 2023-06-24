#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int tower[1001][1001];
    int num = 1;
    int x = 0;
    int y = 1;
    int leng = n;
    int ord = 0;
    while (leng > 0)
    {
        int temp = leng;
        if (ord%3 == 0)
        {
            while(temp--)
            {
                tower[++x][y] = num;
                num++;
            }
        }
        else if (ord%3 == 1)
        {
            while(temp--)
            {
                tower[x][++y] = num;
                num++;
            }
        }
        else
        {
            while(temp--)
            {
                tower[--x][--y] = num;
                num++;
            }
        }
        ord++;
        leng--;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            answer.push_back(tower[i][j]);
    return answer;
}