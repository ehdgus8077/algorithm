#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    
    int one = 0;
    int zero = 0;
    while(n) {
        if (n % 2 == 1){
            break;
        }
        zero += 1;
        n /= 2;
    }
    
    while(n) {
        if (n % 2 != 1){
            break;
        }
        one += 1;
        n /= 2;
    }
    one -= 1;
    zero += 1;
    n += 1;
    n = n << zero;
    while(one) {
        n *= 2;
        n += 1;
        one -=1;
    }
    
    return n;
}
