#include<iostream>
#include<vector>

using namespace std;

int solution(vector < int > a) {
    int dp[1001];
    dp[0] = 0;
    dp[1] = 1;

    for ( int i = 2; i <= a.size(); i++ ){
        dp[i] = 0 ;
        for ( int j = 0 ; j < i-1 ; j++ ){
            if(a[i-1]>a[j] && dp[i]<dp[j+1]){
                dp[i] = dp[j+1];
            }
        }
        dp[i]++;
    }
    int answer = 0;
    for ( int i = 1 ; i <=a.size() ; i++ ){
        if(answer<dp[i])
            answer = dp[i];
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solution(a) << '\n';
    return 0;
}
