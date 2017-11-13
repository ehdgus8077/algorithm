#include <iostream>

using namespace std;

int main(){
    int case_cnt,col,row,n;
    ios::sync_with_stdio(false);
    cin >> case_cnt;
    while(case_cnt--){
        cin >> row >> col >> n;
        cout<< (n-1)%(row)+1;
        if(n/row+1<10)
            cout<<0<<(n-1)/row+1<<"\n";
        else
            cout<<(n-1)/row+1<<"\n";
    }

    return 0;
}
