#include <cstdio>
#include <algorithm>
#define MAX 200000

using namespace std;
int X_location[MAX];

int solution(int start , int End, int h_cnt, int target_c){
    int mid , c_cnt, start_value,result=0;
    while(start<=End){
        mid = (start+End)/2;
        c_cnt = 1;
        start_value = X_location[0];
        for ( int i = 1 ; i < h_cnt ; i ++ ){
            if(X_location[i]-start_value>=mid){
                c_cnt++;
                start_value = X_location[i];
            }
        }
        if(c_cnt<target_c)
            End = mid - 1;
        else{
            result = mid;
            start = mid + 1;
        }
    }
    return result;
}


int main(){
    int h_cnt,c;
    scanf("%d %d",&h_cnt,&c);
    for ( int i = 0 ; i < h_cnt ; i++)
        scanf("%d",&X_location[i]);
    sort(X_location, X_location + h_cnt);
    printf("%d",solution(1,X_location[h_cnt-1]-X_location[0],h_cnt,c));

    return 0;
}
