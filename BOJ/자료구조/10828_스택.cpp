#include <iostream>
#define MAX 100001

using namespace std;

class Stack{
private:
    int *Stack_arr;
    int top;
public:
    Stack(int Size){
        Stack_arr = new int[Size];
        top = -1;
    }
    void push(int num){
        top ++;
        Stack_arr[top] = num;
    }
    bool Empty(){
        return (top==-1)?1:0;
    }
    int pop(){
        if( Empty() )
            return -1;
        else
            return Stack_arr[top--];
    }
    int Top(){
        if( Empty() )
            return -1;
        else
            return Stack_arr[top];
    }
    int Size(){
        return top+1;
    }

};

int main(){
    int stack_size, num;
    string command;
    cin >> stack_size;
    Stack test = Stack(stack_size);
    while(stack_size--){
        cin >> command;
        if(command == "push"){
            cin >> num;
            test.push(num);
        }
        else if(command == "top")
            cout << test.Top()<<"\n";
        else if(command == "size")
            cout << test.Size()<<"\n";
        else if(command == "empty")
            cout << test.Empty()<<"\n";
        else
            cout << test.pop()<<"\n";
    }

    return 0;
}
