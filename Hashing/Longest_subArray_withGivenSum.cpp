#include <iostream>
#include <unordered_map>
using namespace std;

int LongSubArray_Sum(int arr[], int n, int sum){
    unordered_map<int,int>h;
    int prefix_sum=0;
    int res=0;
    for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
        if(prefix_sum==sum) res=i+1;
        if(h.find(prefix_sum)==h.end()) h.insert({prefix_sum,i});
        if(h.find(prefix_sum-sum)!=h.end()) res=max(res,i-h[prefix_sum-sum]);
    }
    return res;
}

int main(){
    int arr[]={5,8,-4,-4,9,-2,-2};
    int n=7;
    int sum=0;
    int p=LongSubArray_Sum(arr,n,sum);
    cout<<p;

return 0;
}