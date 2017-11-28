#include <cstdio>
#define MAX 1000
using namespace std;

int temp_arr[2][2];
int order[2][2];

void rotation( int choice ){
    int temp_num;
    if(choice == 0 ){
            temp_num = order[0][0];
            order[0][0] = order[1][1];
            order[1][1] = temp_num;
    }
    else if( choice == 3 ){
            temp_num = order[1][0];
            order[1][0] = order[0][1];
            order[0][1] = temp_num;
    }
}

void solution(int n , int target, int add_row, int add_col){
    if(n==2){
        if( order[0][0] == target-1 ){
            printf("%d %d\n",1+add_row,2+add_col);
        }
        else if( order[0][1] == target-1 ){
            printf("%d %d\n",2+add_row,2+add_col);
        }
        else if( order[1][0] == target-1 ){
            printf("%d %d\n",1+add_row,1+add_col);
        }
        else{
            printf("%d %d\n",2+add_row,1+add_col);
        }

    }
    else{
        int remainder,value,temp,add;
        temp = (n*n)/4;
        remainder = target%temp;
        value = target/temp;
        if(!remainder){
            value--;
            remainder = temp;
        }
        if( order[0][0] == value ){
            rotation(order[0][0]);
            solution(n/2, remainder, add_row,add_col+n/2);
        }
        else if( order[0][1] == value ){
            rotation(order[0][1]);
            solution(n/2, remainder, add_row+n/2,add_col+n/2);
        }
        else if( order[1][0] == value ){
            rotation(order[1][0]);
            solution(n/2, remainder, add_row,add_col);
        }
        else{
            rotation(order[1][1]);
            solution(n/2, remainder, add_row+n/2 , add_col);
        }

    }

}


int main(){
    int case_cnt, n,target;
    scanf("%d",&case_cnt);

    while(case_cnt--){
        scanf("%d %d",&n,&target);
        order[0][0] = 1;
        order[0][1] = 2;
        order[1][1] = 3;
        order[1][0] = 0;
        solution(n,target,0,0);
    }
    return 0;
}
