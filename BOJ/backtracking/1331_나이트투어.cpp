#include <iostream>
#define Chess_length 6
using namespace std;

/*
문제 요약 : 가로 길이가 2이고, 세로 길이가 3이거나 가로 길이가 3이고 세로 길이가 2인 기억자 방향으로 이동할수 있는 기사을 이동
        시킬 때 모든 좌료를 이동하되, 중복으로 이동하면 안된다. 시작점이 주어진다.
        - 이동하는 경오의 순서와 입력 받은 경로의 순서가 일치하면 valid, 아니면 Invalid를 출력

*/
typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int board[Chess_length][Chess_length];
bool knight_explore(int row , int col , int value){
    if(value==37)
        return true;
    if(0>row || row>5 || 0>col || col>5 || board[row][col]){
        return false;
    }
    else {

            board[row][col]=value;
            for( int i = 0 ; i < 8 ; i++){

                if(knight_explore(row+direction[i].x,col+direction[i].y,value+1))
                    return true;
                else if(i==7){
                    board[row][col]=0;
                    return false;
                }
            }

    }

}
int main(){

    string start_location;
    cin >> start_location;
    cout<<6-(start_location[1]-48)<<" "<<start_location[0]-65<<"\n";
    knight_explore(6-(start_location[1]-48),start_location[0]-65,1);
    for( int i = 0 ; i <6 ;i++){
        for( int j = 0 ; j<6 ;j++)
            cout <<board[i][j]<<" ";
        cout << "\n";
    }

   return 0;
}
