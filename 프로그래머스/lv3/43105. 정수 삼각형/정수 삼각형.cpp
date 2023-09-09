#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int N = triangle.size() - 1;
    
    for (int i = N; i > 0; i--)
        for (int j = 0; j < i; j++)
            triangle[i-1][j] += triangle[i][j+1] > triangle[i][j] ? triangle[i][j+1] : triangle[i][j];
    
    return triangle[0][0];
}