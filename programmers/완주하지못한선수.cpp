#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> names;
    
    for (int i = 0 ; i < participant.size() ; i++) {
        if(names.find(participant[i]) == names.end()) {
            names.insert(make_pair(participant[i],1));   
        } else {
            names[participant[i]] += 1;
        }
    }
    
    for ( int i = 0 ; i < completion.size() ; i++) {
        names[completion[i]] -= 1;
    }
    
    for ( int i = 0 ; i < participant.size() ; i++) {
        if (names[participant[i]] != 0) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
