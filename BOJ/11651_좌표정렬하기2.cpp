#include <iostream>
#include <utility>
#define Swap(a,b) {int temp; temp=a; a=b; b=temp;}
using namespace std;
void Quick_Sort(pair<int,int>* arr,int l,int r){

    int left=l,right=r,mid;
    mid= arr[(left+right)/2].second;
    int mid_first=arr[(left+right)/2].first;
    while(right>=left){
        if(mid<=arr[left].second && mid>=arr[right].second){
            if(arr[left].second!=arr[right].second ){
                Swap(arr[left].second,arr[right].second);
                Swap(arr[left].first,arr[right].first);
            }
            else if(arr[left].first>arr[right].first){
                 Swap(arr[left].second,arr[right].second);
                Swap(arr[left].first,arr[right].first);

            }
        }

        if(mid>arr[left].second ||(mid==arr[left].second &&( mid_first>=arr[left].first))){
            left++;
        }
        if(mid<arr[right].second ||(mid==arr[right].second &&( mid_first<=arr[right].first))){
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

using namespace std;
int main(){
    int number_count,f,s;
    cin >> number_count;
    pair<int,int> numbers[number_count];
    for ( int i=0 ; i < number_count ;i++ ){
        cin >> f >> s;
        numbers[i]=make_pair(f,s);
    }
    Quick_Sort(numbers,0,number_count-1);
    for ( int i=0 ; i < number_count ;i++ ){

        cout<<numbers[i].first <<" "<< numbers[i].second<<"\n";
    }
    return 0;
}
