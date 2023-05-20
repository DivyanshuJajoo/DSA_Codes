#include <iostream>
#include <unordered_map>
using namespace std;

void occurence(int arr[], int n,int k){
   unordered_map<int,int> m;
    
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto e: m)
        if(e.second>n/k)
            cout<<e.first<<" ";
}

int main(){
    int arr[]={30,10,20,20,10,20,30,30};
    int n=8;
    int k=4;
    occurence(arr,n,k);
return 0;
}