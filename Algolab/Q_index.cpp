#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   int test_case,thesis_count,num;
   cin >>test_case;
   while(test_case--){
        cin >> thesis_count;
        int thesis[thesis_count+1];
        thesis[0]=0;
        for(int i=1;i<=thesis_count;i++)
            cin >> thesis[i];
        sort(thesis+1,thesis+thesis_count+1);
        for(int i=thesis_count ;i >=0 ;i--){
            if(thesis[thesis_count-i+1]>=i){
                cout<<i<<"\n";
                break;
            }
        }
   }

    return 0;
}
