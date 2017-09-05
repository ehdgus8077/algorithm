#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int comX(pair<int,string> &fir,pair<int,string> &sec){
    if(fir.first==sec.first)
        return fir.second <sec.second;
    return fir.first>sec.first;

}
int main(){
    vector< pair<int,string> > grade[101][101];
    vector< pair<int,string> >::iterator it;
    int korean , english , math , student_count;
    string name;
    cin >>student_count;

    for ( int i=0; i<student_count ; i++){
        cin >> name;
        cin >> korean >> english >> math;
        pair<int,string> p(math,name);
        grade[korean][english].push_back(p);
    }

    for (int ko = 100 ; ko>=0;ko--){
        for(int eng=0; eng<101 ; eng++){
            if(grade[ko][eng].size()){
                sort(grade[ko][eng].begin(),grade[ko][eng].end(),comX);
                for (it=grade[ko][eng].begin();it!=grade[ko][eng].end();it++)
                    cout<<(*it).second<<"\n";
            }
        }
    }

    return 0;
}
