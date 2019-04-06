#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector< vector<string> > words(26); 
    sort(strings.begin(), strings.end());
    for ( int i = 0 ; i < strings.size() ; i ++ ){
        words[strings[i][n] - 97].push_back(strings[i]);
    }
    for (int i = 0 ; i < 26 ; i ++ ){
        for ( int j = 0 ; j < words[i].size() ; j++ ){
            answer.push_back(words[i][j]);
        }
    }
    return answer;
}
