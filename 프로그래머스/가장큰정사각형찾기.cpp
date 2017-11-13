#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int solution(int i, int j,vector< vector<char> >& board ){
    int row_cnt = board.size();
	int col_cnt = board[0].size();

    if(board[i][j] == 'X')
        return 0;
    else{
        int row = i+1,col = j+1;
        while(row<row_cnt && col<col_cnt){
            for ( int k = 0 ; k <= col-j ; k++ ){
                if(board[i+k][col]=='X'||board[row][j+k] =='X'){
                    cout <<i<<" "<<j<<" "<<k<<"---"<<row-i<<"\n";
                    return (row-i)*(row-i);

                }
            }
            row++;
            col++;
        }
        return (row-i)*(row-i);

    }
}

int findLargestSquare(vector< vector<char> > board)
{
	int answer = 0;
	int row_cnt = board.size();
	int col_cnt = board[0].size();
	int temp;
    for( int i  = 0 ;  i < row_cnt ; i ++  ){
        for( int j = 0 ; j < col_cnt ; j++ ){
            temp = solution(i,j,board);
            if(temp>answer){
                answer = temp;
            }
        }
    }
	return answer;
}
int main()
{

	vector< vector<char> > board{
				{'X','O','O','O','X'},
				{'X','O','O','O','O'},
				{'X','X','O','O','O'},
				{'X','X','O','O','O'},
				{'X','X','X','X','X'}};


	//아래는 테스트 출력을 위한 코드입니다.
	cout<<findLargestSquare(board);
}
