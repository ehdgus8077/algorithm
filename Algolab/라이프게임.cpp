#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
   ifstream inStream;
   char c;
   int check[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
   int numTestCases,row,col,after,count;
   inStream.open("input.txt");
   inStream >> numTestCases;
   while (numTestCases--)
   {
        inStream >> row>> col>> after;
        char arr[row][col];
        int arr_count[row][col];
        for (int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                inStream >> c;
                arr[i][j]=c;
            }
        }
        while(after--){
            for (int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    count=0;
                    for(int k=0;k<8;k++){
                        if(i+check[k][0]>-1&&i+check[k][0]<row&&j+check[k][1]>-1&&j+check[k][1]<col){
                            if(arr[i+check[k][0]][j+check[k][1]]=='O')
                                count++;
                            }
                    }
                    arr_count[i][j]=count;
                }
            }
            for (int i=0;i<row;i++){
                for(int j=0;j<col;j++){

                    if(arr[i][j]=='O'&&arr_count[i][j]<2)
                        arr[i][j]='X';
                    else if(arr[i][j]=='X'&&arr_count[i][j]==3){
                        arr[i][j]='O';

                    }
                    else if(arr[i][j]=='O'&&arr_count[i][j]>3)
                        arr[i][j]='X';

                }
            }
        }
        count=0;

        for (int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               if(arr[i][j]=='O')
                count++;
            }

        }
        cout<<count<<endl;
        for (int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               cout<<arr[i][j];
            }
            cout<<endl;
        }
   }
   inStream.close();
   return 0;
}
