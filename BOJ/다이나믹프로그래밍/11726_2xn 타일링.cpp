#include<iostream>

using namespace std;

int solution(int n) {
    int dp[1001];
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;

    if (n>2){
        for ( int i = 3 ; i <=n ; i ++){
            dp[i] = (dp[i-1]+dp[i-2])%10007;
        }
    }
    answer = dp[n];
    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    return 0;
}
