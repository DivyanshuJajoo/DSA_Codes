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

Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)return temp; //since head pehle se null h mtlb first char insert ho rha h toh that char will be made as head.... head= temp..
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;//because head change nhi hoga agr end se insert krte h.isliye head=insertEnd(head,10); ke acc head=head. toh no change in head
    
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
	Node *head=NULL;
	head=insertEnd(head,30);
	head=insertEnd(head,20);
	head=insertEnd(head,10);
	printlist(head);
	return 0;
} 