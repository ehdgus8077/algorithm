#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

typedef struct points{
    int x;
    int y;
    points(int r,int c):x(r),y(c){}
}point;

int arr[MAX][MAX];
int d[4][2] = { {1,0}, {0,1},{-1,0}, {0,-1} };
queue<point> q;

long long solution(int Size,int r, int c){
    long long cnt = 0;
    int row,col,ripe_cnt=0,add_cnt;
    int next_row,next_col;
    while(!q.empty()){
        add_cnt = q.size();
        ripe_cnt+=add_cnt;
        if(ripe_cnt == Size)
            return cnt;
        cnt++;

        for (int i = 0 ; i < add_cnt ; i++ ){
            row = q.front().x;
            col = q.front().y;
            q.pop();
            for (int j = 0 ; j < 4 ; j++ ){
                next_row=row+d[j][0],next_col=col+d[j][1];
                if(0<next_row&&next_row<=r && 0<next_col&&next_col<=c && arr[next_row][next_col] == 0 ){
                    arr[next_row][next_col] = 1;
                    point p(next_row,next_col);
                    q.push(p);
                }
            }

        }


    }
    return -1;
}

int main(){
    int row,col,temp_cnt=0;
    ios::sync_with_stdio(false);
    cin >>col >> row;
    for ( int i = 1 ; i <= row ; i++ ){
        for (int j = 1 ; j <=col; j ++ ){
            cin >> arr[i][j];
            if(arr[i][j]== -1){
                temp_cnt--;
            }
            else if(arr[i][j]){
                point p(i,j);
                q.push(p);
            }
        }
    }
    cout <<solution(row*col+temp_cnt,row,col);

    return 0;
}
