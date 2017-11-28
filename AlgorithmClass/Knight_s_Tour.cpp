#include <iostream>
#define MAXSIZE 8
#define MARK 1
#define UNMARK 0

using namespace std;

typedef struct Point {
    int x, y;
} point;

point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knightTour(int m, int n, point pos, int counter) {
    int i;
    point next;
    if (counter == m * n)
        return 1;
    for (i=0; i<8; i++) {
        next.x= pos.x+ direction[i].x;
        next.y= pos.y+ direction[i].y;
        if ( next.x>= 0 && next.x< n && next.y>= 0 && next.y< m && board[next.y][next.x] != MARK ) {
                board[next.y][next.x] = MARK;
                path[next.y][next.x] = counter+1;
                if ( knightTour(m, n, next, counter+1) )
                    return 1;
                board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}

int main(){
    point startp;
    startp.x = 0;
    startp.y = 0;
    if(knightTour(MAXSIZE,MAXSIZE,startp,1)){
        board[startp.y][startp.x] = MARK;
        path[startp.y][startp.x] = 1;
        for ( int i = 0 ; i < MAXSIZE ; i++ ){
            for (int j  = 0 ; j < MAXSIZE ; j ++ ){
                cout << path[i][j]<<" ";
            }
            cout << "\n";
        }
    }
    return 0;
}
