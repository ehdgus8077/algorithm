#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 676
using namespace std;

int Map[MAX][MAX];
int visited[MAX][MAX];
int d[4][2] = { {1,0}, {0,1},{-1,0}, {0,-1}};

typedef struct points{
    int x;
    int y;
    points(int r,int c):x(r),y(c){}
}point;

int dfs(int i,int j,int w){
    int next_row,next_col;
    stack<point> s;
    point p(i,j);
    s.push(p);
    visited[i][j] =1;
    int cnt  = 1;
    while(!s.empty()){
        i = s.top().x;
        j = s.top().y;
        s.pop();
        for (int k = 0 ; k < 4 ; k++ ){
            next_row=i+d[k][0],next_col=j+d[k][1];
            if(0<next_row&&next_row<=w && 0<next_col&&next_col<=w && Map[next_row][next_col] == 1 && visited[next_row][next_col]==0){
                point p(next_row,next_col);
                s.push(p);
                visited[next_row][next_col] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

void solution(int w){
    int cnt = 0;
    int result[MAX];
    for (int i = 1 ; i <= w ; i++ ){
        for(int j = 1 ; j <=w ; j++ ){
            if(Map[i][j]==1 && visited[i][j]!=1){
                result[cnt]=dfs(i,j,w);
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    sort(result,result+cnt);
    for ( int i = 0 ; i<cnt ; i++ ){
        cout <<result[i]<<"\n";
    }
}
int main(){
    int w;
    string temp_str;
    cin >> w;
    for ( int i = 1 ; i <= w ; i++ ){
        cin >>temp_str;
        for (int j = 1 ; j <=w ; j++ ){
            Map[i][j] = temp_str[j-1]-'0';
        }
    }
    solution(w);
    return 0;
}
