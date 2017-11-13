#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100011
using namespace std;
int dp[MAX];
int solution(vector< int> num){
    int n = num.size()-1;
    dp[1] = num[1];
    for (int i = 2 ; i<=n ; i++ ){
        dp[i] = max(num[i],dp[i-1]+num[i]);
    }
    int answer = dp[1];
    for ( int i = 2 ; i <= n ; i++ ){
        answer = max(answer,dp[i]);
    }
    return answer;
}
int main() {
        int n;
        cin >> n;
        vector<int> number(n+1);
        number[0] = 0;
        for ( int i = 1 ; i <= n ; i++ ){
            cin >> number[i];
        }
        cout<< solution(number);
    return 0;
}
