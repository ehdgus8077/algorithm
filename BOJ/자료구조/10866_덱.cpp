#include <iostream>

using namespace std;

template<typename T>
struct node{
    T data;
    node<T> * next;
    node<T> * pre;
};


template<typename T>
class Deque{
private:
    node<T> * Front;
    node<T> * Back;
    int queue_size;
public:
    Deque();
    void push_Back(T value);
    void push_Front(T value);
    T pop_Back();
    T pop_Front();
    int Size();
    bool Empty();
    T d_front();
    T d_back();

};
template<typename T>
Deque<T>::Deque(){
    queue_size=0;
    Front = NULL;
    Back = NULL;
}
template<typename T>
void Deque<T>::push_Front(T value){
    node<T> * temp = new node<T>();
    temp->data = value;
    queue_size ++;
    if(Front == NULL){
        temp->next = NULL;
        temp->pre = NULL;
        Front = temp;
        Back = temp;
    }
    else{
        Front->pre = temp;
        temp->next = Front;
        temp->pre = NULL;
        Front = temp;
    }
}
template<typename T>
void Deque<T>::push_Back(T value){
    node<T> * temp = new node<T>();
    temp->data = value;
    queue_size ++;
    if(Back == NULL){
        temp->next = NULL;
        temp->pre = NULL;
        Front = temp;
        Back = temp;
    }
    else{
        Back->next = temp;
        temp->next = NULL;
        temp->pre = Back;
        Back = temp;
    }
}

template<typename T>
T Deque<T>::pop_Back(){
    if(Back == NULL){
        return -1;
    }
    else{
        queue_size--;
        T temp_num = Back->data;
        Back = Back->pre;

        if(Back == NULL)
            Front = NULL;
        else
            Back->next = NULL;
        return temp_num;
    }
}
template<typename T>
T Deque<T>:: pop_Front(){
    if(Front == NULL){
        return -1;
    }
    else{
        T temp_num = Front->data;
        Front = Front->next;

        queue_size--;
        if(Front == NULL)
            Back = NULL;
        else
            Front->pre = NULL;
        return temp_num;
    }
}
template<typename T>
int Deque<T>:: Size(){
    return queue_size;
}

template<typename T>
bool Deque<T>:: Empty(){
    return (Front == NULL)?1:0;
}

template<typename T>
T Deque<T>:: d_front(){
    if(Front == NULL)
        return -1;
    else{
        return Front->data;
    }
}
template<typename T>
T Deque<T>:: d_back(){
    if(Back == NULL)
        return -1;
    else{
        return Back->data;
    }
}
int main(){
    int command_cnt, num;
    string command;
    cin >> command_cnt;
    Deque<int> test;

    while(command_cnt--){
        cin >> command;
         if(command == "push_front"){
            cin >> num;
            test.push_Front(num);
        }
        else if(command == "push_back"){
            cin >> num;
            test.push_Back(num);
        }
        else if(command == "front")
            cout << test.d_front()<<"\n";
         else if(command == "back")
            cout << test.d_back()<<"\n";
        else if(command == "size")
            cout << test.Size()<<"\n";
        else if(command == "empty")
            cout << test.Empty()<<"\n";
        else if(command == "pop_back")
            cout << test.pop_Back()<<"\n";
        else
            cout << test.pop_Front()<<"\n";
    }

    return 0;
}
