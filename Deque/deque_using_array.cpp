#include <iostream>
using namespace std;

struct Deque{
    int * arr;
    int size;
    int cap;
    int front;
    int rear;
    Deque(int c){
        arr=new int[c];
        cap=c;
        size=0;
        front=0;
        rear=(front+size-1)%cap;
    }

    void insertFront(int x){
        front=(front-1+cap)%cap;
        arr[front]=x;
        size++;
    }
    void insertRear(int x){
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
    }

    void deleteRear(){
        rear=(rear-1+cap)%cap;
       size--;
    }
    void deleteFront(){
        front=(front+1)%cap;
    }

    int getFront(){
        return arr[front];
    }
    int getRear(){
        return arr[rear];
    }
    //complete.....
};

int main(){


return 0;
}