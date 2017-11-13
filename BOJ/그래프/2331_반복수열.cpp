/*
���� : ���� ��Ģ�� �´� ������ �߿��� �ߺ������� ������ �������� ������ ����ض�
     ������ ��Ģ�� d[n]�� d[n-1]���� �� �ڸ����� p�� ���� ���� ���� ���̴�.
    ��ųʸ�
*/
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int mul(int num, int p){
    int result=num;
    while(p>1){
        result*=num;
        p--;
    }
    return result;
}
int main(){
    int first_num, p,next_num,prenum,idx=1;
    map<int, int> check;
    cin >> first_num >> p;
    check[first_num]=idx;
    idx++;
    prenum = first_num;
    while(true){
        next_num=0;
        while(prenum){
            next_num+=mul(prenum%10,p);
            prenum/=10;
        }
        if(check.find(next_num) == check.end()){
            check[next_num]=idx;
            idx++;
        }
        else{
            cout<<check[next_num]-1;
            return 0;
        }
        prenum=next_num;
    }
    return 0;
}
