#include <iostream>
using namespace std;


int main(){
   string str;
   int result=0,num,temp=1,n;
   cin >> str >> num;
   for ( int i = str.size()-1 ; i>=0 ;i-- ){
    if(str[i]<58)
        n=str[i]-48;
   else
        n=str[i]-55;
    result+=temp*n;
    temp*=num;
   }
   cout << result;
    return 0;
}
