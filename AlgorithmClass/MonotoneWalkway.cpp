#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
//11067
using namespace std;

bool o_compare(pair<int, pair<int,int> >& lhs,pair<int, pair<int,int> >& rhs){
    return lhs.second.second < rhs.second.second;
}
bool compare(pair<int, pair<int,int> >& lhs, pair<int, pair<int,int> >& rhs){
    if(lhs.first==rhs.first)
        return lhs.second.first < rhs.second.first;
    else
        return lhs.first < rhs.first;
}

void explore(vector< pair<int, pair<int,int> > > & locations){
   int preY=0,pre,next,start=0,o=0;
   int Size = locations.size();
   for ( int i = 0 ; i <Size; i++){
    start=i;
    while(i<Size && locations[i].first==locations[i+1].first){
        i++;
    }

    if(preY>=locations[i].second.first){
        reverse(locations.begin()+start, locations.begin()+i+1);
    }
    else if(preY<=locations[start].second.first){}
    else{
        int j;
        for ( j = start ; j <=i ; j++){
            if(locations[j].second.first>=preY){
                if(locations[j].second.first-preY>preY-locations[j-1].second.first)
                    j--;
                 break;
                }
            }
            pre=j-1;
            next=j+1;
            while(pre>=start && next<=i){
                locations[j].second.second =o++;
                if(locations[j].second.first-locations[pre].second.first<locations[next].second.first-locations[j].second.first){
                    j=pre;
                    pre--;
                }
                else{
                    j=next;
                    next++;
                }

            }
            if(pre>=start){
               while(pre>=start){
                locations[pre].second.second =o++;
                pre--;
               }
            }
            else{
                while(next<=i){
                locations[next].second.second =o++;
               }
               next++;
            }
            sort(locations.begin()+start, locations.begin()+i+1,o_compare);
        }

    preY = locations[i].second.first;
   }

}

int main(){
    ios::sync_with_stdio(false);
    int case_count,x,y,location_count,answer_count,idx,Max;
    cin >> case_count;

    while(case_count--){
        Max=0;
        vector< pair<int, pair<int,int> > > locations;
        vector<int> location_answers;
        cin >> location_count;
            int xxx=location_count;
        while(location_count--){
            cin >> x >> y;
            locations.push_back(make_pair(x,make_pair(y,0)));
        }
        locations.push_back(make_pair(100001,make_pair(0,0)));
        cin >> answer_count;
        sort(locations.begin(), locations.end(), compare);
        explore(locations);
        for ( int i = 0 ; i  < answer_count ; i++){
            cin >> idx;
            cout << locations[idx-1].first<< " "<< locations[idx-1].second.first<<"\n";
        }


    }
    return 0;
}
