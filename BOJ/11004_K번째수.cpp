#include <iostream>
#include <queue>
#define Max 5000000
#define Swap(a,b) {int temp; temp=a; a=b; b=temp;}
using namespace std;
void Quick_Sort(int* arr,int l,int r,int target){

    int left=l,right=r,mid;
    int target_value=arr[target];
    while(right>left){
        if(arr[target]<=arr[left] && arr[target]>=arr[right]){
            Swap(arr[left],arr[right]);
        }

        if(arr[target]>=arr[left] &&left+1<=target){
            left++;
        }
        if(arr[target]<=arr[right]&&right-1>=target){
            right--;
        }

    }
    if(target_value!=arr[target])
        Quick_Sort(arr,target,r,target);
}
int numbers[Max];
int main(){
    int numbers_count,target_idx,num;
    priority_queue<int> pq;
    cin >> numbers_count;
    cin >> target_idx;
    for ( int i = 0 ; i< numbers_count ; i++ ){
        cin >> numbers[i];
    }
    Quick_Sort(numbers,0,numbers_count-1,target_idx-1);

    cout << numbers[target_idx-1];
    return 0;
}
