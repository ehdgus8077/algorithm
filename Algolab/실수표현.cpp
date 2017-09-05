#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    bool count,exp;
    int testcase,num,dot,ec,op,k;
    string a;
    inStream >> testcase ;
    while(testcase--){
        dot=0; ec=0; op=0; k=0;
       count=false; exp=false;
       inStream >> a;

        for(int i=0;i<a.size();i++){
            if((48<=(int)a[i]&&(int)a[i]<=57)&&ec==0&&dot==0){
                count=true;

            }
            else if(a[i]=='.'&&ec==0){
                dot++;

                if(dot>1){ cout<<0<<endl; k++; break;}
            }
            else if((48<=(int)a[i]&&(int)a[i]<=57)&&ec==0&&dot==1){
                count=true;
            }
            else if((a[i]=='e'||a[i]=='E')){
                ec++;
                if(ec>1){ cout<<0<<endl; k++; break;}
            }
            else if(ec>0&&(a[i]=='+'||a[i]=='-')){
                op++;
                if(op>1){ cout<<0<<endl; k++; break;}
            }
            else if(ec>0&&(48<=(int)a[i]&&(int)a[i]<=57)){
                exp=true;
            }
            else { cout<<0<<endl; k++; break;}

        }
            if(k>0){continue;}
            if(count==false||(exp==false&&ec!=0)||(ec==0&&dot==0)){
                 cout<<0<<endl; }
            else {cout<<1<<endl;}
            }


    return 0;
}
