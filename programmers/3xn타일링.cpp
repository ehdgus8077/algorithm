#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long dp[5001];
    if (n == 0) return 0;
    dp[0] = 1;
    dp[2] = 3;
    long long sum = 0;
    for (int i = 4 ; i <=n ; i +=2) {
        sum += (dp[i - 4] * 2) %1000000007;
        dp[i] = (dp[i-2] * 3  + sum) %1000000007;
        
    }
    return dp[n] %1000000007;;
}
