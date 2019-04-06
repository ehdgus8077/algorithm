#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a,vector<int> b){
    if(a[0]<b[0])
        return true;
    else if(a[0]==b[0]){
        return a[1]<b[1];
    }
    else

}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    int min_y = 0;
    for ( int i = 0 ; i < n ; i++ ){
        sort(data.begin(),data.end(),cmp);
    }
    data[i+1][]
    for ( int i = 0 ; i < n-1 ; i++ ){
        for ( int )
    }
    return answer;
}
