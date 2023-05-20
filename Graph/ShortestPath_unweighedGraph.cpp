//O(V+E)
#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int s) 
{ 
	bool visited[V]; 
    int arr[V];
    for(int i=0;i<V;i++){
        arr[i]=INT_MAX;
    }
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 
    arr[s]=0;

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		 
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        visited[v]=true;
                arr[v]=arr[u]+1;
		        q.push(v);
		    }
		} 
	} 
    for(int x:arr){
        cout<<x<<" ";
    }
} 

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=4;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,0,2); 
	addEdge(adj,1,3);
    BFS(adj,V,0);

	

	return 0; 
} 