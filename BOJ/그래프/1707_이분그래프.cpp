#include <iostream>
#include <vector>
#include <queue>
#define Max 20001
using namespace std;

/*
���� ���: Ư�� ������ �������� ����� ������ �ٸ� �κ� ������ �׷����� �̺� �׷�������Ѵ�.
        ���� �׷����� ���θ� �Ǻ��ض�
1. bfs�� Ž���ϸ鼭 ����� ������ �迭�� �̿��Ͽ� �������ش�. ( Ư�� ������ 1�̸� ����� ������ 2)
2. ���� ����� ������ �̹� ǥ�ð� �������� �־�����ϴ� ���� ������ ��� �����ϰ� �ƴϸ� ���� �� NO���
3. ��� ������ ������� ���� ��쵵 NO���?,�� �ΰ��� ��찡 �ƴϸ� YES ���
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
