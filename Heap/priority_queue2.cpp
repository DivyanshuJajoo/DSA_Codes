//priority queue in minheap form.
#include <iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue <int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" "<<endl;;
    cout<<pq.top()<<" "<<endl;
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}
//arr[3]= 5 10 15
//priority_queue<int>pq(arr,arr+3)