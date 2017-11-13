#include <iostream>
#include <queue>
#define Max 1000
using namespace std;

int main(){
    int case_count,num_count,w,l,sum,result;
    cin >> case_count;
    int numbers[Max];
    while(case_count--){
        sum=0;
        result=0;
        queue<int> q;
        cin >> num_count >> w >> l ;
        for( int i =0 ; i<num_count ; i++){
            cin >> numbers[i];
        }

        for ( int i = 0 ; i < num_count ; i++){
            result++;
            if(q.size()==w){
                sum-=q.front();
                q.pop();
            }
            if(sum+numbers[i]<=l){
                sum+=numbers[i];
                q.push(numbers[i]);
            }
            else{
                q.push(0);
                i--;
            }
        }

        cout<<result+w<<"\n";
    }
    return 0;
}
