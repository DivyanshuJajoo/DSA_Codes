#include<bits/stdc++.h> 
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};



struct Deque 
{
    Node* front;
    Node* rear;
    int Size;
  

    Deque()
    {
        front = rear = NULL;
        Size = 0;
    }
void insertFront(int x) {
    Node *node = new Node(x);
    if (front == NULL) {
      
        front = rear = node;
    } else {
      
        node->next = front;
        front->prev = node;
              front = node;
    }
     Size++;
}
void insertEnd(int x) {
    Node *node = new Node(x);
    if (rear == NULL) {
              front = rear = node;
    } else {
               node->prev = rear;
        rear->next = node;
        
        rear = node;
    }
   
    Size++;
}
void deleteFront() {
    if (front == NULL) {
        
        return;
    }
    if (front == rear) {
       
        front = rear = NULL;
    } else {
       
        Node *temp = front;
        front = front->next;
        front->prev = NULL;
        
        delete(temp);
    }
   
    Size--;
}
void deleteEnd() {
    if (rear == NULL) {
       
        return;
    }
    if (front == rear) {
      
        front = rear = NULL;
    } else {
       
        Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
      
        delete(temp);
    }
  
    Size--;
}
int getFront() {
    if (front != NULL) {
        return front->data;
    }
    return -1;
}
int getEnd() {
    if (rear != NULL) {
        return rear->data;
    }
    return -1;
}
int size() {
    return Size;
}
bool isEmpty() {
    if (front == NULL) {
        return true;
    }
    return false;
}
void erase() {
    rear = NULL;
 
    while (front != NULL) {
        Node *temp = front;
       
        front->prev = NULL;
        front = front->next;
      
        delete(temp);
    }
   
    Size = 0;
}
};
int main() {
   Deque d;
    d.insertFront(5);               
    d.insertEnd(10);                  
    d.insertEnd(11);                
    d.insertFront(19);              
    cout<<d.getFront()<<endl;
    cout<<d.getEnd()<<endl;
    d.deleteEnd();                   
    cout<<d.getEnd()<<endl;
    d.deleteFront();                 
    cout<<d.getFront()<<endl;     
    cout<<d.size()<<endl;
    if (d.isEmpty()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    d.erase();
    if (d.isEmpty()) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    
    return 0;
}