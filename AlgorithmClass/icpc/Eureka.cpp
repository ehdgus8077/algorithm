#include <iostream>

using namespace std;
bool solution(int num){
    int temp;
    for( int i = 1 ; 1 ; i++ ){
            for( int j = i ; 1 ; j++ ){
                for( int k = j ; 1 ; k++ ){
                    temp= i*(i+1)/2+j*(j+1)/2+k*(k+1)/2;
                    if(num==temp){
                        return true;
                    }
                    else if(temp>num){
                        break;
                    }
                }
                if(i*(i+1)/2+j*(j+1)/2>=num){
                    break;
                }
            }
            if(i*(i+1)/2>=num){
                    return false;
                }
        }

}

int main(){
    ios::sync_with_stdio(false);
    int case_cnt,num;
    cin >>case_cnt;
    while(case_cnt--){
        cin >>num;
        if(solution(num))
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }

    return 0;
}
