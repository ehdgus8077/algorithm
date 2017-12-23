#include <iostream>
#define Max 101
#define Swap(a,b){int t=a; a=b; b=t;}
using namespace std;
int basket[Max];
void Reverse_order(int start, int End){
    while(start<End){
        Swap(basket[start],basket[End]);
        start++;
        End--;
    }
}
int main(){
    int count,M,start,End;
    cin >> count >> M;
    for( int i = 1 ; i <= count ; i++)
        basket[i]=i;
    while(M--){
        cin >> start >> End;
        Reverse_order(start,End);
    }
    for( int i = 1 ; i <= count ; i++)
       cout << basket[i]<<" ";

    return 0;
}
