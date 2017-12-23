#include <iostream>
#define Max 26
using namespace std;


int main(){
   string str;
   cin >> str;
   int first=0,End;
   End=str.size()-1;
   while(first<End){
        if(str[first]!=str[End]){
            cout<<0;
            return 0;
        }
        first++;
        End--;
   }
   cout <<1;
    return 0;
}
