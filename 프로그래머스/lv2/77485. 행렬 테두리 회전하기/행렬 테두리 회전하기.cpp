#include <string>
#include <vector>
using namespace std;
int matrix[110][110];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num = 1;
    for (int y = 1; y <= rows; y++)
        for (int x = 1; x <= columns; x++)
        {
            matrix[y][x] = num;
            num++;
        }
    
    for (int i = 0; i < queries.size(); i++)
    {
        int nums = 1e9;
        int y1 = queries[i][0];
        int x1 = queries[i][1];
        int y2 = queries[i][2];
        int x2 = queries[i][3];
        int temp = matrix[y1][x1];
        nums = min(nums, temp);
        for (int y = y1; y < y2; y++)
        {
            matrix[y][x1] = matrix[y+1][x1];
            nums = min(nums, matrix[y][x1]);
        }
        for (int x = x1; x < x2; x++)
        {
            matrix[y2][x] = matrix[y2][x+1];
            nums = min(nums, matrix[y2][x]);
        }
        for (int y = y2; y > y1; y--)
        {
            matrix[y][x2] = matrix[y-1][x2];
            nums = min(nums, matrix[y][x2]);
        }
        for (int x = x2; x > x1; x--)
        {
            matrix[y1][x] = matrix[y1][x-1];
            nums = min(nums, matrix[y1][x]);
        }
        matrix[y1][x1 + 1] = temp;
        answer.push_back(nums);
    }
    return answer;
}