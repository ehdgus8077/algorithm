#include <cstdio>
#include <stack>
#define MAX 51
using namespace std;

int Map[MAX][MAX];
int visited[MAX][MAX];
int d[8][2] = { {1,0}, {0,1},{-1,0}, {0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

typedef struct points{
    int x;
    int y;
    points(int r,int c):x(r),y(c){}
}point;

void dfs(int i,int j,int w, int h){
    int next_row,next_col;
    stack<point> s;
    point p(i,j);
    s.push(p);
    visited[i][j] =1;
    while(!s.empty()){
        i = s.top().x;
        j = s.top().y;
        s.pop();
        for (int k = 0 ; k < 8 ; k++ ){
            next_row=i+d[k][0],next_col=j+d[k][1];
            if(0<next_row&&next_row<=h && 0<next_col&&next_col<=w && Map[next_row][next_col] == 1 && visited[next_row][next_col]==0){
                point p(next_row,next_col);
                s.push(p);
                visited[next_row][next_col] = 1;
            }
        }
    }
}
int solution(int w, int h){
    int cnt = 0;
    for (int i = 1 ; i <= h ; i++ ){
        for(int j = 1 ; j <=w ; j++ ){
            if(Map[i][j]==1 && visited[i][j]!=1){
                cnt++;
                dfs(i,j,w,h);
            }
        }
    }
    return cnt;
}
int main(){
    int w,h;
    scanf("%d %d",&w,&h);
    while(w+h!=0){
        for ( int i = 1 ; i <= h ; i++ ){
            for (int j = 1 ; j <=w ; j++ ){
                scanf("%d",&Map[i][j]);
                visited[i][j] =0;
            }
        }
        printf("%d\n",solution(w,h));
        scanf("%d %d",&w,&h);
    }

    return 0;
}
