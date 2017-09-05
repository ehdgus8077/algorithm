#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,y,m,d,j=0;
    inStream >> testcase ;
    while(testcase--){
          inStream >>y>>m;
          d=1;
           cout<<y<<" "<<m<<endl;;
          d+=(y-1582)*365;
          for(int i=1;i<=m;i++){
          switch(i) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
          if(i!=m)d += 31;
           else {j=31;}
          break;
        case 4: case 6: case 9: case 11:
          if(i!=m)d += 30;
           else {j=30;}
          break;
        case 2:
          if(i!=m)d += 28;
           else {j=28;}
          break;
      }
        }
        if(m==2&&(y%400==0||(y%4==0&&y%100!=0))){j++;}
        if(m<=2){y-=1;}
        d+=(y/4-y/100+y/400)-(1582/4-1582/100+1582/400);

        int k=1;
        for(int i=0;;i++){
            for(int h=0;h<7;h++){
                if(h<(d+4)%7&&i==0){cout<<0<<" ";}
                else if(k<=j){
                    cout<<k<<" ";
                    k++;
                }
                else {cout<<0<<" ";}
            }

            cout<<endl;
            if(k>j){break;}
        }
    }
    return 0;
}
