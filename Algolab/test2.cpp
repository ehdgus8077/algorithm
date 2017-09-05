#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
   int n;
   cin >>n;
   vector <long long > d(n+1);
   d[0]=1; d[1]=0;
   for (int i=2;i<=n;i++){
        d[i]=d[i-2]*3;
        for (int j = i-4;j>=0;j-=2)
            d[i]+=2*d[j];
   }
   cout<<d[n];
    return 0;
}

