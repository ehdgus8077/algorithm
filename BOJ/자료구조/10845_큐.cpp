#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
};
class Queue{
private:
    node * Front;
    node * Back;
    int queue_size;
public:
    Queue(){
        queue_size=0;
        Front = NULL;
        Back = NULL;
    }
    void push(int num){
        node * temp = new node();
        temp->data = num;
        queue_size ++;
        if(Back == NULL){
            temp->next = NULL;
            Front = temp;
            Back = temp;
        }
        else{
            Back->next = temp;
            Back = temp;
        }
    }
    int Pop(){
        if(Back == NULL){
            return -1;
        }
        else{
            int temp_num = Front->data;
            Front = Front->next;
            queue_size--;
            if(Front == NULL)
                Back = NULL;
            return temp_num;
        }
    }
    int Size(){
        return queue_size;
    }
    bool Empty(){
        return (Front == NULL)?1:0;
    }
    int Q_front(){
        if(Front == NULL)
            return -1;
        else{
            return Front->data;
        }
    }
    int Q_back(){
        if(Back == NULL)
            return -1;
        else{
            return Back->data;
        }
    }

};
int main(){
    int command_cnt, num;
    string command;
    cin >> command_cnt;
    Queue test;

    while(command_cnt--){
        cin >> command;
         if(command == "push"){
            cin >> num;
            test.push(num);
        }
        else if(command == "front")
            cout << test.Q_front()<<"\n";
         else if(command == "back")
            cout << test.Q_back()<<"\n";
        else if(command == "size")
            cout << test.Size()<<"\n";
        else if(command == "empty")
            cout << test.Empty()<<"\n";
        else
            cout << test.Pop()<<"\n";
    }

    return 0;
}
