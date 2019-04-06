#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long start, end;
    int timeSize = times.size();
    auto minmax = minmax_element (times.begin(), times.end());
    
    start = (timeSize > n)? *minmax.first : *minmax.first * (n / timeSize + n % 2);
    end = 100000000000000;
    
    long long middle;
    while(start <= end) {
        middle = (start + end) / 2;
        long long sum = 0;
        for (int i = 0 ; i < times.size() ; i++) sum += middle / times[i];
        if (n > sum) start = middle + 1;
        else {
            end = middle - 1;
        }
    }
    
    return start;
}
