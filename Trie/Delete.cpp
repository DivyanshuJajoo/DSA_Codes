#include <iostream>
using namespace std;

struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++)
        children[i]= NULL;

    }

    // TrieNode* getNode(void){
    //     TrieNode* pNode=new TrieNode;
    //     pNode->isEnd=false;
    //     for(int i=0;i<26;i++)
    //     pNode->children[i]=NULL;
    //     return pNode;
    // }

    void insert( TrieNode* root,string key){
         TrieNode* curr=root;
        for(int i=0;i<key.length();i++){
            int index= key[i] -'a';
            if(curr->children[index]==NULL)
            curr->children[index]=new TrieNode();
            curr=curr->children[index];

        }
        curr->isEnd=true;
    }

    bool search(TrieNode* root,string key){
        TrieNode* curr=root;
        for(int i=0;i<key.length();i++){
            int index= key[i] -'a';
            if(curr->children[index]==NULL)
            return false;
            curr=curr->children[index];

        }
        return curr->isEnd;
    }

    bool isEmpty(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i]==NULL) return true;
            return false;
        }
    }

    TrieNode* remove(TrieNode*root,string key,int depth=0){
       
        if(!root) return NULL;
        if(depth==key.size()){
        if(root->isEnd==true)
        root->isEnd=false;

        if(isEmpty(root)){
            delete(root);
            root=NULL;
        }
        return root;
        }

        int index=(int)key[depth]-(int)'a';
        root->children[index]= remove(root->children[index],key,depth+1);
        if(isEmpty(root)&& root->isEnd==false){
            delete(root);
            root=NULL;
        }
        return root;


    }
};

int main(){
    string keys[] = {"bad", "bat", "geeks", "geeks", "cat", "cut"}; 
	
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode* root=new TrieNode(); 

	
	for (int i = 0; i < n; i++) 
		root->insert( root,keys[i]); 

	
	root->search(root,"bat")? cout << "Yes\n" : 
						cout << "No\n"; 
	root->search(root,"gee")? cout << "Yes\n" : 
						cout << "No\n";

    root->remove(root,"bat",0);
	root->search(root,"bat")? cout << "Yes\n" : 
						cout << "No\n"; 

return 0;
}