#include <iostream>
#define N 8
// height == 8
using namespace std;

int col[N];
bool isPromising(int row){
    int temp = 1;
    for (int i = row-1 ; i>=0 ; i-- ){
        if(col[row]==col[i])
            return false;
        if(col[row]==col[i]-temp)
            return false;
        if(col[row]==col[i]+temp)
            return false;
            temp++;
    }
    return true;
}

void printNqueens(){
    for (int i = 0 ; i < N ; i++ ){
        for (int j = 0 ; j<N ; j++ ){
            if(col[i]==j)
                cout<<"1 ";
            else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
    cout <<"-----------------------------\n";
}

void nQueens(int row) {
    int i;
    if(isPromising(row)){
        if(row==N-1)
            printNqueens();
        else for(i=0;i<N;i++) {
            col[row+1]=i;
            nQueens(row+1);
        }
    }
}

int main(){
    int i;
    for(i=0;i<N;i++) {
        col[0]=i; nQueens(0);
    }

    return 0;
}
