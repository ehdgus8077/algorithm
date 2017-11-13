#include <cstdio>
#define MAX 1001
using namespace std;


int numbers[MAX];

bool solution(int num_cnt){
    int zero_cnt,temp1,temp2;
      for ( int j = 0 ; j < 1000 ; j ++ ){
            zero_cnt=0;
            temp1 = numbers[0]-numbers[num_cnt-1];
            temp2 = numbers[num_cnt-2]-numbers[num_cnt-1];
            for ( int i = 0 ; i < num_cnt-2 ; i ++ ){

                numbers[i]= numbers[i]-numbers[i+1];
                if(numbers[i]<0)
                    numbers[i]*=-1;
                if(numbers[i]==0){
                    zero_cnt++;
                }
            }
            numbers[num_cnt-1]= temp1>0?temp1:temp1*-1;
            numbers[num_cnt-2]= temp2>0?temp2:temp2*-1;
            if(numbers[num_cnt-1]==0){
                zero_cnt++;
            }
            if(numbers[num_cnt-2]==0){
                zero_cnt++;
            }
            if(zero_cnt == num_cnt){
                printf("ZERO\n");
                return true;
            }

        }
        printf("LOOP\n");
        return true;
}

int main(){
    int case_cnt, num_cnt;
    scanf("%d",&case_cnt);
    while(case_cnt--){
        scanf("%d",&num_cnt);

        for ( int i = 0 ; i < num_cnt ; i++ )
            scanf("%d",&numbers[i]);
        solution(num_cnt);
    }


    return 0;
}
