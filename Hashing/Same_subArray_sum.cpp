#include <iostream>
#include <unordered_map>
using namespace std;

int Same_SubArray(int arr1[], int arr2[],int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr1[i]-arr2[i];
    }
     unordered_map<int,int>h;
    int prefix_sum=0;
    int res=0;
    for(int i=0;i<n;i++){
        prefix_sum+=temp[i];
        if(prefix_sum==0) res= i+1;
        if(h.find(prefix_sum)==h.end()) h.insert({prefix_sum,i});
        if(h.find(prefix_sum)!=h.end()) res=max(res,i-h[prefix_sum]);
    }
    return res;
}

int main(){
    int arr1[]={0,1,0,1,0,0};
    int arr2[]={1,1,1,0,0,1};
    int p=Same_SubArray(arr1,arr2,6);
    cout<<p;
return 0;
}