#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 31
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int check[MAX] = {0,};
    int answer = 0;
    for(int i = 0 ; i <  lost.size() ; i++) check[lost[i]]--;
    for(int i = 0 ; i <  reserve.size() ; i++) check[reserve[i]]++;
    
    for (int i = 1 ; i <= n ; i++) {
        if (check[i] == -1) {
            if (i -1 >= 0 && check[i-1] > 0) {
                answer += 1;
                check[i-1] -=1;
            } else if (i + 1 <= n && check[i+1] > 0) {
                answer += 1;
                check[i+1] -=1;
            } 
            
        }
        if(check[i] >= 0) answer += 1;
        
    }
    
    return answer;
}
