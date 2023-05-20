#include <iostream>
#include <unordered_map>
using namespace std;

int Longest_0and1(int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]==0) arr[i]=-1;
    }
    unordered_map<int,int>h;
    int res=0;
    int prefix_sum=0;
    for(int i=0;i<n;i++){
        prefix_sum+= arr[i];
        if(prefix_sum==0) res= i+1;
        if(h.find(prefix_sum)==h.end()) h.insert({prefix_sum,i});
        if(h.find(prefix_sum)!=h.end()) res=max(res,i-h[arr[i]]);
    } return res;
}

int main(){
int arr[]={0,1,0,0,1,1,0};
int n=7;
int p=Longest_0and1(arr,n);
cout<<p;
return 0;
}