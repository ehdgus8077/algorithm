/*
     �������: ���� ������ ���� ������ ��ū ���� ����Ͻÿ�.
     dp[i] = | 0                    ( i == 0 )
             | a[i]               ( i==1 )
             | max(dp[i-k])+a[i]  ( a[i-k]< a[i] &&i !=1 &&1 <= k <= i)
*/
#include<iostream>
#include<vector>

using namespace std;

int solution(vector < int > a) {

    int dp[1001];   // dp[i] = i��° ���������� ���� ������ ���� ������ ��ū ��
    int Size = a.size();
    a.insert(a.begin(),0);
    dp[0] = 0;
    dp[1] = a[1];
    int answer=dp[1];
    for ( int idx = 2 ; idx<=Size ; idx++ ){
        dp[idx] = dp[0];
        for(int k = 1 ; k <idx ; k++ ){
            if( a[idx-k]<a[idx]&& dp[idx]<dp[idx-k]){
                dp[idx] = dp[idx-k];
            }

        }
         dp[idx]+=a[idx];
         if(dp[idx]>answer){
            answer = dp[idx];
         }
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
