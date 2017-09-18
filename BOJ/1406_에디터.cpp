#include <iostream>
#include <string>
using namespace std;



int main(){
    string str;
    int Count;
    string key1,key2;
    cin >> str;
    cin >> Count;
    int cursor_location=str.size();
    while(Count--){

        cin >> key1;
        switch(key1[0]){
        case 'P':
            cout<<'a'<<"\n";
            cin >> key2;
            str.insert(cursor_location,key2);
            cursor_location++;
            break;
        case 'L':
            if(cursor_location>0)
                cursor_location--;
            break;
        case 'D':
            if(cursor_location<str.size())
                cursor_location++;
            break;
        case 'B':
            if(cursor_location!=0){
                str.erase(cursor_location-1);
                cursor_location--;
            }
            break;
        }

    }
    cout << str;
    return 0;
}
