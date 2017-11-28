#include <cstdio>

#define MAX 100001

using namespace std;

int solution(int * arr,int Size){
    int visited[MAX]={0,};
    int temp = 1;
    int start_temp;
    int v,cycle_vertex_cnt=0;
    for (int i = 1 ; i<=Size ; i++ ){

        if(visited[i])
            continue;
        visited[i] = temp;
        start_temp = temp;
        v = i;
        while(!visited[arr[v]]){
            v = arr[v];
            visited[v] = ++temp;
        }


        if(visited[arr[v]]<start_temp){
            temp++;
            continue;
        }
        else{
            cycle_vertex_cnt += (temp-visited[arr[v]])+1;
        }
        temp++;
    }

    return Size-cycle_vertex_cnt;
}

int main(){
    int case_cnt,vertex_cnt;
    int arr[MAX];
    scanf("%d",&case_cnt);
    while(case_cnt--){
        scanf("%d",&vertex_cnt);
        for ( int i = 1 ; i <=vertex_cnt ; i ++ ){
            scanf("%d",&arr[i]);
        }
        printf("%d\n",solution(arr,vertex_cnt));
    }
    return 0;
}
