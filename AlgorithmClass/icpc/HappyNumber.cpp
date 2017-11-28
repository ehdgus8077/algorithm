#include <cstdio>
#define MAX 1000
using namespace std;

int main(){
    int case_cnt, n,temp;
    scanf("%d",&case_cnt);
    while(case_cnt--){
        int visited[MAX] = {0,};
        scanf("%d",&n);
        temp = n;
        n = 0;
        if(n<1000)
            visited[n] = 1;
        while(temp){
            while(temp){
                n+=(temp%10)*(temp%10);
                temp/=10;
            }
            if(n == 1 ){
                printf("%s","HAPPY\n");
                temp = 0;
            }
            else if(visited[n]){
                printf("%s","UNHAPPY\n");
                temp = 0;
            }
            else{
                visited[n] = 1;
                temp = n;
                n=0;
            }
        }

    }
    return 0;
}
