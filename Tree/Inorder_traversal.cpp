//O(n)TC O(height)AS
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=NULL;
    }

};

void Inorder(Node* root){
    if(root!=NULL){
    Inorder(root->left);
    cout<<root->key<<" ";
    Inorder(root->right);
    }
}

int main(){
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->left->right->left=new Node(60);
    root->left->right->right=new Node(70);
    root->right->right=new Node(80);
    Inorder(root);

return 0;
}