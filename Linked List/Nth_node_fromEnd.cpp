#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
//both sol same tc........

// int EndNode(Node* head, int n){
//     int count=1;
//     Node* curr=head;
//     while(curr!=NULL){
//         curr=curr->next;
//         count++;
//     }
//      if(count<n) return 0;
//     int temp=1;
//     curr=head;
//     while(temp!=count-n){
//         curr=curr->next;
//         temp++;
//     }
//     return (curr->data);
// }

int EndNode(Node * head,int n){
    if(head==NULL)return 0;
    Node *first=head;
    for(int i=0;i<n;i++){
        if(first==NULL)return 0;
        first=first->next;
    }
    Node *second=head;
    while(first!=NULL){
        second=second->next;
        first=first->next;
    }
    return (second->data);
}

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	printlist(head);
    cout<<endl;
    int p=EndNode(head,3);
    cout<<p;
	return 0;
} 