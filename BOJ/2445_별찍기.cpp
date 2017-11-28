#include<iostream>
#define MAX 300

using namespace std;

char arr[MAX];
int main() {
	int n;
	cin >> n ;
	for ( int i = 1; i <=n ; i++ ){
        arr[i] = '*';
        arr[n*2+1-i] = '*';
        for (int j = 1 ; j <=n*2 ; j++){
            if(arr[j]=='*')
                cout<< "*";
            else
                cout<<" ";
        }
        cout<<"\n";
	}
	for ( int i = n; i >=2 ; i-- ){
        arr[i] = ' ';
        arr[n*2+1-i] = ' ';
        for (int j = 1 ; j <=n*2 ; j++){
            if(arr[j]=='*')
                cout<< "*";
            else
                cout<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
