#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500];
    for(int i = 0 ; i < 500 ; i++) {
        for(int j = 0 ; j < 500 ; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = triangle[0][0];
    for (int i = 1 ; i < triangle.size() ; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j = 1 ; j < triangle[i].size() ; j++) {
                
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    for (int i = 0 ; i < triangle.size() ;i ++) {
        if (answer < dp[triangle.size()-1][i]) answer = dp[triangle.size()-1][i];
    }
    return answer;
}
