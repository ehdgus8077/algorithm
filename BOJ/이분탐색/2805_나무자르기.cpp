#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
int numbers[MAX];

long long solution(int num_cnt,int max_num ,int target_cnt ){
    long long start=0,End=max_num,mid,result=0;
    long search_target;
    while(start<=End){
        search_target=0;
        mid = (start+End)/2;
        for( int i = 0 ; i < num_cnt ; i++){
            if(numbers[i]-mid>0)
                search_target += numbers[i]-mid;
        }

        if(search_target>=target_cnt){
            result = mid;
            start = mid + 1;
        }
        else{
            End = mid-1;
        }
    }
    return result;
}
int main(){
    int number_cnt, target_cnt,temp;
    scanf("%d %d",&number_cnt,&target_cnt);
    for( int i = 0 ; i < number_cnt ; i ++ ){
        scanf("%d",&numbers[i]);
    }
    sort( numbers , numbers+number_cnt );
    printf("%d",solution(number_cnt,numbers[number_cnt-1],target_cnt));
    return 0;
}
