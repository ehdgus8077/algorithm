#include <iostream>
#include <algorithm>
#define Max 8
#define Swap(a,b) {int t=a; a=b; b=t;}
using namespace std;
int numbers[Max],Count,sum_max;
int getValue(){
    int sum=0;
    for ( int i = 0 ; i < Count-1 ;i++ ){
        sum+=abs(numbers[i]-numbers[i+1]);
    }
    return sum;
}
void permutation(int first , int End){
    if( first == End ){
        int x=getValue();
        if(sum_max<x)
            sum_max=x;
    }
    else{
        permutation(first+1,End);
        for ( int i = first+1 ; i<=End ; i++){
            Swap(numbers[first],numbers[i]);
            permutation(first+1,End);
            Swap(numbers[i],numbers[first]);
        }
    }

}

int main(){
    int first=0,End,i=0;
    cin >> Count ;
    End=Count-1;
    for ( int i = 0 ; i < Count ; i++)
        cin >> numbers[i];
    permutation(0,Count-1);

    cout << sum_max;
    return 0;
}
