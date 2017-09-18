#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#define Max 1001
using namespace std;


/*
���� : ���� ����� ����= �׷����� ������ ���ض�
1. �� vertex�� ���� vector�� �ִ´�. ��������� �ִ´�.
2. start�� vector�� ���� �տ� �ִ� ������ �Ѵ�. verdfsŽ���� �Ͽ� �̵��� vertex�� ���� vector���� ����.
3. �׸��� ���� ��� ������ +1�Ѵ�.
4. vector�� ���� ���� 2~3������ �ݺ��Ѵ�.
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
// ������ ���� ���� ������ ��������. <- ���п���
