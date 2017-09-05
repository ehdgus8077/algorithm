#include <iostream>
#include <list>
#define Swap(a,b) {int temp; temp=a; a=b; b=temp;}
using namespace std;
// »ðÀÔ Á¤·Ä
void Insertion_Sort(int * arr, int n){
    for ( int target = 1 ; target < n ; target++){
        for( int check = target-1 ; check>=0 ; check--){
            if(arr[check+1]<arr[check]){
                Swap(arr[check+1],arr[check]);
            }
            else
                break;
        }
    }

}
void Quick_Sort(int* arr,int l,int r){

    int left=l,right=r,mid;
    mid= arr[(left+right)/2];
    while(right>=left){
        if(mid<=arr[left] && mid>=arr[right]){
            Swap(arr[left],arr[right]);
        }

        if(mid>=arr[left]){
            left++;
        }
        if(mid<=arr[right]){
            right--;
        }

    }
    if(left<r){
        Quick_Sort(arr,left,r);
    }
    if(right>l){
        Quick_Sort(arr,l,right);
    }
}

void merge_sort(int * arr, int left, int right){
    if(right!=left){
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);

        int left_idx=left;
        int right_idx=right;
        int temp[(right-left)+1];
        right=mid+1;
        int first=0;

        while(left<=mid && right<=right_idx){
            if(arr[left]<=arr[right])
                temp[first++]=arr[left++];
            else
                temp[first++]=arr[right++];
        }
        while(left<=mid)
            temp[first++]=arr[left++];
        while(right<=right_idx)
            temp[first++]=arr[right++];
        int x=0;
        for (int i=left_idx ; i<=right_idx ; i++)
            arr[i]=temp[x++];

    }

}

int main(){
    int number_count;
    cin >> number_count;
    int num[number_count];
    for(int i=0;i<number_count;i++){
        cin >> num[i];
    }
    //Quick_Sort(num,0,number_count-1);
    //Insertion_Sort(num,number_count);
    merge_sort(num,0,number_count-1);
     for(int i=0;i<number_count;i++){
        cout << num[i]<<"\n";
    }
    return 0;
}
