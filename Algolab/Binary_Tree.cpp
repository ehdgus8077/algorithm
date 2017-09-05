#include <iostream>
#include <algorithm>
#include<cstdlib>
#define Max 4194304
using namespace std;
int tree[Max];
int sum;
int node_count;

int tree_explore(int idx){
    if(idx*2>=node_count){
        sum+=tree[idx];
        return tree[idx];
    }
    else{
        int x=tree_explore(idx*2);
        int y=tree_explore(idx*2+1);
        if(x<y){
            sum+=tree[idx]+y-x;
            return tree[idx]+y;
        }
        else{
            sum+=tree[idx]+x-y;
            return tree[idx]+x;
        }


    }
}

int main(){
    ios::sync_with_stdio(false);
    int height,test_case;
    cin >> test_case;

    while(test_case--){
        sum=0;
        cin >> height;
        node_count= (1<<(height+1));

        tree[0]=0;
        for (int i=2;i<node_count;i++)
            cin >> tree[i];
        tree_explore(1);
        cout <<sum<<"\n";
    }
    return 0;
}
