#include <iostream>
#include <fstream>
using namespace std;
int check[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int main()
{
   ifstream inStream;
   int numTestCases,num,row,col,result_row,result_col;
   bool flag;
   inStream.open("input.txt");
   inStream >> numTestCases;
   while (numTestCases--)
   {
       inStream >> row >>col;
       char arr[row][col];
       for( int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                inStream >> arr[i][j];
            }
       }
       inStream >> num;
       string str;
       while(num--){
            inStream >> str;
            for( int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(arr[i][j]==str[0]){
                        for(int k=0;k<8;k++){
                            result_row=i;
                            result_col=j;
                            flag=true;
                            for(int exp=1;exp<str.size();exp++){
                                result_row+=check[k][0];
                                result_col+=check[k][1];
                                if(result_row>-1&&result_row<row&&result_col>-1&&result_col<col){
                                    if(arr[result_row][result_col]!=str[exp]){
                                       flag=false;
                                        break;
                                    }
                                }
                                else{
                                   flag=false;
                                    break;
                                }
                            }
                            if(flag==true){
                                cout<<i+1<<" "<<j+1<<" "<<k<<endl;
                                i=row; j=col; k=8;
                            }

                        }// °á·Î Å½»ö
                    } //

                }

            }
            if(flag==false)
                cout<<-1<<endl;
        }
    }
   inStream.close();
   return 0;
}
