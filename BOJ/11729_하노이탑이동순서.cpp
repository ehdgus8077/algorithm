#include <iostream>
using namespace std;

void hanoi(int first, int mid, int End,int num){

    if(num>0){
        hanoi(first,End,mid,num-1);
        cout <<first<<" "<<End<<"\n";
        hanoi(mid,first,End,num-1);
    }
}

int main(){
    int num;
    cin >> num;
    cout << (1<<num)-1<<"\n";
    hanoi(1,2,3,num);
    return 0;
}
