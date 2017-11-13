#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#define Max 10001
using namespace std;
int numbers[Max];
int main(){
   int num_count,num;
   cin >> num_count;
    for( int i = 0 ; i < num_count ; i++ ){
        cin >> num;
        numbers[num]++;
   }
    for( int i = 1 ; i < 10001 ; i++ ){
        if(numbers[i]){
            cout << i<<"\n";
            num_count--;
            numbers[i]--;
            i--;
        }
        else if(!num_count)
            break;
   }
    return 0;
}
