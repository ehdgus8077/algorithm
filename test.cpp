#include <stdio.h>


int map[510][510] = {};
int visit[510][510] = {};
int M, N;

struct saveMap{
    int x;
    int y;
};

saveMap make_saveMap(int x, int y){
    saveMap temp;
    temp.x = x; temp.y = y;
    return temp;
}

int serch(int x, int y){

    int vect_x[5] = { 0, 1, 0, -1, 0 };
    int vect_y[5] = { 0, 0, 1, 0, -1 };

    if (x == N && y == M)
        return 1;
    if (visit[y][x]) return visit[y][x];
    for (int i = 1; i <= 4; i++){
        int nextX = x + vect_x[i];
        int nextY = y + vect_y[i];
        if (map[nextY][nextX] < map[y][x] && nextX>0 && nextX <= N && nextY>0 && nextY <= M){

            visit[y][x] += serch(nextX,nextY);

        }
    }

    return visit[y][x];
}
int main(void){



    scanf("%d %d", &M, &N);

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &map[i][j]);


    printf("%d\n", serch(1,1));
    return 0;
}


