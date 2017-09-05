#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,num,k,sum,sum2,result,n,k2;
    inStream >> testcase ;
    while(testcase--){
         inStream >> n;
         int arr[n][n];
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                inStream >> num;
                arr[i][j]=num;

             }

         }
         result=0;
          for(int i=0;i<n;i++){
              k=n-i-1;
              k2=i;
              sum=0;
              sum2=0;
             for(int j=0;j<n;j++){
                if(k==n){k=0;}
                if(k2==-1){k2=n-1;}
                sum+=arr[j][k];
                sum2+=arr[j][k2];
                k++;
                k2--;
             }

              if(sum>result||sum2>result){
                    if(sum>sum2)
                        result=sum;
                    else{
                        result=sum2;
                    }
              }

          }
          cout<<result<<endl;
        }

    return 0;
}
