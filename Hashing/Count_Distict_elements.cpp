#include <iostream>
#include <unordered_set>
using namespace std;

int CountDistinct(int arr[], int n){
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    return s.size();
}

int main(){
int arr[]={10,20,30,30,50,40,20,10};
int n=8;
int p=CountDistinct(arr,8);
cout<<p;
return 0;
}