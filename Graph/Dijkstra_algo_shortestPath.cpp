//Shortest path to each vertex from given vertex
//O((V+E)logV)
#include <iostream>
#include <vector>
#include <limits.h>
#define V 4
using namespace std;

vector<int> djikstra(int graph[V][V],int src){
    vector<int> distance(V,INT_MAX);
    distance[src]=0;
	bool arr[V]; 

	for (int count = 0; count < V ; count++) 
	{ 
		int u = -1; 

		for(int i=0;i<V;i++)
		    if(!arr[i]&&(u==-1||distance[i]<distance[u]))
		        u=i;
		arr[u] = true; 
        
    

    		for (int v = 0; v < V; v++) 

			if (graph[u][v]!=0 && arr[v] == false) 
				distance[v] = min(distance[v],distance[u]+graph[u][v]);
}
return distance;

}

int main(){
    int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: djikstra(graph,0)){
	    cout<<x<<" ";
	} 

return 0;
}