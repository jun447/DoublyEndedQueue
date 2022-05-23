#include <iostream>
using namespace std;
class Deque{
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n){
        size=n;
        front=-1;
        rear=-1;
        arr=new int[n];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull())//checkig if ull or not
            return false;
        else if(front==-1){
            front=0;
            rear=0;
//           arr[front]=x;
        }else if(front==0 && rear!=size-1){//Maintaing the Cyclic Nature
            front=size-1;
        }else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull()){// checking for queue is full or not
            return false;
        }else if(front==-1){//checking if we are inserting at first time
            front=0;
            rear=0;
        }else if(rear==size-1 && front!=0){// checking if our rear is at end and front is in between
            rear=0;                        // maintaining cyclic nature
        }else{//normal case insertion
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (front==-1){// queue is empty
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        }else if(front==size-1){
            front=0;//to maintain cyclic nature
        }else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (front==-1){// queue is empty
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear){//Single element Hai
            front=-1;
            rear=-1;
        }else if(rear==0){
            rear=size-1;//to maintain cyclic nature
        }else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front==-1){
            return true;
        } else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if (front==0 && rear==size-1 ||(front!=0 && rear==(front-1)%(size-1))){// checking for queue is full or not
            return true;
        }else
            return false;

    }
    void printDequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }else{
            int i=front;
            while(i!=rear){
                cout<<arr[i]<<" ";
                i=(i+1)%size;
            }
            cout<<arr[i]<<endl;
        }
    }
};

int main() {
   Deque dq(5) ;
   dq.pushFront(12);
   dq.pushRear(14);
   dq.printDequeue();
   cout<<"Front is"<<dq.getFront()<<endl;
    cout<<"Rear is"<<dq.getRear()<<endl;
    dq.popRear();
    dq.printDequeue();
    return 0;
}
