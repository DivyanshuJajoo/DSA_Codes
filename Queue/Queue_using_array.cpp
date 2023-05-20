//Using circular array
#include <iostream>
using namespace std;

struct Queue{
    int size;
    int cap;
    int front;
    int*arr;
    Queue(int c){
    arr=new int[c];
    int cap=c;
    front=0;
    size=0;
    }
    void dequeue(){
        if(size==0) return;
        front=(front+1)%cap;
        size--;
    }

    void enqueue(int x){
        if(size==cap) return;
        int rear=(front+size-1)%cap;
        arr[(rear+1)%cap]=x;
        size++;
    }
    bool isFull(){
     return (size==cap);
    }

    bool isEmpty(){
        return (size==0);
    }
    int getFront(){
        if(isEmpty()) return -1;
        return front;
    }

    int getRear(){
        if(isEmpty()) return -1;
        int rear=(front+size-1)%cap;
        return rear;
    }

    

    
};


int main(){
    Queue q(100);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull();

    
}