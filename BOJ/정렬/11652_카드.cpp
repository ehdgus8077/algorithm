#include <iostream>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;
bool com_str_number(const string& x, const string& y){
    int tx=1;
    int ty=1;
    if(x[0]=='-')
        tx=-1;
    if(x[0]=='-')
        ty=-1;
    if(tx<ty)
        return false;
    else if(tx>ty)
        return true;
    else{
        if(x.size()*tx<y.size()*tx)
            return false;
        else if(x.size()*tx>y.size()*tx)
            return true;
    }
    for ( int i = 0 ; i <x.size() ; i++ ){

        if(int(x[i])*tx<int(y[i])*tx)
            return false;
        else if(int(x[i])*tx>int(y[i])*tx)
            return true;
    }
    return false;
}
int main(){
   int num_count;
   string str_num;
   map< string,int> m;
   map< string , int >::iterator it;
   cin >> num_count;
    for( int i = 0 ; i < num_count ; i++ ){
        cin >> str_num;
        m[str_num]= (m[str_num])?m[str_num]+1:1;
   }
    int Max = 0;
    string Max_value;
    for (it=m.begin() ; it!=m.end();it++){
        if(Max<(*it).second ||Max==(*it).second && com_str_number(Max_value,(*it).first)){
            Max=(*it).second;
            Max_value=(*it).first;
        }
    }
    cout<<Max_value;
    return 0;
}
