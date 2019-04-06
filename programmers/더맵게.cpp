#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<int> h;
    for (int i = 0 ; i < scoville.size() ; i ++) h.push(scoville[i] * -1);

    int first,second;
    int result;
    int answer = 0;
    while(h.size() != 1) {
        first = h.top();
        h.pop();
        second = h.top();
        h.pop();   
        
        if ( (first * -1) >= K && (second * -1) >= K) {
            return answer;
        } else {
            answer += 1;
            h.push(first + second*2);
        }
    }
    
    if (h.top() * -1 < K) return -1;
    
    return answer;
}
