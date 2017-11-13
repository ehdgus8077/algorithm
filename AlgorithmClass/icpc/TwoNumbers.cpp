#include <vector>
#include <algorithm>
#include <cstdio>
#define ARR_MAX 1000001
#define MAX 300000001
using namespace std;
int answer;
int target_len;
int number_cnt;
int numbers[ARR_MAX];
bool Find(int num, int target){
    int start=num+1,End=number_cnt-1;
    int mid,temp;
    target-=numbers[num];

    while(End-start>1){
        mid = (start+End)/2;
        if(numbers[mid]==target){
            if( target_len==0 )
                answer++;
            else{
                target_len =0;
                answer=1;
            }
            return true;
        }
        else if(numbers[mid]>target){
            End = mid-1;
        }
        else {
            start = mid+1;
        }
    }

    for( int i = start-1 ; i<=End+1 ;i++){
        if(i<=num || i> number_cnt-1)
            continue;
        temp = abs(target-numbers[i]);
        if( target_len==temp )
           answer++;
        else if( target_len>temp ){
            target_len = temp;
            answer = 1;
        }
    }
    return true;
}
int main(){
    int case_cnt,target,temp;
    scanf("%d",&case_cnt);
    while(case_cnt--){
        target_len = MAX;
        answer = 0;
        scanf("%d %d",&number_cnt,&target);
        for( int i = 0 ; i < number_cnt ; i++ ){
            scanf("%d",&numbers[i]);
        }
        sort(numbers, numbers+number_cnt);
        for ( int i = 0 ; i < number_cnt-1 ; i++ ){
            Find(i,target);
        }
        printf("%d\n",answer);
    }

    return 0;
}
