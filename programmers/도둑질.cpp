#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 1000000
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int dp[MAX][2];
    int s = money.size();
    for (int i = 0 ; i < money.size() ; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    dp[0][0] = money[0];
    dp[1][0] = max(money[0] , money[1]);
    dp[1][1] = money[1];
    dp[2][1] = max(money[1], money[2]);
    for (int i = 2 ; i < money.size() - 1 ; i++) {
        dp[i][0] = max(dp[i-2][0] + money[i], dp[i-1][0]);
    }
    for (int i = 3 ; i < money.size() -1 ; i++) {
        dp[i][1] = max(dp[i-2][1] + money[i], dp[i - 1][1]);
    }

    answer = max(dp[s - 2][0], dp[s - 3][1] + money[s - 1]);
    return answer;
}
