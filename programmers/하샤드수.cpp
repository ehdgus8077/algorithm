#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    
    int sum = 0;
    bool answer = true;
    int _x = x;
    while(_x) {
        sum += _x%10;
        _x /= 10;
    }
    if (x % sum != 0) {
        answer = false;
    }
    
    return answer;
    
}
