#include <iostream>
#include <unordered_set>
using namespace std;

bool SubArray_Sum(int arr[], int n, int sum){
    unordered_set<int>h;
    int prefix_sum=0;
    for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
        if(h.find(prefix_sum-sum)!=h.end())
        return true;
        if(prefix_sum==sum) return true;
        h.insert(prefix_sum);
    }
    return false;
}

int main(){
    int arr[]={5,3,2,-1};
    int n=4;
    int sum=4;
    if(SubArray_Sum(arr,n,sum)) cout<<"true";
    else{
        cout<<"false";
    }
return 0;
}