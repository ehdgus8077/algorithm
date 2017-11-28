#include <iostream>
#define MAX 31

using namespace std;
long long dp[MAX][2]; // dp[i][0] = 3xi 크기의 타일에서 가장 오른쪽에 2x1타일이 있는 경우의 수
                // dp[i][1] = 3xi 크기의 타일의 경우의 수
long long solution (int n ){
    dp[2][1] = 3;
    dp[2][0] = 2;
    for ( int i = 4 ; i <=n ; i+=2 ){
        dp[i][1] = dp[i-2][1]*3 + dp[i-2][0];
        dp[i][0] = dp[i-2][1]*2 + dp[i-2][0];
    }
    return dp[n][1];
}

int main(){

    int n;
    cin >> n ;
    cout << solution(n);
    return 0;
}
