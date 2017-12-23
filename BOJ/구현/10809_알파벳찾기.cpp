#include <iostream>
#define Max 26
using namespace std;
int alpha[Max];

int main(){
   string str;
   cin >> str;
   for( int i = 0 ; i<str.size() ; i++){
        if(!alpha[str[i]-97])
            alpha[str[i]-97]=i+1;
   }
   for( int i = 0 ; i<26 ; i ++){
        cout << alpha[i]-1<<" ";
   }
    return 0;
}
