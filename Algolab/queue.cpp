#include <iostream>

using namespace std;
class Queue {
    private:
        int* arrayOfData;
        int front;
        int rear;
        const int sizeQueue;
    public:
        Queue(int size) : sizeQueue(size) {
            front = 0;
            rear = 0;
            arrayOfData = new int[sizeQueue];
        }
        void Enqueue (int item) {

            if (rear == sizeQueue){cout<<"FULL"<<endl;}
            else{arrayOfData[rear++] = item; }
        }
        int dequeue () {
            if (rear==0)
                return -1;
            return arrayOfData[front++];
        }
        int queue_full() {
             if (rear==sizeQueue)
                return 1;
             return 0;
        }
        int queue_empty() {
            if (front ==rear)
                return 1;
           return 0;
        }
        void print_queue() {
             int i;
             if (queue_empty())  cout << "Queue is Empty!\n";
             else {  i =front;
                    cout << "-- Print Queue --\n";
                    while (i < rear) {
                        cout <<  arrayOfData[i]<<" ";
                        i = i + 1;  }
                        cout<<endl;
            }
        }
};




int main(){
    Queue a(4);
    a.Enqueue(40); a.Enqueue(30); a.Enqueue(20); a.Enqueue(10);
    a.print_queue();
    a.dequeue ();
    a.dequeue ();
    a.print_queue();
    return 0;
}
