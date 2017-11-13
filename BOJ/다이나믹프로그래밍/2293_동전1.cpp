#include <iostream>

using namespace std;
int temp;
void aaaa(string str,int a, int b){
    if(a==b-1)
        cout << str<<"\n";
    else{
        for (int i = a ; i <b ; i++ ){
            temp= str[a];
            str[a] = str[i];
            str[i] =  temp;
            aaaa(str,a+1,b);
            temp= str[a];
            str[a] = str[i];
            str[i] =  temp;
        }
    }
}
int main(){
    string aaa="abc";
    aaaa(aaa,0,3);
    return 0;
}
