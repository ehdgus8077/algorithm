#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#define Max 1001
using namespace std;


/*
문제 : 연결 요소의 개수= 그래프의 개수를 구해라
1. 각 vertex값 들을 vector에 넣는다. 양방향으로 넣는다.
2. start는 vector에 가장 앞에 있는 값으로 한다. verdfs탐색을 하여 이동된 vertex를 값을 vector에서 뺀다.
3. 그리고 연결 요소 개수를 +1한다.
4. vector가 빌때 까지 2~3과정을 반복한다.
*/
bool DFS_visit[Max];
bool vector_visit[Max];
vector<int> v;
void vertor_erase(int num){

    vector<int>::iterator it;
    for (it=v.begin() ; it!=v.end(); it++){
        if((*it)==num){
            v.erase(it);
            break;
        }
    }
}
void DFS(int start, vector<int>* adj ){

    stack<int> Stack;
    Stack.push(start);
    while(!Stack.empty()){
        int vertex = Stack.top();
        Stack.pop();
        if(DFS_visit[vertex])
            continue;
        vertor_erase(vertex);
        DFS_visit[vertex] = true;
        sort(adj[vertex].begin(),adj[vertex].end(),greater<int>());
        for (int i = 0 ; i <adj[vertex].size(); i++){
            if(!DFS_visit[adj[vertex][i]]){
                Stack.push(adj[vertex][i]);
            }
        }

    }

}
int main(){
    vector<int> adj[Max];
    int count=0;
    int vertex_count, edge_count, vertex, value;
    std::ios_base::sync_with_stdio(false);

    cin >> vertex_count>> edge_count;
    for( int i = 0 ; i < edge_count ; i++){
        cin >> vertex >> value;
        adj[vertex].push_back(value);
        adj[value].push_back(vertex);
        if(!vector_visit[vertex]){
            v.push_back(vertex);
            vector_visit[vertex]=true;
        }
        if(!vector_visit[value]){
            v.push_back(value);
            vector_visit[value]=true;
        }
    }
    while(!v.empty()){
        DFS(v[0], adj);
        count++;
    }
    if(vertex_count-edge_count>1)
        count+=vertex_count-edge_count-1;
    cout << count;
    return 0;
}
// 연결이 되지 않은 정점을 생각안함. <- 실패요인
