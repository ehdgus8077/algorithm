#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool check(string first, string second) {
    int cnt = 0;
    for (int i = 0 ; i < first.size() ; i ++) {
        if (first[i] == second[i]) cnt += 1;
    }
    return (first.size() - 1 == cnt)? true : false;
}

int solution(string begin, string target, vector<string> words) {
    
    bool checkArr[51] = {0,};
    queue<pair<string,int>> q;
    q.push(make_pair(begin, 0));
    while(!q.empty()) {
        auto b = q.front();
        if(target == b.first) return b.second; 
        q.pop();
        for (int i = 0 ; i < words.size() ; i++) {
            if (checkArr[i]) continue;
            if (!check(b.first, words[i])) continue;
            q.push(make_pair(words[i], b.second + 1));
            checkArr[i] = true;
        }
    }
    
    return 0;
}
