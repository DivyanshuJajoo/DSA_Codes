//lowest common root of two given numbers..........
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

Node *lca(Node *root, int n1, int n2){//both n1 n2 h tree m confirm tb hee kaam krega....efficient O(n) O (h) 1 traversal
 if(root==NULL)return NULL;
    if(root->key==n1||root->key==n2)
        return root;
    
    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);
    
    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}

// bool findPath(Node *root, vector<Node *> &p, int n){//works fine for any case. O(n) but 3 traversals
//     if(root==NULL)return false;
//     p.push_back(root);
//     if(root->key==n)return true;
    
//     if(findPath(root->left,p,n)||findPath(root->right,p,n))return true;
    
//     p.pop_back();
//     return false;
// }

// Node *lca(Node *root, int n1, int n2){
//     vector <Node *> path1, path2;
//     if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
//         return NULL;
//     for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
//         if(path1[i+1]!=path2[i+1])
//             return path1[i];
//     return NULL;
// }

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
}