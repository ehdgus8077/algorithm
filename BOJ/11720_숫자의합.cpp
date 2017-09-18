#include <iostream>
using namespace std;

int main(){
    int count,sum=0;
    string numbers;
    cin >> count;
    cin >> numbers;

    for( int i = 0 ; i < count ; i++ ){
        sum+=numbers[i]-48;
    }
    cout << sum << "\n";

    return 0;
}
