/*
    문제 요약: 2개 이상의 섬들 사이에 다리가 있고, 각각의 다리는 중량제한이 있다. 여러 섬중 두 곳에
            공장이 있고,두 공장이 한번의 이동으로 옮길 수 있는 최대 중량을 출력해라.
            두 섬 사이의 다리가 여러 개일 수 있다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 100001
using namespace std;

vector< pair<int, int> > edge[MAX];
bool visited[MAX];
int result_max;
bool explore(int start, int End, int w){
    if(start == End){
        return true;
    }
    else{
        for ( int i = 0 ; i < edge[start].size(); i ++ ){
            if(!visited[edge[start][i].first] && edge[start][i].second>=w ){
                visited[edge[start][i].first] = 1 ;
                if(explore(edge[start][i].first,End, w))
                    return true;
            }
        }
    }
    return false;

}

int main(){

    int island_cnt, factory_cnt, first_island, second_island, w;
    int start, End;
    int weight[MAX];
    scanf("%d %d",&island_cnt, &factory_cnt);

    for (int i = 0 ; i < factory_cnt; i++){
        scanf("%d %d %d",&first_island, &second_island, &w);
        edge[first_island].push_back(make_pair(second_island,w));
        edge[second_island].push_back(make_pair(first_island,w));
        weight[i] = w;
    }
    scanf("%d %d",&start,&End);
    sort(weight, weight+factory_cnt);
    result_max = 0;

    int left=0, right=factory_cnt-1,mid;
    while(left<=right){
        visited[start] = 1;
        mid = (left+right)/2;

        if(explore( start, End , weight[mid])){
            result_max = weight[mid];
            left = mid +1;
        }
        else{
            right = mid -1 ;
        }
        for ( int i = 1 ; i <= factory_cnt ; i++)
            visited[i]= 0;

    }
    printf("%d", result_max);
    return 0;
}
