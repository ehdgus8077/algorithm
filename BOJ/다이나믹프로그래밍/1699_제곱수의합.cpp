#include<iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[100001];
    dp[0] = 0;
    dp[1] = 1;
    int num;
    for ( int i = 2 ; i <= n ; i++ ){
        num = 1;
        dp[i] = dp[i-1]+1;
        while(i-num*num>=0){
            if( dp[i]>dp[i-num*num])
                dp[i] = dp[i-num*num];
            num++;
        }
        dp[i]++;
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
