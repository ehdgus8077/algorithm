#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool checkArr[201] = {0,};
    for (int i = 0 ; i < n ; i++) checkArr[i] = 0;
    queue<int> q;
    
    int crr;
    for (int i = 0 ; i < n ; i++) {
        if (checkArr[i]) continue;
        q.push(i);
        checkArr[i] = true;
        while(!q.empty()) {
            crr = q.front();
            q.pop();
            for (int j = 0 ; j < n ; j++) {
                if (!computers[crr][j]) continue;
                if (checkArr[j]) continue;
                q.push(j);
                checkArr[j] = true;
            }
        }
        cout << i << " ";
        answer += 1;
    } 
    
    
    return answer;
}
