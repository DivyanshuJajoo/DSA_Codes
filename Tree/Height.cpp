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

int Height(Node* root){
    if(root==NULL) return 0;
    int k=max(Height(root->left), Height(root->right))+1;
    return k;
}



int main(){
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->left->right->left=new Node(70);
    root->left->right->right=new Node(80);
    root->right->right=new Node(60);
    int h= Height(root);
    cout<<h;

return 0;
}