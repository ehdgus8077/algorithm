#include <iostream>
#include <algorithm>
#define Max 2501
using namespace std;
/*
�Ӹ���� ������ ������ �ּҰ��� ����ض�.
1. ���̳��� ���α׷������� Ǯ��
dp[i]�� i��° ���ڿ������� �ּ� ���� ����

*/
int dp[Max];
string str;
bool isPalindrom(int start , int End) {

   while(start<End){
        if(str[start]!=str[End]){
            return false;
        }
        start++;
        End--;
   }
    return true;
}
int main(){
    cin >> str;
    int str_length = str.length();
    dp[1]=1;
    str=' '+str;
    for ( int End = 2 ; End <= str_length ; End++ ){
        dp[End] = dp[End-1]+1;
        for ( int start = End-1 ; start >0 ; start --){
            if(isPalindrom(start, End)){
                dp[End]=min(dp[End],dp[start-1]+1);
            }
        }
    }

    cout << dp[str_length];
    return 0;
}
