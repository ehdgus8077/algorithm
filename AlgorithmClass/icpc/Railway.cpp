#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    // 입력 및 정의
    ios::sync_with_stdio(false);
    int people_count,Start,End,rail_length,end_location,count_,max_count;
    int test_case;
    cin >> test_case;
    while(test_case--){
        vector< pair<int,int> > rail;
        priority_queue< int > q;
        max_count=0;
        cin >>people_count;

        for ( int i=0; i<people_count ; i++){
            cin >> Start >> End;
            if(End>Start)
                rail.push_back(make_pair(End,Start));
            else
                rail.push_back(make_pair(Start,End));
        }
        cin >>rail_length;
        sort(rail.begin(),rail.end());

        for( int i = 0 ; i < people_count ; i++ ){
            if( rail[i].first-rail[i].second <=rail_length)
                q.push(-rail[i].second);
            while(!q.empty()){
                if( rail[i].first+q.top() >rail_length){
                    q.pop();
                }
                else
                    break;
            }
            if(max_count<q.size()){
                max_count=q.size();
            }
        }
       cout << max_count<<"\n";
    }
    return 0;
}
