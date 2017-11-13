#include <iostream>
#include <vector>
#include <queue>
#define Max 20001
using namespace std;

/*
문제 요약: 특점 정점을 기준으로 연결된 정점은 다른 부분 집합인 그래프를 이분 그래프라고한다.
        이진 그래프의 여부를 판별해라
1. bfs로 탐색하면서 연결된 정점을 배열을 이용하여 구분해준다. ( 특정 정점이 1이면 연결된 정점은 2)
2. 만약 연결된 정점이 이미 표시가 되있을때 넣어줘야하는 값과 같은면 계속 진핼하고 아니면 종료 후 NO출력
3. 모든 정점이 연결되지 않은 경우도 NO출력?,이 두가지 경우가 아니면 YES 출력
*/
int binary_graph[Max];
vector<int> adj[Max];
bool BFS(int start){

    queue<int> q;
    q.push(start);
    binary_graph[start]=1;
    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        for (int i = 0 ; i < adj[vertex].size(); i ++ ){
            if(!binary_graph[adj[vertex][i]]){
                binary_graph[adj[vertex][i]]=3-binary_graph[vertex];
                q.push(adj[vertex][i]);
            }
            else if(binary_graph[vertex] == binary_graph[adj[vertex][i]]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int test_case;
    cin >> test_case;
    while(test_case--){
        int vertex_count, edge_count, vertex, value;
        //std::ios_base::sync_with_stdio(false);

        cin >> vertex_count>> edge_count;
        for ( int i = 1 ; i <= vertex_count ;i++){
            adj[i].clear();
            binary_graph[i]=0;
        }

        for( int i = 0 ; i < edge_count ; i++){
            cin >> vertex >> value;
            adj[vertex].push_back(value);
            adj[value].push_back(vertex);

        }
        bool flag = true;
        for ( int i = 1 ; i  <= vertex_count ; i ++ ){
            if(!binary_graph[i]){
                if(!BFS(i)){
                    flag = false;
                    break;
                }
            }
        }
       if(flag){
            cout <<"YES"<<"\n";
       }
       else{
            cout <<"NO"<<"\n";
       }

    }
    return 0;
}
