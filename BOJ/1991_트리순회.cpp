#include <iostream>
#define Max 26
using namespace std;
/*
문제 요약 : 트리를 전위,중위,후위 순회하여 출력하기
        빈 노드는 .으로 채워짐 -> 완전한 트리임으로 배열로 구현
        **노드의 이름은 A부터 차례대로 영문자 대문자로 매겨진다.
*/
char binary_tree[Max][2];
void preorder( char c ){
    if(c!='.'){
        cout<<c;
        preorder(binary_tree[c-65][0]);
        preorder(binary_tree[c-65][1]);
    }

}
void inorder( char c ){
    if(c!='.'){
        inorder(binary_tree[c-65][0]);
        cout<<c;
        inorder(binary_tree[c-65][1]);
    }

}
void postorder( char c ){
    if(c!='.'){
        postorder(binary_tree[c-65][0]);
        postorder(binary_tree[c-65][1]);
        cout<<c;
    }

}
int main(){
   int Count;
   char temp;
   cin >> Count;

   while(Count--){
     cin >> temp;
     cin >>binary_tree[temp-65][0] >> binary_tree[temp-65][1];
   }
    preorder('A');
    cout <<"\n";
    inorder('A');
    cout <<"\n";
    postorder('A');
    cout <<"\n";
}
