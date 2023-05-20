#include <iostream>
#include <unordered_set>
using namespace std;

bool isPair(int arr[], int n,int sum){
    unordered_set<int>h;
    for(int i=0;i<n;i++){
        if(h.find(sum-arr[i])!=h.end()) return true;
        else{
            h.insert(arr[i]);
        }
    }return false;
}

int main(){
int arr[]={1,7,9,6,2,3};
int n=6;
int sum=5;
if(isPair(arr,n,sum)){
    cout<<"true";
}
else { cout<<"false";}
return 0;
}