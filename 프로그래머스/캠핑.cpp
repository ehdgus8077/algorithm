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
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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
