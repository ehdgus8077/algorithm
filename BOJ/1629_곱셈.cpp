#include <iostream>
#include <cstdio>

using namespace std;
long long A,C;
long long solution( long long count ){
    if(count==1)
        return A%C;
    else if(count==2){

        return A*A%C;
    }
    else{
        long long x=solution(count/2);
        if(count%2==1)
            return (x*x%C*A)%C;
        else{
            return (x*x)%C;
        }
    }
}
int main(){
    long long B,answer;
    ios::sync_with_stdio(false);
    cin >> A >> B >> C;

    cout<<solution(B);
    return 0;
}
