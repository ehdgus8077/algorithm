#include <cstdio>
#include <string>
#define MAX 5001
#define INF 1000000

using namespace std;

int solution(string pwd){

    int dp[MAX],temp=0;
    int Size = pwd.size();
    if(Size == 0 || pwd[0]=='0'){
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int  i = 2 ; i<=Size ; i++ ){
        temp = pwd[i-1]-'0';
        if(temp){
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = 0;
        }
        temp = temp+(pwd[i-2]-'0')*10;
        if(10<=temp&&temp<=26){
            dp[i]= (dp[i]+dp[i-2])%INF;
        }
    }
    return dp[Size];
}

int main(){
    char t[MAX];
    scanf("%s",&t);
    string pw = t;
    printf("%d", solution(pw));
    return 0 ;
}
