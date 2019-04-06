#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    int count = stock;
    
    for (int i = 0 ; i < dates.size() ; i++) {
        if (count + 1 <= dates[i]) {
            count += pq.top();
            pq.pop();
            answer += 1;
        }
        pq.push(supplies[i]);
    }
    
    while(count < k) {
        count += pq.top();
        pq.pop();
        answer += 1;
    }
    
    return answer;
}
