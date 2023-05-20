#include <iostream>
#include <unordered_set>
using namespace std;

void Union(int arr1[], int arr2[], int m, int n){
    unordered_set<int>s(arr1,arr1+m);
    for(int i=0;i<n;i++) s.insert(arr2[i]);
    for(auto it=s.begin(); it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
        cout<<"No. of elements:"<<s.size();
}

int main(){
int arr1[] = {15, 17, 27, 27, 28, 15};
    int arr2[] = {16, 17, 28, 17, 31, 17};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    Union(arr1,arr2,m,n);
return 0;
}