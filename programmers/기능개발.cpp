#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
    int MIN = -1;
    for (int i = 0 ; i < progresses.size() ; i++){
        int time = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0) {
            time += 1;
        }
        if (MIN < time) {
            answer.push_back(1);
            MIN = time;
        } else {
            answer[answer.size() - 1] += 1;
        }
    }
    
    return answer;
}
