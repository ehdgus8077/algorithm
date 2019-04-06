#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> wordSet;
    bool flag = true;
    wordSet.insert(words[0]);
    
    for (int i = 1 ; i < words.size() ; i++) {
        if (words[i][0] != words[i-1][words[i-1].size() - 1] || wordSet.find(words[i]) != wordSet.end()) {
            flag = false;
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        wordSet.insert(words[i]);
    }
    
    if (flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    cout << "Hello Cpp" << endl;

    return answer;
}
