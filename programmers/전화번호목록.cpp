#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool flag;
    int size;
    for (int i = 0 ; i < phone_book.size() ; i++) {
        for (int j = i + 1 ; j <phone_book.size() ; j++) {
            flag = true;
            size = min(phone_book[i].size(), phone_book[j].size());
            for (int k = 0 ; k < size ; k ++){
                if(phone_book[i][k] != phone_book[j][k]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    
    
    return true;
}
