#include <bits/stdc++.h>
using namespace std;

void printprevG(int arr[],int n){
    
    stack<int> s ;
    vector <int>v;
       s.push(arr[n-1]);
       v.push_back(-1);
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
        }
        
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(int x:v) cout<<x<<" ";

}

int main() 
{ 
    int arr[]={13,12,13,14,11,16};
    int n=6;
    for(int x:arr) cout<<x<<" ";
    cout<<endl;
    printprevG(arr,n);
    return 0; 
}