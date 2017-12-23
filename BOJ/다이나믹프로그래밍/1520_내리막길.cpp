#include <cstdio>
#include<memory.h>
#define MAX 501
using namespace std;
// Ư¡: roop�� parallel �� ���� �׷��� �̴�.
// Ʋ�� ���� : �ȵǴ� ��θ� ǥ�����ְ� �� ����� �Ѱ��� �̵��ϸ� ���� Ž���� �ʿ����

int visited[MAX][MAX];
int num[MAX][MAX];
int direction[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int dfs(int x, int y, int row ,int col){
    int next_x,next_y;

    if( x== row && y == col){
        return 1;
    }
    if( !visited[x][y] ){
        return visited[x][y];
    }
    else if( visited[x][y]!=-1 ){
        return visited[x][y];
    }
    visited[x][y] = 0;
    for ( int i = 0 ; i < 4 ; i++){
        next_x = x+direction[i][0];
        next_y = y+direction[i][1];

        if( (num[next_x][next_y] < num[x][y] &&0<  next_x&&next_x<= row && 0< next_y&& next_y<= col) ){

            visited[x][y] += dfs(next_x,next_y,row,col);

        }
    }
    return visited[x][y];
}

int main(){
    int row,col;
    memset(visited, -1, sizeof(visited));
    scanf("%d %d",&row,&col);
    for ( int i = 1 ; i <= row ; i++ ){
        for ( int j = 1; j<=col ; j++ ){
            scanf("%d",&num[i][j]);
        }
    }
    if( row == 1 && col == 1){
        printf("1");
        return 0;
    }
    visited[row][col] = 1;
    dfs(1,1,row,col);
    printf("%d\n",visited[1][1]);

    return 0;
}
