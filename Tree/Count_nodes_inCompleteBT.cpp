//complete binary tree m tree is filled from top to bottom..
//last lvl filled from left to right.maybe bottom row puri fill nhi ho but left side se filled hoti h and right se shyd na ho...
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

// int countNode(Node *root){//O(n)
//     if(root==NULL)return 0;
//     else
//         return 1+countNode(root->left)+countNode(root->right);
// }  

//efficient m O(logn*logn)
//pahale left subtree m jaake check kiya ki sbse left side and sbse right side ki height same h. agr h toh perfect subtree h.
//toh no. of nodes 2^h-1 uss side ke. similarly right m gye or subtree m condition dali ki perfect h ya nhi. jo perfect nikle unme 
//2^h-1 wala formula or baki m naive method type return use hoga......
int countNode(Node *root){
    int lh=0,rh=0;
    Node *curr=root;
    while(curr!=NULL){
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL){
        rh++;
        curr=curr->right;
    }
    if(lh==rh){
        return pow(2,lh)-1;
    }else{
        return 1+countNode(root->left)+countNode(root->right);
    }
}  

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	
	cout<<countNode(root);
} 