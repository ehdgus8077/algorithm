#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int check = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '(') {
            check += 1;
        } else {
            check -= 1;
        }
        if (check < 0) {
            answer = false;
            break;
        }
    }
    if (check != 0) {
        answer = false;
    }
    cout << "Hello Cpp" << endl;
    
    return answer;
}
