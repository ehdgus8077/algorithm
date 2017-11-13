/*
    ���� ��� : n���� ���̵��� M���� 1�ν� ���̱ⱸ�� Ÿ�� ���� ���� ���� �ִ�. ���̱ⱸ���� ���� ���� �ð��� �ִ�.
            ���� ���̰� Ÿ�� �� ���̱ⱸ�� �����ϱ�?
            ���̱ⱸ�� ���� ��ȣ���� ž���Ѵ�.
*/
#include <cstdio>
#define MAX 10001
using namespace std;

int ride_time[MAX];
int div_zero[MAX];
int main(){
    int people_cnt, ride_cnt,time,result;
    scanf("%d %d", &people_cnt,&ride_cnt);
    for(int i = 1 ; i <=ride_cnt ; i++){
        scanf("%d",&time);
        ride_time[i] = time;
    }
    long long left = 0, right = 60000000000,mid, sum_time;

    while(left<=right){
        int temp = 0;
        mid = (left+right)/2;
        sum_time = ride_cnt;
        for (int i = 1 ; i <= ride_cnt ; i++){
            sum_time += mid/ride_time[i];
            if(mid%ride_time[i]==0)
                div_zero[temp++]= i;
        }

        if( 0<=sum_time-people_cnt&&sum_time-people_cnt<=temp-1){
            result = div_zero[temp-1-(sum_time-people_cnt)];
            right = mid -1;
        }
        else if( sum_time <people_cnt)
            left = mid+1;
        else
            right = mid -1;
    }
    printf("%d",result);
    return 0;
}
