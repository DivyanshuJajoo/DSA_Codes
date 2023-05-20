#include <iostream>
using namespace std;
 

#define M 5
#define N 5
 struct TrieNode
{
    bool isEnd;
    TrieNode* character[2];
};

// TrieNode* getNewTrieNode()
// {
//     TrieNode* node = new Trie;
 
//     node->character[0] = node->character[1] = NULL;
//     node->isLeaf = false;
 
//     return node;
// }
 

bool insert(TrieNode*& head, bool* arr)
{

    TrieNode* curr = head;
 
    for (int i = 0; i < N; i++)
    {

        if (curr->character[arr[i]] == NULL) {
            curr->character[arr[i]] = new TrieNode();
        }
 

        curr = curr->character[arr[i]];
    }
 

    if (curr->isEnd) {
        return false;
    }
 
    
    return curr->isEnd = true;
}
 
int main()
{
    bool mat[M][N] =
    {
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 0, 0}
    };
	int count=0;
 
  
    TrieNode* head =new TrieNode();
    for (int i = 0; i < M; i++)
    {
        if (insert(head, mat[i])) {
            count++;
        }
    }

	cout<<count;
 
    return 0;
}
