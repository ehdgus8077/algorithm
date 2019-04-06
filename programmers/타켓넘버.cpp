#include <string>
#include <vector>

using namespace std;
int answer;
void com(int start, int target, vector<int>& numbers, int sum) {
    if (start <= numbers.size()) {
        if (sum == target) {
            answer += 1;
            return;
        }
        com(start + 1, target, numbers, sum);
        com(start + 1, target, numbers, sum - numbers[start] * 2);
    }
}
int solution(vector<int> numbers, int target) {
    answer = 0;
    int sum = 0;
    for (int i = 0 ; i < numbers.size() ; i++) {
        sum += numbers[i];
    }
    com(0, target, numbers, sum);
    return answer;
}
