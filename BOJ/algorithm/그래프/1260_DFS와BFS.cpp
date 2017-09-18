// BFS는 Breadth First Search의 약자로 너비 우선이다.
// DFS는 Depth First Search의 약자로 깊이 우선이다.
// 양방향?
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define Max 1001
using namespace std;

bool DFS_visit[Max];
bool BFS_visit[Max];
void DFS(int start, vector<int>* adj ){

    stack<int> Stack;
    Stack.push(start);
    while(!Stack.empty()){
        int vertex = Stack.top();
        Stack.pop();
        if(DFS_visit[vertex])
            continue;
        cout << vertex << " ";
        DFS_visit[vertex] = true;
        sort(adj[vertex].begin(),adj[vertex].end(),greater<int>());
        for (int i = 0 ; i <adj[vertex].size(); i++){
            if(!DFS_visit[adj[vertex][i]]){
                Stack.push(adj[vertex][i]);
            }
        }

    }



}
void BFS(int start, vector<int>* adj ){

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        if (BFS_visit[vertex])
            continue;
        BFS_visit[vertex]=true;
        cout << vertex<<" ";
        sort(adj[vertex].begin(),adj[vertex].end());

        for (int i = 0 ; i < adj[vertex].size(); i ++ ){
            if(!BFS_visit[adj[vertex][i]]){
                q.push(adj[vertex][i]);
            }
        }
    }


}
int main(){
    vector<int> adj[Max];
    int vertex_count, edge_count, start_vertex, vertex, value;

    cin >> vertex_count>> edge_count>> start_vertex;
    for( int i = 0 ; i < edge_count ; i++){
        cin >> vertex >> value;
        adj[vertex].push_back(value);
        adj[value].push_back(vertex );

    }
    DFS(start_vertex, adj);
    cout <<"\n";
    BFS(start_vertex, adj);
    return 0;
}
