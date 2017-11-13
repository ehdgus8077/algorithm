#include <iostream>
#include <string>
#include <map>
#define Max 10001
using namespace std;

float ceta;
string str;
int dp[Max];
bool isPalindrom(string s) {
   int w = s.length();
   int i;
      for (i = 0; i < w / 2; i++) {
         if (!(s[i] == s[w - i - 1]))
            break;
      }
      if (float(i) >= float(w*ceta / 2)) {
               return true;
            }
            else {
               return false;
            }
}


int main(){

    ios::sync_with_stdio(false);
    float k, l;
    int Length;
    cin >> Length >> k >> l;
    cin >> str;
    ceta = k / l;

    str=' '+str;
    dp[1]=Max;
    for ( int End = 2 ; End <= Length ; End++ ){
        dp[End] = Max;
        for ( int start = End-1 ; start >0 ; start --){
            if(dp[start-1]==Max || start ==2 )
                continue;
            if(isPalindrom(str.substr(start, End-start+1))){
                dp[End]=min(dp[End],dp[start-1]+1);
            }
        }
    }

    cout << dp[Length];
    return 0;
}
