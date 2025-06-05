#include<iostream>

using namespace std;

class Queue{
    int* arr;

    int capacity;
    int currsize;

    int f,r;
public:
    Queue(int size){
        capacity = size;
        arr = new int[size];
        currsize = 0;
        f = 0;
        r = -1;
    }
    void push(int data){
        if(currsize == capacity){
            cout << "Queue is Overflow!" << endl;
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currsize++;
    }
    void pop(){
        if(empty()){
            cout << "Queue is Underflow!" << endl;
            return;
        }
        f = (f + 1) % capacity;
        currsize--;
    }
    int front(){
        if(empty()){
            cout << "Queue is Underflow!" << endl;
            return -1;
        }
        return arr[f];
    }
    bool empty(){
        return currsize == 0;
    }
};

int main(){
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    
    q.push(5);
    cout << q.front() << endl;
    return 0;
}