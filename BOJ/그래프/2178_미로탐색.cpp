#include <iostream>
#include <stack>
#include <utility>
#define MAX 102
#define d_MAX 2000000000
using namespace std;

char miro[MAX][MAX];
int tance[MAX][MAX];
int d[4][3] = { {1,0}, {0,1},{-1,0}, {0,-1}};

//shortest path
int solution(int target_row, int target_col ){
    int row,col,temp;
    stack< pair<int, int> > vertexs;
    vertexs.push( make_pair(1,1) );
    tance[1][1] = 1;

    while(!vertexs.empty() ){
        row = vertexs.top().first;
        col = vertexs.top().second;
        vertexs.pop();

        for ( int i = 0 ; i < 4 ; i ++ ){
            if(miro[row+d[i][0]][col+d[i][1]] =='1' && tance[row][col]+1< tance[row+d[i][0]][col+d[i][1]] ){
                tance[row+d[i][0]][col+d[i][1]] = tance[row][col]+1;
                vertexs.push( make_pair(row+d[i][0],col+d[i][1]));
            }
        }
    }

    return tance[target_row][target_col];

}

int main(){
    int row,col;
    cin >> row >> col;
    string t;
    for (int i = 1 ; i <= row ; i++ ){
        cin >> t;
        for (int j = 0 ; j < col ; j++ ){
            miro[i][j+1] = t[j];
            tance[i][j+1] = d_MAX;
        }
    }

    cout << solution(row , col);
    return 0;
}
