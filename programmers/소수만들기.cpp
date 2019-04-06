#include <vector>
#include <iostream>
using namespace std;

void com(int numbers[], int start, int count, vector<int>& nums, int sum) {
    
    if (count == 0) {
        numbers[sum] += 1;
    } else {
        if(start >= nums.size()) {
            return;
        }
        com(numbers, start + 1, count - 1, nums, sum + nums[start]);
        com(numbers, start + 1, count, nums, sum);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    int numbers[3000] = {0,};
    
    com(numbers, 0, 3, nums, 0);

    for (int i = 2 ; i < 3000 ; i++){
        for (int j = i + i ; j < 3000 ; j = j + i) {
            numbers[j] = 0;
        }
    }
    for (int i = 0 ; i < 3000 ; i++) {
        answer += numbers[i];
    }
    cout << "Hello Cpp" << endl;

    return answer;
}
