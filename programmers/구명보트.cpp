#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, start = 0 , end = people.size() -1;
    sort(people.begin(), people.end());
    while(start < end) {
        if (people[start] + people[end] > limit) {
            answer += 1;
        } else {
            start += 1;
            answer += 1;
        }
        end -= 1;
    }
    if (start == end) answer += 1;
    return answer;
}
