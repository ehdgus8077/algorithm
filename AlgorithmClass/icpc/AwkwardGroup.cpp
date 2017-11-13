#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define Max 1001

using namespace std;

struct Eg {
	int u, v, w;
	bool operator<(const Eg & other) const {
		return w < other.w;
	}
};
int disjoint[Max];
int  edge_cnt[Max];
int vertex_count[Max];
int set_compare(int idx){

    if(disjoint[idx]==idx)
        return idx;
    else{
        return disjoint[idx]=set_compare(disjoint[idx]);
    }
}
Eg closeness[500500];
int main(){
    ios::sync_with_stdio(false);
    int case_count, people_count, temp,result,eg_count;
    cin >> case_count;
    while( case_count-- ){
        vector < int > check_full;
        result = 0;
        eg_count=0;
        cin >> people_count;
        if( people_count <3){
            cout <<0<<"\n";
            continue;
        }
        for( int i = 1 ; i < people_count ; i++ ){
            for( int j = i+1 ; j <= people_count ; j ++){
                cin >> temp ;
                closeness[eg_count].u = i;
                closeness[eg_count].v = j;
                closeness[eg_count++].w = temp;
            }
        }
        for (int i = 1 ;i <= people_count ;i++ ){
            disjoint[i] = i;
            vertex_count[i]=1;
             edge_cnt[i]=0;
        }


        sort(closeness, closeness+eg_count);
        for (int i = 0 ; i < eg_count ; i ++ ){
            int start = set_compare(closeness[i].u);
            int End = set_compare(closeness[i].v);
            edge_cnt[End]++;
            if (start != End){
                disjoint[start]=End;
                vertex_count[End] += vertex_count[start];
                edge_cnt[End] += edge_cnt[start];
                edge_cnt[start] = 0;
                vertex_count[start] = 0;

            }
            check_full.push_back(End);
            if (i != eg_count - 1 && closeness[i].w == closeness[i+1].w)
				continue;


            sort(check_full.begin(), check_full.end());
			int pre = -1;
			for (int i = 0; i < check_full.size(); i++) {
				if (pre == check_full[i] || disjoint[check_full[i]] != check_full[i])
					continue;
				pre = check_full[i];
                if( (vertex_count[check_full[i]]*(vertex_count[check_full[i]]-1))/2==edge_cnt[check_full[i]]){
                    result++;
            }
			}

            check_full.clear();
        }

        cout << result-1 <<"\n";
    }

    return 0;
}
