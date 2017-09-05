#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,num,result;
    string a;
    inStream >> testcase ;
    while(testcase--){
       inStream >> num;
       inStream >> a;

       for(int i=0;i<a.size();i++){
        if((int)a[i]>=65&&(int)a[i]<=90){
            result=a[i]+num;

          if(result>90){result-=26;}
          cout<<(char)result;
        }
        else if((int)a[i]>=97&&(int)a[i]<=122){
             result=a[i]+num;

          if(result>122){result-=26;}
          cout<<(char)result;

        }
        else {cout<<a[i];

        }
       }
       cout<<endl;
        }

    return 0;
}
