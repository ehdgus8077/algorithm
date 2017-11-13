/*
문제 요약 : 학생들 모두 자신과 짝이 됬으면 하는 학생을 고른다. 만약 그 관계가 사이클일 경우 한 팀이 된다.
        그럼 팀이 없는 학생의 수는 몇명인가?
*/
#include <iostream>
#define MAX 100001
using namespace std;

int parent[MAX];
int visit_no[MAX];
int answer;
int solution(int i, int no){
    while(true){
        visit_no[i]=no;
        if(visit_no[i]){
            answer+=no-visit_no[i];
            break;
        }
        no++;
        i = parent[i];
    }
    return no
}

int main(){
    int case_cnt,student_cnt;
    cin >> case_cnt;
    while(case_cnt--){
        answer = 0;
        cin >>student_cnt;
        for( int i = 1 ; i <= student_cnt ; i++ ){
            visit_no[i]=0;
            cin >> parent[i];
        }
        for ( int i = 1 ; i <= student_cnt ; i++ ){
            if(!visit_no[i])
                solution(i,1);
        }
        cout << student_cnt-answer <<"\n";

    }
    return 0;
}
