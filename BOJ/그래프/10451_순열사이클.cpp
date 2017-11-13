#include <cstdio>
#include <stack>
#include <vector>
#define Max 1001
using namespace std;
/*
문제 요약: 순열 사이클의 개수를 구한다. 순열을 입력받으면 순서대로 1부터 순열개수까지 간선을 이어 그래프를 만든다.
        그래프에는 정점과 간선의 개수가 같고, 모든 정점은 연결이 되있다.
        한 그래프에 두개의 순열 사이클이 존재 하지 않는다.
1. 양방향으로 인접 리스트를 만든다. 연결요소의 개수가 사이클의 개수다.

*/

vector<int> adj[Max];
int DFS_visit[Max];
void DFS(int start){

    stack<int> Stack;
    Stack.push(start);
    while(!Stack.empty()){
        int vertex = Stack.top();
        Stack.pop();
        if(DFS_visit[vertex])
            continue;
        DFS_visit[vertex] = true;
        for (int i = 0 ; i <adj[vertex].size(); i++){
            if(!DFS_visit[adj[vertex][i]]){
                Stack.push(adj[vertex][i]);
            }
        }

    }

}
int main(){
    int test_count,edge_count,value,count;
    scanf("%d",&test_count);
    while(test_count--){
        count = 0;
        scanf("%d",&edge_count);

        for( int i = 1 ; i <= edge_count ; i++){
            DFS_visit[i]=0;
            adj[i].clear();
            scanf("%d",&value);
            adj[i].push_back(value);
            adj[value].push_back(i);
        }
    for (int i = 1 ; i <= edge_count ;i++) {
        if(!DFS_visit[i]){
            DFS(i);
            count++;
        }
    }
    printf("%d\n",count);

    }

    return 0;
}
