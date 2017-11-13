/*
    문제 요약 : n자리의 이친수의 경우의 수를 출력하시오. 이친수는 첫문자가 0이 아니고 연속된 1이 없는 이진수 조합이다.
    dp[i][2] = dp[i][k] i자리 이진수의 가장 뒷자리가 k인 경우의 수
    dp[i][0] = | 0   ( i==1 )
               | dp[i-1][1]+dp[i-1][0] (i!=1)
    dp[i][0] = | 1   ( i==1 )
               | dp[i-1][0] (i!=1)

*/
#include<iostream>

using namespace std;

long long solution(int a) {
    long long dp[91][2];
    dp[1][0] = 0;
    dp[1][1] = 1;
    for ( int i=2 ; i <= a ;i++ ){
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }
    return dp[a][0]+dp[a][1];
}

int main() {
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    return 0;
}
