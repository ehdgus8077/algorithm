#include <cstdio>
#define MAX 2000
using namespace std;
char board[MAX][MAX];
bool visited[MAX][MAX];
bool check;
int row,col;
void solution(int x, int y ){
    if(  visited[x][y]==true || board[x][y]=='1' || y<0 ||  x<0 || x >= row || y >=col ){
    }
    else{
        visited[x][y]=true;
        if(x == row-1){
            check = true;
        }
        else{
            solution(x-1,y);
            solution(x+1,y);
            solution(x,y+1);
            solution(x,y-1);
        }
    }
}

int main(){
    scanf("%d %d",&row,&col);

    for( int i =  0 ; i < row ; i++ ){
        scanf("%s",&board[i]);
    }


    for ( int i = 0 ; i < col ; i ++ ){
        solution(0,i);
    }
    if(check){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}
