#include <cstdio>
#include <stack>
#include <vector>
#define Max 1001
using namespace std;
/*
���� ���: ���� ����Ŭ�� ������ ���Ѵ�. ������ �Է¹����� ������� 1���� ������������ ������ �̾� �׷����� �����.
        �׷������� ������ ������ ������ ����, ��� ������ ������ ���ִ�.
        �� �׷����� �ΰ��� ���� ����Ŭ�� ���� ���� �ʴ´�.
1. ��������� ���� ����Ʈ�� �����. �������� ������ ����Ŭ�� ������.

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
