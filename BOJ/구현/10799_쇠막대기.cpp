#include <cstdio>
#include <vector>
#define MAX 5001
using namespace std;

void solution( int n , int k){
    int number[MAX];
    if(n == 1){
        printf("%d",1);

    }
    else{
        for ( int i = 1 ;  i< n ; i ++ ){
            number[i] = i+1;
        }
        number[n] = 1;
        int cnt=1, pre_num = n,key = 1;
        while(1){
            if(cnt%k==0){
                printf("%d, ",key);
                if(pre_num == number[key]){
                    break;
                }
                number[pre_num] = number[key];
            }
            else{
                pre_num = key;
            }
            key = number[key];
            cnt++;
        }
        printf("%d",number[key]);
    }
}

int main(){


    int n,k;
    scanf("%d %d",&n,&k);

    printf("%c",'<');
    solution(n,k);
    printf("%c",'>');
    return 0;
}
