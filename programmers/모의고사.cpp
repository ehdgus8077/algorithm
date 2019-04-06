#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int two[] = {1, 3, 4, 5};
    int three[] = {3, 1, 2, 4, 5};
    int score[] = {0, 0, 0};
    for (int i = 0 ; i < answers.size() ; i ++) {
        if (answers[i] == i % 5 + 1){
            score[0] += 1; 
        }
        if ((i % 2 == 0 && answers[i] == 2) || i % 2 == 1 && (answers[i] == two[i/2%4])) {
            score[1] += 1;
        }
        if (answers[i] == three[i/2%5]) {
            score[2] += 1;
        }
    }
    
    
    for (int i = 0 ; i < 3 ; i ++) {
        bool flag = true; 
        for (int j = 0 ; j < 3 ; j ++) {
            if (i == j) {
                continue;
            }
            if (score[j] > score[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
         answer.push_back(i + 1);   
        }
    }
    
    return answer;
}
