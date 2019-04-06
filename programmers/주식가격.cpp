#include <string>
#include <vector>
#include <stack>
#include <utility> 

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int> > s;
    s.push(make_pair(prices[0],0));
    for ( int i = 1 ; i< prices.size() ; i++ ){
        while(!s.empty()) {
            if (s.top().first > prices[i]) {
                answer[s.top().second] = i - s.top().second;
                s.pop();
                continue;
            }
            break;
        }
        s.push(make_pair(prices[i],i));   
    }
    while(!s.empty()) {
        answer[s.top().second] = prices.size() - s.top().second - 1;
        s.pop();
    }

    return answer;
}
