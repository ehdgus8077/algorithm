#include <iostream>
#include <fstream>
using namespace std;
void magic_square(int n)  {
    int square[n][n];
    square[0][(n-1)/2]=1;
    int key = 2,i = 0;
    int j = (n-1)/2;

    while(key <= n * n) {
        if(key%n==1){

            i++;
            if(i>n-1){i=0;}
        }
        else{j++;
             i--;}
        if(j>n-1){j=0;}
        if(i==-1){i=n-1;}

        square[i][j] = key;
        key++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<square[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
   ifstream inStream;
   int numTestCases,temp;
   inStream.open("input.txt");
   inStream >> numTestCases;
   while(numTestCases--)
   {
        inStream >> temp;
        magic_square(temp);

   }
   inStream.close();
   return 0;
}
