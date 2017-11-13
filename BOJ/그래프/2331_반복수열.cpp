/*
문제 : 문제 규칙에 맞는 수열들 중에서 중복수열을 제외한 수열들의 개수를 출력해라
     수열의 규칙은 d[n]는 d[n-1]수의 각 자리수를 p번 곱한 수들 더한 값이다.
    딕셔너리
*/
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int mul(int num, int p){
    int result=num;
    while(p>1){
        result*=num;
        p--;
    }
    return result;
}
int main(){
    int first_num, p,next_num,prenum,idx=1;
    map<int, int> check;
    cin >> first_num >> p;
    check[first_num]=idx;
    idx++;
    prenum = first_num;
    while(true){
        next_num=0;
        while(prenum){
            next_num+=mul(prenum%10,p);
            prenum/=10;
        }
        if(check.find(next_num) == check.end()){
            check[next_num]=idx;
            idx++;
        }
        else{
            cout<<check[next_num]-1;
            return 0;
        }
        prenum=next_num;
    }
    return 0;
}
