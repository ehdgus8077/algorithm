#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    int sum = 0;
    for (int i = 0; i < bridge_length ; i ++) {
        bridge.push(0);
    }
    int i = 0;
    while(i < truck_weights.size()) {
        sum -= bridge.front();
        bridge.pop();
        
        if (sum + truck_weights[i] > weight) {
            bridge.push(0);
        } else {
            sum += truck_weights[i];
            bridge.push(truck_weights[i]);
            i += 1;
        }
        answer += 1;
    }
    answer += bridge_length;
    return answer;
}
