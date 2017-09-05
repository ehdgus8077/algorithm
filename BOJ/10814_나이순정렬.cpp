#include <iostream>
#include <utility>

using namespace std;
void merge_sort(pair<int,string>* arr, int left, int right){
    if(right!=left){
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);

        merge_sort(arr,mid+1,right);

        int left_idx=left;
        int right_idx=right;
        pair<int,string> temp[(right-left)+1];
        right=mid+1;
        int first=0;


        while(left<=mid && right<=right_idx){
            if(arr[left].first<=arr[right].first){
                temp[first].first=arr[left].first;
                temp[first++].second=arr[left++].second;

            }
            else{
                temp[first].first=arr[right].first;
                temp[first++].second=arr[right++].second;
            }
        }

        while(left<=mid){
            temp[first].first=arr[left].first;
            temp[first++].second=arr[left++].second;
        }
        while(right<=right_idx){
            temp[first].first=arr[right].first;
            temp[first++].second=arr[right++].second;
        }
        int x=0;
        for (int i=left_idx ; i<=right_idx ; i++){
            arr[i].first=temp[x].first;
            arr[i].second=temp[x++].second;
        }

    }

}

int main(){
    int number_count,f;
    string s;
    cin >> number_count;
    pair<int,string> numbers[number_count];
    for ( int i=0 ; i < number_count ;i++ ){
        cin >> f >> s;
        numbers[i]=make_pair(f,s);
    }
    merge_sort(numbers,0,number_count-1);
    for ( int i=0 ; i < number_count ;i++ ){

        cout<<numbers[i].first <<" "<< numbers[i].second<<"\n";
    }
    return 0;
}
