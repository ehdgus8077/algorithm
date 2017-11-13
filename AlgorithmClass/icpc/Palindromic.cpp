#include <iostream>
#define Max 30
using namespace std;
int numbers[Max];
int conversion(int num, int x){
    int count = 0;
    while(num){
        numbers[count++] = num%x;
        num/=x;
    }
    return count;
}
bool isPalindrom(int count){
    int first = 0, End = count-1;
    while(first<End){
        if(numbers[first++]!=numbers[End--])
            return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    int case_count,num,i;
    cin >> case_count;
    while(case_count--){
        cin >> num ;
        for( i = 2 ; i <=64 ; i++){
            if(isPalindrom(conversion(num,i))){
                cout <<1<<"\n";
                break;
            }
        }
        if(i==65)
            cout<<0<<"\n";
    }

    return 0;
}
