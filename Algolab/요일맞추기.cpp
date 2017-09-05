#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,y,m,d;
    inStream >> testcase ;
    while(testcase--){
          inStream >>y>>m>>d;

          d+=(y-1582)*365;
          for(int i=1;i<m;i++){
          switch(i) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
          d += 31;
          break;
        case 4: case 6: case 9: case 11:
          d += 30;
          break;
        case 2:
          d += 28;
          break;
      }
        }
        if(m<=2){y-=1;}
        d+=(y/4-y/100+y/400)-(1582/4-1582/100+1582/400);
        cout<<(d)%7<<endl;
    }
    return 0;
}
